#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

#include "dispatcher.h"
#include "tests.h"
#include "remote_control.h"

const bool TESTING = true;

using namespace std;

int main()
{
    if (TESTING)
    {
        //testSequence();
        condition_variable inputCond;
        mutex inputMutex;
        set<string> sources;
        sources.insert("123");
        sources.insert("234");
        RemoteControl r;
        r(sources, inputCond, inputMutex);
    }
    else
    {
        queue<InRecord>* inQueue = new queue<InRecord>;
        queue<OutRecord>* outQueue = new queue<OutRecord>;

        TestReceiver testIn;
        Dispatcher dispatcher;
        TestSender testOut;
        set<string> sources;

        RSSReceiver rssIn;

        mutex* inputMutex = new mutex;
        mutex* outputMutex = new mutex;

        condition_variable* inputCond = new condition_variable;
        condition_variable* outputCond = new condition_variable;
        //rssIn.addSource("http://127.0.0.1/security.rss");

//        thread receiver2(testIn, inQueue, inputCond, inputMutex);
//        thread receiver(rssIn, sources, inQueue, inputCond, inputMutex);

//        thread disp(dispatcher, inQueue, inputCond, inputMutex,
//                    outQueue, outputCond, outputMutex);
//        thread sender(testOut, outQueue, outputCond, outputMutex);
//        receiver2.join();
    }

    return 0;
}
