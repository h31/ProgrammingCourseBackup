#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
#include <condition_variable>
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
    //enum ReceiverStatusCode code;
    string feedName;
    string title;
    string data;
    string link;
    string guid;
    string pubDate;
};

struct HTTPRecord
{
    enum ReceiverStatusCode code;
    string data;
};

template <class T>
class Receiver
{
public:
    void addSource(const string src, int interval=15);
    void removeSource(const string src);
    void operator()(queue<T>* pipe, condition_variable* inCond, mutex* m);
protected:
    set<string> sources;
};

class RSSReceiver : public Receiver <InRecord>
{
public:
    void operator()(queue<InRecord>* pipe, condition_variable* inCond, mutex* m);
protected:
    set<string> guids;

    HTTPRecord parseHTTP(const string responce);
    void parseFeed(const string rssContent, vector<InRecord> &itemArray);
    bool parseUrl(const string url, string& address, int& port, string& path);
    virtual string downloadSource(const string url);
};

class TestReceiver : public Receiver <InRecord>
{
public:
    void operator()(queue<InRecord>* pipe, condition_variable* inCond, mutex* m);
};

#endif // RECEIVERS_H
