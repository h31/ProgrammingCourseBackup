#include "senders.h"
#include <iostream>
#include <mutex>
#include <thread>
//#include <stdio.h>
//#include <stdlib.h>

using namespace std;

void TestSender::operator()(queue<TestRecord>* pipe, condition_variable* cond, mutex* m)
{
    while (1)
    {
        unique_lock<mutex> outLock(*m);
        cond->wait(outLock);

        while (pipe->size() > 0)
        {
            cout << "Queue size: " << pipe->size() << endl;
            TestRecord temp = pipe->front();
            cout << "Title: " << temp.title << endl;
            cout << "Text: " << temp.text << endl;
            cout << endl;
            pipe->pop();
        }
    }
}
