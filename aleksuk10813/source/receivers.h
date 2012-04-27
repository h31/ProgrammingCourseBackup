#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
#include <condition_variable>
#include <list>
#include <map>

#include "shared.h"
#include "dispatcher.h"

using namespace std;

enum ReceiverStatusCode
{
    // если что-то не так, то номер больше единицы
    OK = 1,
    NOT_IMPLEMENTED = 2,
    INVALID_DATA = 3,
    CLIENT_ERROR = 4,
    SERVER_ERROR = 5
};

struct HTTPRecord
{
    enum ReceiverStatusCode statusCode;
    string data;
};

class RSSReceiver
{
public:
    void operator()(ReceiverArgs args);
protected:
    static const char* unitName;
    static const int updateIntervalInSeconds;

    string rawResponce;
    HTTPRecord ParsedResponce;
    list<InRecord> receivedItems;
    string responce;
    PartsOfURL partsOfURL;
    string currentURL;
    int sock;

    void windowsSocketStart();
    void sendRequest(PartsOfURL partsOfURL);
    string receiveResponce();

    HTTPRecord parseHTTP(const string responce);
    list<InRecord> parseFeed(const string rssContent);
    void leaveOnlyNewItems(const string sourceAddress, map<string, set<string> >* guids);
    PartsOfURL parseUrl(const string url);
    virtual void downloadSource(const string url);

    enum ReceiverStatusCode getStatusCode(const char responce);
};

class TestReceiver
{
public:
    void operator()(ReceiverArgs args);
};

#endif // RECEIVERS_H
