#ifndef SHARED_H
#define SHARED_H

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <map>
#include <set>
#include <time.h>

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

using namespace std;

struct InRecord
{
    string feedName;
    string title;
    string data;
    string link;
    string guid;
    string pubDate;
};

struct OutRecord
{
    //enum ReceiverStatusCode code;
    string to;
    string subject;
    string text;
    string senderProtocol;
};

struct AddressRecord
{
    string protocol;
    string address;
};

struct Directions
{
    AddressRecord source;
    list<AddressRecord> destinations;
};

struct SMTPSettings
{
    string username;
    string password;
    string server;
};

struct ReceiverArgs
{
    queue<InRecord>* itemsQueue;
    condition_variable* conditionalVariable;
    mutex* mutexVariable;
    list<string>* sources;
    map<string, set<string> >* guids;
};

struct SenderArgs
{
    queue<OutRecord>* itemsQueue;
    condition_variable* conditionalVariable;
    mutex* mutexVariable;
    list<string>* destinations;
    SMTPSettings* smtpSettings;
};

struct ConfigHandlerArgs
{
 int argc;
 char **argv;
 map<string, set<string> >* guids;
 list<Directions>* directions;
 SMTPSettings* smtpSettings;
};

enum Importance
{
    ERROR = 1,
    INFO = 2,
    DEBUG = 3
};

class RSSReceiverException
{
public:
    RSSReceiverException(enum Importance importance, string message);
};

class RemoteControlException
{
public:
    RemoteControlException(enum Importance importance, string message);
};

class ConfigHandlerException
{
public:
    ConfigHandlerException(enum Importance importance, string message);
};

class SMTPSenderException
{
public:
    SMTPSenderException(enum Importance importance, string message);
};

class AddressCorrectnessException {};

struct PartsOfURL
{
    string address;
    int port;
    string path;
};

void log(enum Importance importance, string message);
string receive_helper(int socket);
void send_helper(int clientSocket, string data);
int connect_helper(PartsOfURL url);

string generateXMLForDirections(list<Directions> directions);
list<Directions>* importDirectionsFromXML(string requestPayload);

#endif // SHARED_H
