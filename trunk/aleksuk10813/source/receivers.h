#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
#include <condition_variable>

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
                    set<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
protected:
    set<string> guids;
    int sock;
    static const char* unitName;
    void windowsSocketStart();
    void sendRequest(PartsOfURL partsOfURL);
    string receiveResponce();

    HTTPRecord parseHTTP(const string responce);
    void parseFeed(const string rssContent, vector<InRecord> &itemArray);
    PartsOfURL parseUrl(const string url);
    virtual string downloadSource(const string url);

    enum ReceiverStatusCode getStatusCode(const char responce);
};

class TestReceiver
{
public:
    void operator()(queue<InRecord>* pipe,
                    set<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
};

#endif // RECEIVERS_H
