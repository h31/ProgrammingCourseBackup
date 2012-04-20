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
const int RSSReceiver::updateIntervalInSeconds = 1; // TODO: сделать динамическим

void RSSReceiver::operator()(queue<InRecord>* pipe, list<string>* sources, condition_variable* cond, mutex* m)
{
    while (1)
    {
        for(list<string>::const_iterator it = sources->begin(); it != sources->end(); it++)
        {
            downloadSource(*it);
            ParsedResponce = parseHTTP(rawResponce);
            receivedItems = parseFeed(ParsedResponce.data);
            leaveOnlyNewItems(*it);

            unique_lock<mutex> lk(*m);
            // lk.try_lock();

            for (list<InRecord>::iterator it = receivedItems.begin();
                 it != receivedItems.end();
                 ++it)
                pipe->push(*it);

            lk.unlock();
            cond->notify_one();
        }
        this_thread::sleep_for(chrono::seconds(updateIntervalInSeconds));
    }
}

void RSSReceiver::downloadSource(const string url)
{
    partsOfURL = parseUrl(url);
    sock = connect_helper(partsOfURL);
    sendRequest(partsOfURL);
    rawResponce = receive_helper(sock);
}

HTTPRecord RSSReceiver::parseHTTP(const string responce)
{
    const int prefixLen = strlen("HTTP");
    HTTPRecord record;

    // Пример:
    // HTTP/1.1 200 Ok

    if (responce.substr(0, prefixLen) != "HTTP")
        // TODO: объединить с другой проверкой
        throw RSSReceiverException(ERROR, "Not an HTTP responce");

    // Проверяем код состояния
    record.statusCode = getStatusCode(responce[ prefixLen + strlen("/1.1 ") ] );
    if (record.statusCode == OK)
    {
        int dataStart = responce.find("\r\n\r\n", prefixLen) + strlen("\r\n\r\n");
        if (dataStart == -1)
            throw RSSReceiverException(ERROR, "invalid HTTP responce");
        record.data = responce.substr(dataStart);
    }
    else
        throw RSSReceiverException(ERROR, "bad HTTP status code");
    return record;
}

list<InRecord> RSSReceiver::parseFeed(const string rssContent)
{
    list<InRecord> itemList;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(rssContent.c_str(), rssContent.length());
    if (result.status != pugi::status_ok)
        throw RSSReceiverException(ERROR, "Bad XML syntax");
    pugi::xml_node itemRoot = doc.child("rss").child("channel");
    if (itemRoot == NULL)
        throw RSSReceiverException(ERROR, "No rss or channel nodes");
    if (itemRoot.child("item") == NULL)
        throw RSSReceiverException(ERROR, "No item node");
    for (pugi::xml_node item = itemRoot.child("item"); item; item = item.next_sibling("item") )
    {
        InRecord record;
        record.title = item.child_value("title");
        record.data = item.child_value("description");
        record.link = item.child_value("link");
        record.guid = item.child_value("guid");
        itemList.push_back(record);
        // TODO: остальное
    }
    return itemList;
}

void RSSReceiver::leaveOnlyNewItems(const string sourceAddress)
{
    set<string> sourceGuids = guids[sourceAddress];
    list<InRecord> onlyNewItems;
    for (list<InRecord>::iterator it = receivedItems.begin(); it != receivedItems.end(); ++it)
    {
        if (sourceGuids.find(it->guid) == sourceGuids.end() ) // новая запись
        {
            sourceGuids.insert(it->guid);
            onlyNewItems.push_back(*it);
        }
        else // такая запись уже была
        {

        }
    }

    guids[sourceAddress] = sourceGuids;
    receivedItems = onlyNewItems;
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
    request  = "GET " + partsOfURL.path + " HTTP/1.0\r\n";
    request += "Host: " + partsOfURL.address + "\r\n";
    request += "Connection: close\r\n";
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
        throw RSSReceiverException(ERROR, "invalid URL");
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
