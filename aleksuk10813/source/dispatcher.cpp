#include "dispatcher.h"
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

void Dispatcher::operator()(queue<TestRecord>* in_pipe, queue<TestRecord>* out_pipe,
                            bool* ready, condition_variable* inCond)
{
    mutex m;
    int i=0;
    unique_lock<mutex> lk(m);
    while(!ready)
        inCond->wait(lk);
    if (in_pipe->size() > 0)
    {
        TestRecord temp = in_pipe->front();
        cout << temp.text;
    }
}
