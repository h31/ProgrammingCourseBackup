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
#include <unistd.h>
#endif

#include "shared.h"
#include <string.h>
#include "remote_control.h"
#include "3rdparty/pugixml.hpp"
#include <sstream>

const char* RemoteControl::unitName = "HTTPServer";

void RemoteControl::operator()(set<string>* sources, mutex* m)
{
    windowsSocketStart();
    establishServerSocket();

    while (1)
    {
        establishClientSocket();
        request = receiveRequest();

        method = getMethodOfRequest(request);
        path = getRequestedPath(request);

        if (getTypeOfRequest() == GET_SOURCES)
        {
            unique_lock<mutex> lk(*m);
                string xml = generateXMLForSources(*sources);
            lk.unlock();
            sendResponce(xml);
        }
        else if (getTypeOfRequest() == SET_SOURCES)
        {
            payload = getPayloadOfPOST(request);
            unique_lock<mutex> lk(*m);
                importSources(payload, sources);
            sendResponce("");
        }
        else if (getTypeOfRequest() == IMPORT_OPML)
        {
            payload = getPayloadOfPOST(request);
            unique_lock<mutex> lk(*m);
                importOPML(payload, sources);
            lk.unlock();
        }
        else if (getTypeOfRequest() == EXPORT_OPML)
        {
            // TODO
        }
        // TODO: остальные варианты
        else
            throw RemoteControlException(ERROR, "Invalid URL");

        close(clientSock);
    }
}

void RemoteControl::establishServerSocket()
{
    runSocket();
    runBind();
    runListen();
}

string RemoteControl::getMethodOfRequest(string request)
{
    string method = request.substr(0, request.find(" ") );
    if (method != "GET" && method != "POST")
        throw RemoteControlException(ERROR, "Bad request");
    return method;
}

string RemoteControl::getRequestedPath(string request)
{
    // Пример:
    // GET /path HTTP/1.1

    int pathEnd = request.find("HTTP") - 1;
    int pathStart = request.find(" /") + strlen(" /");
    string path(request, pathStart, pathEnd - pathStart);
    return path; // TODO: упростить
}

string RemoteControl::getPayloadOfPOST(string request)
{
    int dataStart = request.find("\r\n\r\n") + strlen("\r\n\r\n");
    if (dataStart == -1)
        throw RemoteControlException(ERROR, "invalid POST request");
    return request.substr(dataStart);
}

TypeOfRequest RemoteControl::getTypeOfRequest()
{
    if (method == "GET" && path == "sources")
    {
        return GET_SOURCES;
    }
    else if (method == "POST" && path == "sources")
    {
        return SET_SOURCES;
    }

    else if (method == "GET" && path == "opml")
    {
        return EXPORT_OPML;
    }
    else if (method == "POST" && path == "opml")
    {
        return IMPORT_OPML;
    }
    else throw RemoteControlException(ERROR, "Unknown type of request");
}

string RemoteControl::generateXMLForSources(set<string> sources)
{
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("data");

    for (set<string>::iterator it = sources.begin(); it != sources.end(); it++)
    {
        pugi::xml_node source = root.append_child("source");

        pugi::xml_attribute addressAttribute = source.append_attribute("address");
        addressAttribute.set_name("address");
        addressAttribute.set_value(it->c_str() );

        pugi::xml_attribute protocolAttribute = source.append_attribute("protocol");
        protocolAttribute.set_name("protocol");
        protocolAttribute.set_value("rss"); // TODO
    }

    stringstream payload;
    doc.save(payload);
    return payload.str();
}

void RemoteControl::importOPML(string opml, set<string> *sources)
{
//    pugi::xml_document doc;
//    stringstream stream;
//    doc.load(stream);
}

void RemoteControl::importSources(string requestPayload, set<string> *sources)
{
    sources->clear();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(requestPayload.c_str(), requestPayload.length());

    if (result.status != pugi::status_ok)
        throw RemoteControlException(ERROR, "Bad XML syntax");

    pugi::xml_node root = doc.child("data");
    if (root == NULL)
        throw RSSReceiverException(ERROR, "No rss or channel nodes");

    if (root.child("source") == NULL)
        throw RSSReceiverException(ERROR, "No source nodes");
    for (pugi::xml_node item = root.child("source"); item; item = item.next_sibling("item") )
    {
        pugi::xml_attribute attr = item.attribute("address");
        if (attr == NULL)
            throw RSSReceiverException(ERROR, "No address attribute");
        sources->insert(attr.value() );
    }
}

void RemoteControl::sendResponce(string payload)
{
    string responce = "";
    int sendStatus;

    responce  = "HTTP/1.1 200 OK\r\n";
    responce += "Content-Type: text/plain; charset=utf-8\r\n";
    responce += "Connection: close\r\n";
    responce += "\r\n";
    responce += payload;

    sendStatus = send(clientSock, responce.c_str(), responce.length(), 0);
    if ( sendStatus <= 0 )
    {
        throw RemoteControlException(ERROR, "send error");
    }
}

void RemoteControl::establishClientSocket()
{
    clientSock = accept(serverSock, NULL, NULL);
    if (clientSock < 0)
    {
        throw RemoteControlException(ERROR, "client socket error");
    }
}

string RemoteControl::receiveRequest()
{
    string request = "";
    int recvStatus;
    char buf[1280];

    do {
        recvStatus = recv(clientSock, buf, sizeof(buf), 0);
        request.append(buf, recvStatus);
        // TODO: проверка на зависание
    } while (recvStatus == sizeof(buf) );
    return request;
}

void RemoteControl::runSocket()
{
    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0)
        throw RemoteControlException(ERROR, "server socket error");
}

void RemoteControl::runBind()
{
    struct sockaddr_in local;
    int bindStatus;

    local.sin_family = AF_INET;
    local.sin_port = htons(9863);
    //local.sin_addr.s_addr = inet_addr("127.0.0.1"); - не работает, TODO
    local.sin_addr.s_addr = htonl( INADDR_ANY );

    bindStatus = ::bind(serverSock, (struct sockaddr *)&local, sizeof(local) );
    if (bindStatus < 0)
    {
        throw RemoteControlException(ERROR, "connect error");
    }
}

void RemoteControl::runListen()
{
    int listenStatus;

    listenStatus = listen(serverSock, 2);
    if (listenStatus != 0)
        throw RemoteControlException(ERROR, "listen error");
}

void RemoteControl::windowsSocketStart()
{
#ifdef __MINGW32__
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0)
    {
        log(ERROR, unit_name, "WSAStartup error");
        throw HTTPServerException;
    }
#endif
}
