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
        map<string, list<string> >* adresses;

        queue<InRecord>* inQueue = new queue<InRecord>;
        queue<OutRecord>* outQueue = new queue<OutRecord>;

        list<string>* sources = new list<string>;
        list<string>* destinations = new list<string>;

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
        sources->push_back("http://news.yandex.ru/security.rss");
        sources->push_back("http://feeds.newsru.com/com/www/news/top");
        //sources->push_back("http://identi.ca/api/statuses/user_timeline/188782.rss");

        thread receiver2(testIn, inQueue, sources, inputCond, inputMutex);
        thread receiver(rssIn, inQueue, sources, inputCond, inputMutex);

        thread disp(dispatcher, inQueue, inputCond, inputMutex,
                                outQueue, outputCond, outputMutex,
                                adresses);

        //thread sender(testOut, outQueue, destinations, outputCond, outputMutex);
        thread sender(smtpOut, outQueue, destinations, outputCond, outputMutex);

        thread remote(remoteControl, adresses, inputMutex);
        receiver2.join();
    }

    return 0;
}
