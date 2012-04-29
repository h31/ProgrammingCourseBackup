#include "dispatcher.h"
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

void Dispatcher::operator()(ReceiverArgs input, SenderArgs output, list<Directions>* directions, mutex* mutexVariable)
{
    for (list<Directions>::iterator it = directions->begin(); it != directions->end(); it++)
        if (it->source.protocol == "RSS")
            input.sources->push_back(it->source.address);

    while (1)
    {
        unique_lock<mutex> inLock(*input.mutexVariable);
        input.conditionalVariable->wait(inLock);

        while (input.itemsQueue->size() > 0)
        {
            InRecord tempInRecord = input.itemsQueue->front();
            input.itemsQueue->pop();

            Directions tempDirections;
            unique_lock<mutex> directionsLock(*mutexVariable);
            // Находим нужный tempDirections на основании имени ленты из directions
            for (list<Directions>::iterator it = directions->begin(); it != directions->end(); it++)
                if (it->source.address == tempInRecord.feedName)
                {
                    tempDirections = *it;
                    break;
                }
            directionsLock.unlock();

            unique_lock<mutex> outLock(*output.mutexVariable);
            for (list<AddressRecord>::iterator it = tempDirections.destinations.begin(); it != tempDirections.destinations.end(); it++)
            {
                OutRecord tempOutRecord;
                tempOutRecord.subject = tempInRecord.title;
                tempOutRecord.text = tempInRecord.data;
                tempOutRecord.to = it->address;
                tempOutRecord.senderProtocol = it->protocol;
                output.itemsQueue->push(tempOutRecord);
            }
            outLock.unlock();
            output.conditionalVariable->notify_one();
        }
        inLock.unlock();
    }
}
