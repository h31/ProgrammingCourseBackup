#include "receivers.h"

#include <iostream>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool RSSReceiver::parseUrl(const string url, string& address, int& port, string& path)
{
    const int prefixLen = strlen("http://");
    int slashPos = url.find('/', prefixLen);

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

    struct sockaddr_in peer;
    char buf[128];
    string address;
    string path;
    int port;
    string request;
    string responce;

    parseUrl(url, address, port, path);

    peer.sin_family = AF_INET;
    peer.sin_port = htons(80);
    peer.sin_addr.s_addr = inet_addr(address.c_str() );

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {} //TODO: Log

    sockStatus = connect(sock, (struct sockaddr *)&peer, sizeof(peer) );
    if (sockStatus) {} //TODO: Log

    request = "GET " + path + " HTTP/1.1\r\n";
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
    if (responce.substr(0, prefixLen) != "HTTP/1.1")
    {
        record.code = INVALID_DATA;
        return record;
    }

    switch (responce[prefixLen+1]) {
    case '1':
        record.code = NOT_IMPLEMENTED;
        return record;
    case '2':
        record.code = OK;
        break;
    case '3':
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

void RSSReceiver::operator()(queue<RSSRecord>* pipe, condition_variable* cond, mutex* m)
{
    string url = "http://127.0.0.1/";
    const string responce = downloadSource(url);
    HTTPRecord record = parseHTTP(responce);
    cout << record.data;
}

