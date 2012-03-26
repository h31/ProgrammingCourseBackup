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
#include <string>
#include <string.h>
#include "remote_control.h"

void RemoteControl::operator()(condition_variable* cond, mutex* m)
{
    while (1)
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
        local.sin_port = htons(9873);
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

        pathEnd = request.find("HTTP") - 1;
        string path(request, strlen("GET /"), pathEnd - strlen("GET "));

        if (path != "SOURCES")
            throw HTTPServerException();
            // TODO


        // Пример:
        // HTTP/1.1 200 Ok
//        responce += "\r\n";
//        sendStatus = send(sock, request.c_str(), request.length(), 0);
//        if ( sendStatus <= 0 )
//        {
//            log(ERROR, unit_name, "send error");
//            throw HTTPServerException();
//        }

    }
}
