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

#include "shared.h"
#include <string.h>
#include "remote_control.h"
#include "pugixml.hpp"
#include <sstream>

void RemoteControl::operator()(set<string>& sources, condition_variable& cond, mutex& m)
{
    //unique_lock<mutex> outLock(*m);
    //cond->wait(outLock);

    int self_sock;
    int sock;
    int bindStatus;
    int sendStatus;
    int recvStatus;
    int listenStatus;

    int pathEnd;

    struct sockaddr_in local;
    //        struct addrinfo *gaiResult;
    char buf[1280];
    //        string address;
    //        string path;
    //        int port;
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
        throw HTTPServerException;
    }
#endif

    local.sin_family = AF_INET;
    local.sin_port = htons(9867);
    //local.sin_addr.s_addr = inet_addr("127.0.0.1");
    local.sin_addr.s_addr = htonl( INADDR_ANY );

    self_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (self_sock < 0)
    {
        log(ERROR, unit_name, "socket error");
        throw HTTPServerException();
    }

    bindStatus = ::bind(self_sock, (struct sockaddr *)&local, sizeof(local) );
    if (bindStatus < 0)
    {
        log(ERROR, unit_name, "connect error");
        throw HTTPServerException();
    }
    listenStatus = listen(self_sock, 2);
    //while (1)
    //{
        sock = accept(self_sock, NULL, NULL);
        // TODO: Log

        request = "";
        //do {
        recvStatus = recv(sock, buf, sizeof(buf), 0);
        request.append(buf, recvStatus);
        // TODO: проверка на зависание
        //} while (recvStatus > 0);

        // Пример:
        // GET / HTTP/1.1
        // Host: ya.ru

        // Пример:
        // GET / HTTP/1.1
        if (request.substr(0, strlen("GET") ) != "GET")
        {
            log(ERROR, unit_name, "Bad request");
            throw HTTPServerException();
        }

        pathEnd = request.find("HTTP") - 2;
        string path(request, strlen("GET /"), pathEnd - strlen("GET "));

        if (path != "sources")
            throw HTTPServerException();
        // TODO

        pugi::xml_document doc;
        for (set<string>::iterator it = sources.begin(); it != sources.end(); it++)
        {
            pugi::xml_node source = doc.append_child("source");
            pugi::xml_attribute attr = source.append_attribute("address");
            attr.set_name("address");
            attr.set_value(it->c_str() );
        }
//
//        pugi::xml_node sender = receiver.append_child("sender");

        stringstream payload;
        doc.save(payload);

        responce  = "HTTP/1.1 200 OK\r\n";
        responce += "Content-Type: text/plain; charset=utf-8\r\n";
        responce += "Connection: close\r\n";
        responce += "\r\n";
        responce += payload.str();

        sendStatus = send(sock, responce.c_str(), responce.length(), 0);
        if ( sendStatus <= 0 )
        {
            log(ERROR, unit_name, "send error");
            throw HTTPServerException();
        }

        close(sock);
    //}
}
