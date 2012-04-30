#include "shared.h"
#include "config_handler.h"

#include "3rdparty/pugixml.hpp"
#include <iostream>
#include <sstream>
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

ConfigHandlerException::ConfigHandlerException(Importance importance, string message)
{
    log(importance, message);
}

SMTPSenderException::SMTPSenderException(Importance importance, string message)
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
        // delete[] sockaddr_ipv4; // TODO
    } while (gaiResult->ai_next != NULL);
    if (sockStatus)
    {
        throw RSSReceiverException(ERROR, string("connect error:") + string(strerror(errno)));
    }

    delete[] gaiResult;

    return clientSocket;
}

string generateXMLForDirections(list<Directions> directions)
{
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("data");

    for (list<Directions>::iterator sourceIt = directions.begin(); sourceIt != directions.end(); sourceIt++)
    {
        pugi::xml_node source = root.append_child("source");

        pugi::xml_attribute addressAttribute = source.append_attribute("address");
        addressAttribute.set_name("address");
        addressAttribute.set_value(sourceIt->source.address.c_str() );

        pugi::xml_attribute protocolAttribute = source.append_attribute("protocol");
        protocolAttribute.set_name("protocol");
        protocolAttribute.set_value(sourceIt->source.protocol.c_str() );

        for (list<AddressRecord>::iterator destinationIt = sourceIt->destinations.begin();
             destinationIt != sourceIt->destinations.end(); destinationIt++)
        {
            pugi::xml_node destination = source.append_child("destination");

            pugi::xml_attribute addressAttribute = destination.append_attribute("address");
            addressAttribute.set_name("address");
            addressAttribute.set_value(destinationIt->address.c_str() );

            pugi::xml_attribute protocolAttribute = destination.append_attribute("protocol");
            protocolAttribute.set_name("protocol");
            protocolAttribute.set_value(destinationIt->protocol.c_str() );
        }
    }

    stringstream payload;
    doc.save(payload);
    return payload.str();
}

void importDirectionsFromXML(string requestPayload, list<Directions>* directions)
{
    directions->clear();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(requestPayload.c_str(), requestPayload.length());

    if (result.status != pugi::status_ok)
        throw RemoteControlException(ERROR, "Bad XML syntax");

    pugi::xml_node root = doc.child("data");

    if (root == NULL)
        throw RSSReceiverException(ERROR, "No data node");

    if (root.child("source") == NULL)
        throw RSSReceiverException(ERROR, "No source nodes");

    for (pugi::xml_node sourceItem = root.child("source"); sourceItem;
         sourceItem = sourceItem.next_sibling("source") )
    {
        list<AddressRecord> destinations;

        for (pugi::xml_node destinationItem = sourceItem.child("destination");
             destinationItem; destinationItem = destinationItem.next_sibling("destination") )
        {
            AddressRecord currentAddressRecord;

            pugi::xml_attribute destinationAddress = destinationItem.attribute("address");
            if (destinationAddress == NULL)
                throw RSSReceiverException(ERROR, "No address attribute");

            pugi::xml_attribute destinationProtocol = destinationItem.attribute("protocol");
            if (destinationProtocol == NULL)
                throw RSSReceiverException(ERROR, "No protocol attribute");

            currentAddressRecord.address = destinationAddress.value();
            currentAddressRecord.protocol = destinationProtocol.value();
            destinations.push_back(currentAddressRecord);
        }

        pugi::xml_attribute sourceAddress = sourceItem.attribute("address");
        if (sourceAddress == NULL)
            throw RSSReceiverException(ERROR, "No address attribute");

        pugi::xml_attribute sourceProtocol = sourceItem.attribute("protocol");
        if (sourceProtocol == NULL)
            throw RSSReceiverException(ERROR, "No protocol attribute");

        Directions currentDirection;
        currentDirection.source.address = sourceAddress.value();
        currentDirection.source.protocol = sourceProtocol.value();
        currentDirection.destinations = destinations;
        directions->push_back(currentDirection);
    }
}

void signalHandler(int signal)
{
    printf("Exiting...");
    ConfigHandler configHandler;
    configHandler.saveConfig(signal);
    exit(0);
}
