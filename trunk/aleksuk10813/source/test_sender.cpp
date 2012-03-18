#include "senders.h"
#include <iostream>
#include <mutex>
#include <thread>
//#include <stdio.h>
//#include <stdlib.h>

using namespace std;

void TestSender::operator()(queue<OutRecord>* pipe, condition_variable* cond, mutex* m)
{
    while (1)
    {
        unique_lock<mutex> outLock(*m);
        cond->wait(outLock);

        while (pipe->size() > 0)
        {
            cout << "Queue size: " << pipe->size() << endl;
            OutRecord temp = pipe->front();
            cout << "Subject: " << temp.subject << endl;
            cout << "To: " << temp.to << endl;
            cout << "Text: " << temp.text << endl;
            cout << endl;
            pipe->pop();
        }
    }
}
