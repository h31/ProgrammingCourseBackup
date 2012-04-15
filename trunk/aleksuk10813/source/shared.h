#ifndef SHARED_H
#define SHARED_H

#include <string>
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

enum Importance
{
    ERROR = 1,
    INFO = 2,
    DEBUG = 3
};

class RSSReceiverException
{
public:
    RSSReceiverException(enum Importance importance, const char *message);
};
class RemoteControlException
{
public:
    RemoteControlException(enum Importance importance, const char *message);
};

class AddressCorrectnessException {};

struct PartsOfURL
{
    string address;
    int port;
    string path;
};

void log(enum Importance importance, const char *message);
string receive_helper(int socket);
void send_helper(int clientSocket, string data);
int connect_helper(PartsOfURL url);

#endif // SHARED_H
