#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
#include <condition_variable>
using namespace std;

enum HTTPStatusCode
{
    OK = 1,
    NOT_IMPLEMENTED = 2,
    INVALID_DATA = 3,
    CLIENT_ERROR = 4,
    SERVER_ERROR = 5
};

struct HTTPRecord
{
    enum HTTPStatusCode code;
    string data;
};

struct RSSRecord
{
    string feed;

    string title;
    string description;
    string link;
    string guid;
    string pubDate;
};

struct TestRecord
{
    string title;
    string text;
};

template <class T>
class Receiver
{
public:
    bool addSource(string src, int interval=15);
    bool removeSource(string src);
    void operator()(queue<T>* pipe, condition_variable* inCond, mutex* m);
protected:
    set<string> sources;
};

class RSSReceiver : protected Receiver <RSSRecord>
{
public:
    void operator()(queue<RSSRecord>* pipe, condition_variable* inCond, mutex* m);
private:
    set<string> guids;

    HTTPRecord parseHTTP(const string responce);
    void parseFeed(HTTPRecord input);
    bool parseUrl(const string url, string& address, int& port, string& path);
    string downloadSource(const string url);
};

class TestReceiver : protected Receiver <TestRecord>
{
public:
    void operator()(queue<TestRecord>* pipe, condition_variable* inCond, mutex* m);
};

#endif // RECEIVERS_H
