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
    void operator()(set<string>* sources,
                    mutex* m);
private:
    int serverSock;
    int clientSock;
    static const char* unitName;
    string path;
    string method;
    string request;
    string payload;

    void establishServerSocket();
    void establishClientSocket();

    enum TypeOfRequest getTypeOfRequest();
    string getRequestedPath(string request);
    string getMethodOfRequest(string request);
    string getPayloadOfPOST(string request);
    string generateXMLForSources(set<string> sources);
    void importOPML(string opml, set<string>* sources);
    void importSources(string requestPayload, set<string>* sources);
    void sendResponce(string payload);

    string receiveRequest();
    void runSocket();
    void runBind();
    void runListen();
    void windowsSocketStart();

    friend bool RemoteControlTest2();
    friend bool RemoteControlTest3();
    friend bool RemoteControlTest4();
    friend bool RemoteControlTest5();
};

#endif // REMOTE_CONTROL_H
