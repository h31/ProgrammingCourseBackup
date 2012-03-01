#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "receivers.h"
#include "senders.h"
#include <condition_variable>

class Dispatcher
{
public:
    void operator()(queue<TestRecord>* r_pipe, queue<TestRecord>* s_pipe,
                    bool* inReady, condition_variable* inCond);
private:
    string html2txt(string html);
};


#endif // DISPATCHER_H
