#ifdef __MINGW32__
#define _WIN32_WINNT 0x0601
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#include <string>
#include <stdlib.h>
#include <string.h>
#include <mutex>
#include <thread>
#include <iostream>

#include "pugixml.hpp"
#include "receivers.h"
#include "shared.h"

using namespace std;

bool RSSReceiver::parseUrl(const string url, string& address, int& port, string& path)
{
    const int prefixLen = strlen("http://");
    int slashPos = url.find('/', prefixLen); // ищём разделитель между адресом и путём
    if (slashPos == -1)
    {
        log(ERROR, "HTTPClient", "invalid URL");
        throw HTTPClientException();
    }

    if (url.substr(0, prefixLen) != "http://")
        return false;

    address = url.substr(prefixLen, slashPos-prefixLen);
    port = 80; //TODO
    path = url.substr(slashPos);

    return true;
}

string RSSReceiver::downloadSource(const string url)
{

    int sock;
    int sockStatus;
    int sendStatus;
    int recvStatus;
    int gaiStatus;

    struct sockaddr_in peer;
    struct addrinfo *gaiResult;
    struct sockaddr_in *sockaddr_ipv4;
    char buf[1280];
    string address;
    string path;
    int port;
    string request;
    string responce;
    const char* unit_name = "HTTPClient";

#ifdef __MINGW32__
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0)
    {
        log(ERROR, unit_name, "WSAStartup error");
        throw HTTPClientException;
    }
#endif

    parseUrl(url, address, port, path);

    gaiStatus = getaddrinfo(address.c_str(), NULL, NULL, &gaiResult);
    if (gaiStatus != 0)
    {
        log(ERROR, unit_name, "getaddrinfo error");
        throw HTTPClientException();
    }

    peer.sin_family = gaiResult->ai_family;
    peer.sin_port = htons(80);
    sockaddr_ipv4 = (struct sockaddr_in *) gaiResult->ai_addr;
    peer.sin_addr = sockaddr_ipv4->sin_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        log(ERROR, unit_name, "socket error");
        throw HTTPClientException();
    }

    sockStatus = connect(sock, (struct sockaddr *)&peer, sizeof(peer) );
    if (sockStatus)
    {
        log(ERROR, unit_name, "connect error");
        throw HTTPClientException();
    }

    // Пример:
    // GET / HTTP/1.1
    // Host: ya.ru

    request = "GET " + path + " HTTP/1.0\r\n";
    request += "Host: " + address + "\r\n";
    request += "\r\n";
    sendStatus = send(sock, request.c_str(), request.length(), 0);
    if ( sendStatus <= 0 )
    {
        log(ERROR, unit_name, "send error");
        throw HTTPClientException();
    }

    do {
        recvStatus = recv(sock, buf, sizeof(buf), 0);
        responce.append(buf, recvStatus);
        // TODO: проверка на зависание
    } while (recvStatus > 0);

    delete gaiResult;
    // delete sockaddr_ipv4;

    return responce;
}

HTTPRecord RSSReceiver::parseHTTP(const string responce)
{
    const int prefixLen = strlen("HTTP");
    HTTPRecord record;

    // Пример:
    // HTTP/1.1 200 Ok

    if (responce.substr(0, prefixLen) != "HTTP")
    {
        record.code = INVALID_DATA;
        return record;
    }

    // Проверяем код состояния
    switch (responce[prefixLen+strlen("/1.1 ")]) {
    case '1':
        record.code = NOT_IMPLEMENTED;
        return record;
    case '2':
        record.code = OK;
        break;
    case '3': // перенаправление
        record.code = NOT_IMPLEMENTED;
        return record;
    case '4':
        record.code = CLIENT_ERROR;
        return record;
    case '5':
        record.code = SERVER_ERROR;
        return record;
    default:
        record.code = INVALID_DATA;
        return record;
    }

    int dataStart = responce.find("\r\n\r\n", prefixLen) + strlen("\r\n\r\n");
    if (dataStart == -1)
    {
        log(ERROR, "HTTPClient", "invalid HTTP responce");
        throw HTTPClientException();
    }
    record.data = responce.substr(dataStart);
    return record;

}

void RSSReceiver::parseFeed(const string rssContent, vector<InRecord>& itemArray)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(rssContent.c_str(), rssContent.length());
    if (result.status != pugi::status_ok)
    {
        log(ERROR, "XMLParser", "Bad XML syntax");
        throw XMLParserException();
    }
    pugi::xml_node itemRoot = doc.child("rss").child("channel");
    if (itemRoot == NULL)
    {
        log(ERROR, "XMLParser", "No rss or channel nodes");
        throw XMLParserException();
    }
    if (itemRoot.child("item") == NULL)
    {
        log(ERROR, "XMLParser", "No item node");
        throw XMLParserException();
    }
    for (pugi::xml_node item = itemRoot.child("item"); item; item = item.next_sibling("item") )
    {
        InRecord record;
        record.title = item.child_value("title");
        record.data = item.child_value("description");
        record.link = item.child_value("link");
        itemArray.push_back(record);
        // TODO: остальное
    }
}

void RSSReceiver::operator()(queue<InRecord>& pipe, set<string>& sources, condition_variable& cond, mutex& m)
{
    for(set<string>::const_iterator it = sources.begin(); it != sources.end(); it++)
    {
        const string responce = downloadSource(*it);
        HTTPRecord record = parseHTTP(responce);
        if (record.code != OK)
        {
            log(ERROR, "HTTPClient", "bad HTTP status code");
            throw HTTPClientException();
        }
        vector<InRecord> itemArray;
        parseFeed(record.data, itemArray);

        unique_lock<mutex> lk(m);
        // lk.try_lock();

        for (vector<InRecord>::iterator it = itemArray.begin(); it!=itemArray.end(); ++it)
            pipe.push(*it);

        lk.unlock();
        cond.notify_one();
    }
}
