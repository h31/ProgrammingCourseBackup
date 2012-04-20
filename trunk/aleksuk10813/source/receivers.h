#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
#include <condition_variable>
#include <list>
#include <map>

#include "shared.h"

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

struct InRecord
{
    string feedName;
    string title;
    string data;
    string link;
    string guid;
    string pubDate;
};

struct HTTPRecord
{
    enum ReceiverStatusCode statusCode;
    string data;
};

class RSSReceiver
{
public:
    void operator()(queue<InRecord>* pipe,
                    list<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
protected:
    static const char* unitName;
    static const int updateIntervalInSeconds;

    string rawResponce;
    HTTPRecord ParsedResponce;
    list<InRecord> receivedItems;
    string responce;
    PartsOfURL partsOfURL;
    map<string, set<string> > guids;
    int sock;

    void windowsSocketStart();
    void sendRequest(PartsOfURL partsOfURL);
    string receiveResponce();

    HTTPRecord parseHTTP(const string responce);
    list<InRecord> parseFeed(const string rssContent);
    void leaveOnlyNewItems(const string sourceAddress);
    PartsOfURL parseUrl(const string url);
    virtual void downloadSource(const string url);

    enum ReceiverStatusCode getStatusCode(const char responce);
};

class TestReceiver
{
public:
    void operator()(queue<InRecord>* pipe,
                    list<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
};

#endif // RECEIVERS_H
