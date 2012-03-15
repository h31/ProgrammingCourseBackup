#include "receivers.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void TestReceiver::operator()(queue<TestRecord>* pipe, condition_variable* cond, mutex* m)
{
    for (int i=0; i<10; i++)
    {
        TestRecord record;
        record.title = "Title";

        // преобразуем i как число в строку
        char temp_str[10];
        sprintf(temp_str, "%d", i);
        record.text = temp_str;
        //delete temp_str;

        unique_lock<mutex> lk(*m);
        // lk.try_lock();

        pipe->push(record);

        lk.unlock();
        cond->notify_one();

        this_thread::sleep_for(chrono::seconds(1));
    }
}
