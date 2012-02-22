#ifndef SENDERS_H
#define SENDERS_H

#include <string>

using namespace std;

struct SMTPRecord
{
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
    void operator() ();
private:
    queue<T>* pipe;
    set<string> destinations;
};

class SMTPSender : public Sender <SMTPRecord>
{
public:
    SMTPSender(queue<SMTPRecord>*);
private:

    string genEmail(SMTPRecord input);
    bool sendEmail(string email,
                   string from,
                   string to);

};

string SMTPSender::genEmail(SMTPRecord input)
{
    return 0;
}

#endif // SENDERS_H
