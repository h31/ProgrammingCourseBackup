#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
#include <condition_variable>
using namespace std;

struct HTTPResponce
{
    int code;
    string responce;
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
    void operator()(queue<RSSRecord>* pipe);
private:
    set<string> guids;

    HTTPResponce downloadSource();
    void parseFeed(HTTPResponce input);
};

class TestReceiver : protected Receiver <TestRecord>
{
public:
    void operator()(queue<TestRecord>* pipe, condition_variable* inCond, mutex* m);
};

#endif // RECEIVERS_H
