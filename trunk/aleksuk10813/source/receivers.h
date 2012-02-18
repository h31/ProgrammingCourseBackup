#ifndef RECEIVERS_H
#define RECEIVERS_H

#include <string>
#include <queue>
#include <set>
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

template <class T>
class Receiver
{
public:
    bool addSource(string src, int interval=15);
    bool removeSource(string src);
    void worker();
private:
    queue<T>* pipe;
    set<string> sources;
};

class RSSReceiver : public Receiver <RSSRecord>
{
public:
    RSSReceiver(queue<RSSRecord>*);
private:
    set<string> guids;

    HTTPResponce downloadSource();
    void parseFeed(HTTPResponce input);

};

template <class T>
bool Receiver<T>::addSource(string src, int interval)
{
    return 0;
}

#endif // RECEIVERS_H
