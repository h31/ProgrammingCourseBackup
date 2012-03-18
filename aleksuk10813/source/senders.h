#ifndef SENDERS_H
#define SENDERS_H

#include <string>
#include <receivers.h>
#include <queue>
#include <set>
#include <condition_variable>

using namespace std;

struct OutRecord
{
    //enum ReceiverStatusCode code;
    string feedName;
    string title;
    string data;
    string link;
    string guid;
    string pubDate;
    string from;
    string to;
    string subject;
    string text;
};

template <class T>
class Sender
{
public:
    bool addDestination(string dest);
    bool removeDestination(string dest);
    void operator()(queue<T>* pipe, condition_variable* cond, mutex* m);
protected:
    set<string> destinations;
};

class SMTPSender : protected Sender <OutRecord>
{
public:
    void operator()(queue<OutRecord>* pipe, condition_variable* cond, mutex* m);
private:
    string genEmail(OutRecord input);
    bool sendEmail(string email,
                   string from,
                   string to);

};

class TestSender : protected Sender <OutRecord>
{
public:
    void operator()(queue<OutRecord>* pipe, condition_variable* cond, mutex* m);
};

#endif // SENDERS_H
