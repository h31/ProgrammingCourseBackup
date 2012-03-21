#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

#include "dispatcher.h"
#include "logger.h"
#include "tests.h"

const bool TESTING = true;

using namespace std;

int main()
{
    if (TESTING)
    {
        testSequence();
    }
    else
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
        rssIn.addSource("http://news.yandex.ru/security.rss");

        thread receiver2(testIn, inQueue, inputCond, inputMutex);
        thread receiver(rssIn, inQueue, inputCond, inputMutex);

        thread disp(dispatcher, inQueue, inputCond, inputMutex,
                    outQueue, outputCond, outputMutex);
        thread sender(testOut, outQueue, outputCond, outputMutex);
        receiver2.join();
    }

    return 0;
}
