#include "receivers.h"
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void TestReceiver::operator()(queue<TestRecord>* pipe, bool* ready, condition_variable* inCond)
{
    mutex m;
    for (int i=0; i<10; i++)
    {
        TestRecord record;
        record.title = "Title";
        record.text = i;

        unique_lock<mutex> lk(m);
        //lk.try_lock();
        ready=false;
        pipe->push(record);
        //*ready = true;
        inCond->notify_one();
        lk.unlock();

        this_thread::sleep_for(chrono::seconds(1));
    }
}
