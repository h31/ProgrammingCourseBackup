#include "shared.h"
#include <iostream>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifdef __MINGW32__
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#endif

RSSReceiverException::RSSReceiverException(Importance importance, string message)
{
    log(importance, message);
}

RemoteControlException::RemoteControlException(Importance importance, string message)
{
    log(importance, message);
}

string enum2string(enum Importance in)
{
    switch (in) {
    case ERROR:
        return "ERROR";
    case INFO:
        return "INFO";
    case DEBUG:
        return "DEBUG";
    }
}

void log(enum Importance importance, string message)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%d:%.2d:%.2d %s: %s\n",
           timeinfo->tm_hour,
           timeinfo->tm_min,
           timeinfo->tm_sec,
           enum2string(importance).c_str(),
           message.c_str() );
}

string receive_helper(int clientSocket)
{
    string request = "";
    int recvStatus;
    char buf[1280];

    do {
        recvStatus = recv(clientSocket, buf, sizeof(buf), 0);
        request.append(buf, recvStatus);
        // TODO: проверка на зависание
    } while (recvStatus > 0);
    // delete buf; // TODO
    //recvStatus == sizeof(buf)  Если значение меньше sizeof(buf), то все данные уже получены, иначе нужно продолжать
    return request;
}

void send_helper(int clientSocket, string data)
{
    int sendStatus;

    sendStatus = send(clientSocket, data.c_str(), data.length(), 0);
    if ( sendStatus <= 0 )
        throw RemoteControlException(ERROR, "send error");
}

int connect_helper(PartsOfURL url)
{
    int sockStatus;
    int gaiStatus;
    int clientSocket;
    struct sockaddr_in peer;
    struct addrinfo* gaiResult;
    struct sockaddr_in* sockaddr_ipv4;
    extern int errno;

    gaiStatus = getaddrinfo(url.address.c_str(), NULL, NULL, &gaiResult);
    if (gaiStatus != 0)
        throw RSSReceiverException(ERROR, "getaddrinfo error");

    do
    {
        peer.sin_family = gaiResult->ai_family;
        peer.sin_port = htons(url.port);
        sockaddr_ipv4 = reinterpret_cast<struct sockaddr_in *>(gaiResult->ai_addr);
        peer.sin_addr = sockaddr_ipv4->sin_addr;

        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket < 0)
            throw RSSReceiverException(ERROR, "socket error");

        sockStatus = connect(clientSocket, (struct sockaddr *)&peer, sizeof(peer) );
        if (sockStatus == 0)
        {
            break;
        }
        char* t = strerror(errno);
        gaiResult = gaiResult->ai_next;
        delete[] sockaddr_ipv4; // TODO
    } while (gaiResult->ai_next != NULL);
    if (sockStatus)
    {
        throw RSSReceiverException(ERROR, string("connect error:") + string(strerror(errno)));
    }

    delete[] gaiResult;

    return clientSocket;
}
