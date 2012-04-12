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

class SMTPSender
{
public:
    void operator()(queue<OutRecord>* pipe,
                    set<string>* destinations,
                    condition_variable* cond,
                    mutex* m);
// protected: // TODO: Решить
    int clientSock;
    static const char* unitName;

    string generateEmail(OutRecord input);
    bool addressesCorrectness(OutRecord input);
    void sendEmail(OutRecord addresses, string payload);
    void establishClientSocket();
    string escapeDots(const string data);

};

class TestSender
{
public:
    void operator ()(queue<OutRecord> *pipe,
                     set<string> *destinations,
                     condition_variable *cond,
                     mutex *m);
};

#endif // SENDERS_H
