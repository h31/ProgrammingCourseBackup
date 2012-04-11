#ifndef SENDERS_H
#define SENDERS_H

#include <string>
#include "receivers.h"
#include <queue>
#include <set>
#include <condition_variable>

using namespace std;

struct OutRecord
{
    //enum ReceiverStatusCode code;
    string to;
    string subject;
    string text;
};

template <class T>
class Sender
{
public:
    void operator()(queue<T>* pipe,
                    set<string>* destinations,
                    condition_variable* cond,
                    mutex* m);
};

class SMTPSender : protected Sender <OutRecord>
{
public:
    void operator()(queue<OutRecord>* pipe,
                    set<string>* destinations,
                    condition_variable* cond,
                    mutex* m);
// protected: // TODO: Решить
    int clientSock;
    static const char* unitName;

    string genEmail(OutRecord input);
    bool addressesCorrectness(OutRecord input);
    bool sendEmail(OutRecord addresses, string payload);
    void establishClientSocket();
    string escapeDots(const string data);

};

class TestSender : protected Sender <OutRecord>
{
public:
    void operator ()(queue<OutRecord> *pipe,
                     set<string> *destinations,
                     condition_variable *cond,
                     mutex *m);
};

#endif // SENDERS_H
