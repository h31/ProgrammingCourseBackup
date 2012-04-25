#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <condition_variable>
#include <mutex>
#include <string>
#include <set>
#include "tests.h"

using namespace std;

enum TypeOfRequest
{
    GET_SOURCES,
    SET_SOURCES,

    EXPORT_OPML,
    IMPORT_OPML
};

class RemoteControl
{
public:
    void operator()(list<Directions>* directions, mutex* m);
private:
    int serverSock;
    int clientSock;
    static const char* unitName;
    string path;
    string method;
    string request;
    string payload;
    list<Directions>* directions;

    void establishServerSocket();
    void establishClientSocket();

    enum TypeOfRequest getTypeOfRequest();
    string getRequestedPath(string request);
    string getMethodOfRequest(string request);
    string getPayloadOfPOST(string request);
    string generateXMLForSources();
    void importOPML(string opml);
    void importSources(string requestPayload);
    void sendResponce(string payload);

    string receiveRequest();
    void runSocket();
    void runBind();
    void runListen();
    void windowsSocketStart();

    friend class Tester;
};

#endif // REMOTE_CONTROL_H
