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
    void operator()(queue<T>* pipe,
                    set<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
};

class RSSReceiver : public Receiver <InRecord>
{
public:
    void operator()(queue<InRecord>* pipe,
                    set<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
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
    void operator()(queue<InRecord>* pipe,
                    set<string>* sources,
                    condition_variable* inCond,
                    mutex* m);
};

#endif // RECEIVERS_H