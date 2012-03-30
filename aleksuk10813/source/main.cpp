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
        testSequence();
    }
    else
    {
        queue<InRecord>* inQueue = new queue<InRecord>;
        queue<OutRecord>* outQueue = new queue<OutRecord>;

        set<string>* sources = new set<string>;

        mutex* inputMutex = new mutex;
        mutex* outputMutex = new mutex;

        condition_variable* inputCond = new condition_variable;
        condition_variable* outputCond = new condition_variable;

        TestReceiver testIn;
        RSSReceiver rssIn;
        Dispatcher dispatcher;
        TestSender testOut;

        RemoteControl remoteControl;

        //sources->insert("http://127.0.0.1/security.rss");
        sources->insert("http://news.yandex.ru/security.rss");
        sources->insert("http://feeds.newsru.com/com/www/news/top");

        thread receiver2(testIn, inQueue, sources, inputCond, inputMutex);
        thread receiver(rssIn, inQueue, sources, inputCond, inputMutex);

        thread disp(dispatcher, inQueue, inputCond, inputMutex,
                                outQueue, outputCond, outputMutex);

        thread sender(testOut, outQueue, outputCond, outputMutex);

        thread remote(remoteControl, sources, inputMutex);
        receiver2.join();
    }

    return 0;
}
