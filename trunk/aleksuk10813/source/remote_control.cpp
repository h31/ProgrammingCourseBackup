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
#include "pugixml.hpp"
#include <sstream>

const char* RemoteControl::unitName = "HTTPClient";

void RemoteControl::operator()(set<string>* sources, mutex* m)
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

    establishServerSocket();

    while (1)
    {
        establishClientSocket();
        request = receiveRequest();

        path = getRequestedPath(request);

        if (path == "sources")
        {
            unique_lock<mutex> lk(*m);
                string xml = generateXML(*sources);
            lk.unlock();
            sendResponce(xml);
        }
        // TODO: остальные варианты
        else
            throw HTTPServerException();

        close(clientSock);
    }
}

void RemoteControl::establishServerSocket()
{
    runSocket();
    runBind();
    runListen();
}

string RemoteControl::getRequestedPath(string request)
{
    // Пример:
    // GET / HTTP/1.1

    if (request.substr(0, strlen("GET") ) != "GET")
    {
        log(ERROR, unitName, "Bad request");
        throw HTTPServerException();
    }

    int pathEnd = request.find("HTTP") - 2;
    string path(request, strlen("GET /"), pathEnd - strlen("GET "));
    return path; // TODO: упростить
}

string RemoteControl::generateXML(set<string> sources)
{
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("data");

    for (set<string>::iterator it = sources.begin(); it != sources.end(); it++)
    {
        pugi::xml_node source = root.append_child("source");
        pugi::xml_attribute attr = source.append_attribute("address");
        attr.set_name("address");
        attr.set_value(it->c_str() );
    }

    stringstream payload;
    doc.save(payload);
    return payload.str();
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
        log(ERROR, unitName, "send error");
        throw HTTPServerException();
    }
}

void RemoteControl::establishClientSocket()
{
    clientSock = accept(serverSock, NULL, NULL);
    if (clientSock < 0)
    {
        log(ERROR, unitName, "client socket error");
        throw HTTPServerException();
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
    {
        log(ERROR, unitName, "server socket error");
        throw HTTPServerException();
    }
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
        log(ERROR, unitName, "connect error");
        throw HTTPServerException();
    }
}

void RemoteControl::runListen()
{
    int listenStatus;

    listenStatus = listen(serverSock, 2);
    if (listenStatus != 0)
    {
        log(ERROR, unitName, "listen error");
        throw HTTPServerException();
    }
}
