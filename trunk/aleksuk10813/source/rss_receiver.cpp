#include "receivers.h"

#include <iostream>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include "pugixml.hpp"

using namespace std;

bool RSSReceiver::parseUrl(const string url, string& address, int& port, string& path)
{
    const int prefixLen = strlen("http://");
    int slashPos = url.find('/', prefixLen); // ищём разделитель между адресом и путём
    // TODO: если нет слэша в конце

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

    parseUrl(url, address, port, path);

    gaiStatus = getaddrinfo(address.c_str(), NULL, NULL, &gaiResult);

    peer.sin_family = AF_INET;
    peer.sin_port = htons(80);
    sockaddr_ipv4 = (struct sockaddr_in *) gaiResult->ai_addr;
    peer.sin_addr = sockaddr_ipv4->sin_addr;
    //peer.sin_addr.s_addr = inet_addr(address.c_str() );

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {} //TODO: Log

    sockStatus = connect(sock, (struct sockaddr *)&peer, sizeof(peer) );
    if (sockStatus) {} //TODO: Log

    // Пример:
    // GET / HTTP/1.1
    // Host: ya.ru

    request = "GET " + path + " HTTP/1.0\r\n";
    request += "Host: " + address + "\r\n";
    request += "\r\n";
    sendStatus = send(sock, request.c_str(), request.length(), 0);
    if ( sendStatus <= 0 ) {}  //TODO: Log

    do {
        recvStatus = recv(sock, buf, sizeof(buf), 0);
        responce.append(buf, recvStatus);
    } while (recvStatus > 0);
    //if ( currStatus <= 0 ) {}  //TODO: Log
    return responce;
}

HTTPRecord RSSReceiver::parseHTTP(const string responce)
{
    const int prefixLen = strlen("HTTP/1.1");
    HTTPRecord record;

    // Пример:
    // HTTP/1.1 200 Ok

    if (responce.substr(0, prefixLen) != "HTTP/1.1")
    {
        record.code = INVALID_DATA;
        return record;
    }

    // Проверяем код состояния
    switch (responce[prefixLen+1]) {
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
    record.data = responce.substr(dataStart);
    return record;

}

void RSSReceiver::parseFeed(vector<InRecord>& itemArray)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("test_xml.txt");
    pugi::xml_node itemRoot = doc.child("rss").child("channel");
    for (pugi::xml_node item = itemRoot.child("item"); item; item = itemRoot.next_sibling("item") )
    {
        InRecord record;
        record.title = item.child_value("title");
        record.data = item.child_value("description");
        record.link = item.child_value("link");
        itemArray.push_back(record);
        // TODO: остальное
    }
}

void RSSReceiver::operator()(queue<InRecord>* pipe, condition_variable* cond, mutex* m)
{
    vector<InRecord> itemArray;
    //string url = "http://news.yandex.ru/hardware.rss";
    //const string responce = downloadSource(url);
    //HTTPRecord record = parseHTTP(responce);
    parseFeed(itemArray);
    cout << "record.data";
}

