#include <iostream>
#include "dispatcher.h"
#include <pthread.h>
#include <thread>

using namespace std;

int main()
{
    queue<TestRecord>* testInQueue = new queue<TestRecord>;
    queue<TestRecord>* testOutQueue = new queue<TestRecord>;

    TestReceiver test;
    Dispatcher dispatcher;
    bool* inReady;
    condition_variable* inCond = new condition_variable;
    //test->addSource("urlHere");

    thread receiver(test, testInQueue, inReady, inCond);
    //

    thread disp(dispatcher, testInQueue, testOutQueue, inReady, inCond); // testOutQueue
    receiver.join();

    //cout << testInQueue->size();

    return 0;
}
