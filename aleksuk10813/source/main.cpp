#include <iostream>
#include "dispatcher.h"
#include <pthread.h>
#include <thread>
#include <mutex>

using namespace std;

int main()
{
    queue<InRecord>* testInQueue = new queue<InRecord>;
    queue<OutRecord>* testOutQueue = new queue<OutRecord>;
    queue<InRecord>* rssInQueue = new queue<InRecord>;

    TestReceiver testIn;
    Dispatcher dispatcher;
    TestSender testOut;

    RSSReceiver rssIn;

    mutex* inputMutex = new mutex;
    mutex* outputMutex = new mutex;

    condition_variable* inputCond = new condition_variable;
    condition_variable* outputCond = new condition_variable;
    //test->addSource("urlHere");

    thread receiver(rssIn, rssInQueue, inputCond, inputMutex);

    //thread disp(dispatcher, testInQueue, inputCond, inputMutex,
    //                        testOutQueue, outputCond, outputMutex);
    //thread sender(testOut, testOutQueue, outputCond, outputMutex);

    receiver.join();

    //cout << testInQueue->size();

    return 0;
}
