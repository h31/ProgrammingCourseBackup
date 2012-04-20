#include "dispatcher.h"
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

void Dispatcher::operator()(queue<InRecord>* inQueue, condition_variable* inputCond, mutex* inputMutex,
                            queue<OutRecord>* outQueue, condition_variable* outputCond, mutex* outputMutex)
{
    while (1)
    {
        unique_lock<mutex> inLock(*inputMutex);
        inputCond->wait(inLock);

        while (inQueue->size() > 0)
        {
            InRecord temp = inQueue->front();
            inQueue->pop();

            // временно поломано
            unique_lock<mutex> outLock(*outputMutex);
            OutRecord out;
            out.subject = temp.title;
            out.text = temp.data;
            out.to = "artem@h31.ishere.ru";
            outQueue->push(out);
            outLock.unlock();
            outputCond->notify_one();
        }
    }
}
