#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <condition_variable>
#include <mutex>
#include <string>
#include <set>

using namespace std;

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
    string request;

    void establishServerSocket();
    void establishClientSocket();

    string getPath(string request);
    string generateXML(set<string> sources);
    void sendResponce(string payload);

    string receiveRequest();
    void runSocket();
    void runBind();
    void runListen();

};

#endif // REMOTE_CONTROL_H
