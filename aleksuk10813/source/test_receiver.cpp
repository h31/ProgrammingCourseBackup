#include "receivers.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void TestReceiver::operator()(queue<InRecord>* pipe, set<string>* sources, condition_variable* cond, mutex* m)
{
    for (int i=0; i<10; i++)
    {
        InRecord record;
        record.title = "Title";

        // преобразуем i как число в строку
        char temp_str[10];
        sprintf(temp_str, "%d", i);
        record.data = temp_str;
        //delete temp_str;

        unique_lock<mutex> lk(*m);
        // lk.try_lock();

        pipe->push(record);

        lk.unlock();
        cond->notify_one();

        this_thread::sleep_for(chrono::seconds(1));
    }
    // Workaround того, что после завершения потока Receiver программа падает
    // реальная реализация Receiver работает постоянно, поэтому проблема
    // касается только TestReceiver.
    this_thread::sleep_for(chrono::minutes(30));
}
