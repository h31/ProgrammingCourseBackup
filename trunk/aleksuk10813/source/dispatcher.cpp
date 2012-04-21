#include "dispatcher.h"
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

void Dispatcher::operator()(queue<InRecord>* inQueue, condition_variable* inputCond, mutex* inputMutex,
                            queue<OutRecord>* outQueue, condition_variable* outputCond, mutex* outputMutex,
                            map<string, list<string> >* adresses)
{
    while (1)
    {
        unique_lock<mutex> inLock(*inputMutex);
        inputCond->wait(inLock);

        while (inQueue->size() > 0)
        {
            InRecord tempInRecord = inQueue->front();
            inQueue->pop();

            map<string, list<string> >::iterator destinations = adresses->find(tempInRecord.feedName);

            for (list<string>::iterator it = destinations->second.begin(); it != destinations->second.end(); it++)
            {
                unique_lock<mutex> outLock(*outputMutex);
                OutRecord tempOutRecord;
                tempOutRecord.subject = tempInRecord.title;
                tempOutRecord.text = tempInRecord.data;
                tempOutRecord.to = (*it);
                outQueue->push(tempOutRecord);
                outLock.unlock();
                outputCond->notify_one();
            }
        }
    }
}
