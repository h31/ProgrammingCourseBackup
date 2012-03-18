#include <iostream>
#include "dispatcher.h"
#include <pthread.h>
#include <thread>
#include <mutex>

using namespace std;

int main()
{
    queue<InRecord>* inQueue = new queue<InRecord>;
    queue<OutRecord>* outQueue = new queue<OutRecord>;

    TestReceiver testIn;
    Dispatcher dispatcher;
    TestSender testOut;

    RSSReceiver rssIn;

    mutex* inputMutex = new mutex;
    mutex* outputMutex = new mutex;

    condition_variable* inputCond = new condition_variable;
    condition_variable* outputCond = new condition_variable;
    //test->addSource("urlHere");

    thread receiver2(testIn, inQueue, inputCond, inputMutex);
    thread receiver(rssIn, inQueue, inputCond, inputMutex);

    thread disp(dispatcher, inQueue, inputCond, inputMutex,
                            outQueue, outputCond, outputMutex);
    thread sender(testOut, outQueue, outputCond, outputMutex);

    receiver.join();

    //cout << testInQueue->size();

    return 0;
}
