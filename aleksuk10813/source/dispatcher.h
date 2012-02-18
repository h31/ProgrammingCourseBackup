#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "receivers.h"
#include "senders.h"

class Dispatcher
{
public:
    Dispatcher(queue<RSSRecord>*, queue<SMTPRecord>*);
    void worker();
private:
    string html2txt(string html);
};

#endif // DISPATCHER_H
