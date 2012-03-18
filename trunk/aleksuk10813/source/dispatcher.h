#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "receivers.h"
#include "senders.h"
#include <condition_variable>

class Dispatcher
{
public:
    void operator()(queue<InRecord>* inQueue, condition_variable* inputCond, mutex* inputMutex,
                    queue<OutRecord>* outQueue, condition_variable* outputCond, mutex* outputMutex);
private:
    string html2txt(string html);
};


#endif // DISPATCHER_H
