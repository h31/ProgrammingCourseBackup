#include "dispatcher.h"
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

void Dispatcher::operator()(queue<TestRecord>* inQueue, condition_variable* inputCond, mutex* inputMutex,
                            queue<TestRecord>* outQueue, condition_variable* outputCond, mutex* outputMutex)
{
    while (1)
    {
        unique_lock<mutex> inLock(*inputMutex);
        inputCond->wait(inLock);

        while (inQueue->size() > 0)
        {
            TestRecord temp = inQueue->front();
            inQueue->pop();

            unique_lock<mutex> outLock(*outputMutex);
            outQueue->push(temp);
            outLock.unlock();
            outputCond->notify_one();
        }
    }
}
