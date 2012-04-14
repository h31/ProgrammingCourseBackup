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

#include "3rdparty/pugixml.hpp"
#include "receivers.h"
#include "shared.h"

using namespace std;

const char* RSSReceiver::unitName = "HTTPClient";

void RSSReceiver::operator()(queue<InRecord>* pipe, set<string>* sources, condition_variable* cond, mutex* m)
{
    for(set<string>::const_iterator it = sources->begin(); it != sources->end(); it++)
    {
        const string rawResponce = downloadSource(*it);
        // TODO: Парсер HTTP должен сам обрабатывать ошибки
        HTTPRecord ParsedResponce = parseHTTP(rawResponce);
        vector<InRecord> receivedItems;
        parseFeed(ParsedResponce.data, receivedItems);
        // TODO: не использовать передачу через аргументы

        unique_lock<mutex> lk(*m);
        // lk.try_lock();

        for (vector<InRecord>::iterator it = receivedItems.begin();
             it != receivedItems.end();
             ++it)
            pipe->push(*it);

        lk.unlock();
        cond->notify_one();
    }
}

string RSSReceiver::downloadSource(const string url)
{
    string responce;
    const char* unit_name = "HTTPClient";
    PartsOfURL partsOfURL;

    partsOfURL = parseUrl(url);
    sock = connect_helper(partsOfURL);
    sendRequest(partsOfURL);
    responce = receive_helper(sock);

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
        // TODO: объединить с другой проверкой
        log(ERROR, "HTTPClient", "Not an HTTP responce");
        throw HTTPClientException();
    }

    // Проверяем код состояния
    record.statusCode = getStatusCode(responce[ prefixLen + strlen("/1.1 ") ] );
    if (record.statusCode == OK)
    {
        int dataStart = responce.find("\r\n\r\n", prefixLen) + strlen("\r\n\r\n");
        if (dataStart == -1)
        {
            log(ERROR, "HTTPClient", "invalid HTTP responce");
            throw HTTPClientException();
        }
        record.data = responce.substr(dataStart);
    }
    else
    {
        log(ERROR, "HTTPClient", "bad HTTP status code");
        throw HTTPClientException();
    }

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

enum ReceiverStatusCode RSSReceiver::getStatusCode(const char responce)
{
    // Проверяем код состояния
    switch (responce) {
    case '1':
        return NOT_IMPLEMENTED;
    case '2':
        return OK;
    case '3': // перенаправление
        return NOT_IMPLEMENTED;
    case '4':
        return CLIENT_ERROR;
    case '5':
        return SERVER_ERROR;
    default:
        return INVALID_DATA;
    }
}

void RSSReceiver::sendRequest(PartsOfURL partsOfURL)
{
    // Пример:
    // GET / HTTP/1.1
    // Host: ya.ru

    string request;
    request = "GET " + partsOfURL.path + " HTTP/1.0\r\n";
    request += "Host: " + partsOfURL.address + "\r\n";
    request += "\r\n";

    send_helper(sock, request);
}

PartsOfURL RSSReceiver::parseUrl(const string url)
{
    PartsOfURL result;
    const int prefixLen = strlen("http://");

    if (url.substr(0, prefixLen) != "http://")
    {
        // TODO: Exception
    }


    int slashPos = url.find('/', prefixLen); // ищём разделитель между адресом и путём
    if (slashPos == -1)
    {
        log(ERROR, "HTTPClient", "invalid URL");
        throw HTTPClientException();
    }

    result.address = url.substr(prefixLen, slashPos-prefixLen);
    result.port = 80; //TODO
    result.path = url.substr(slashPos);

    return result;
}

void RSSReceiver::windowsSocketStart()
{
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
}
