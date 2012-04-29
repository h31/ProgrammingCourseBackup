#include "receivers.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void TestReceiver::operator()(ReceiverArgs args)
{
    for (int i=0; i<10; i++)
    {
        InRecord record;
        record.title = "Title";
        record.feedName = "TestFeed";

        // преобразуем i как число в строку
        char temp_str[10];
        sprintf(temp_str, "%d", i);
        record.data = temp_str;
        //delete temp_str;

        unique_lock<mutex> lk(*args.mutexForQueue);
        // lk.try_lock();

        args.itemsQueue->push(record);

        lk.unlock();
        args.conditionalVariableForQueue->notify_one();

        this_thread::sleep_for(chrono::seconds(1));
    }
    // Workaround того, что после завершения потока Receiver программа падает
    // реальная реализация Receiver работает постоянно, поэтому проблема
    // касается только TestReceiver.
    this_thread::sleep_for(chrono::minutes(30));
}
