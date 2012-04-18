#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

#include "dispatcher.h"
#include "tests.h"
#include "remote_control.h"

const bool TESTING = false;

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
        set<string>* destinations = new set<string>;

        mutex* inputMutex = new mutex;
        mutex* outputMutex = new mutex;

        condition_variable* inputCond = new condition_variable;
        condition_variable* outputCond = new condition_variable;

        TestReceiver testIn;
        RSSReceiver rssIn;

        Dispatcher dispatcher;

        TestSender testOut;
        SMTPSender smtpOut;

        RemoteControl remoteControl;

        //sources->insert("http://127.0.0.1/security.rss");
        sources->insert("http://news.yandex.ru/security.rss");
        sources->insert("http://feeds.newsru.com/com/www/news/top");

        thread receiver2(testIn, inQueue, sources, inputCond, inputMutex);
        thread receiver(rssIn, inQueue, sources, inputCond, inputMutex);

        thread disp(dispatcher, inQueue, inputCond, inputMutex,
                                outQueue, outputCond, outputMutex);

        thread sender(testOut, outQueue, destinations, outputCond, outputMutex);

        thread remote(remoteControl, sources, inputMutex);
        receiver2.join();

//        OutRecord testRecord;
//        testRecord.subject = "Subject";
//        testRecord.text = "Text";
//        testRecord.to = "artem@h31.ishere.ru";
//        outQueue->push(testRecord);
//        thread sender(smtpOut, outQueue, destinations, outputCond, outputMutex);
//        sender.join();
    }

    return 0;
}
