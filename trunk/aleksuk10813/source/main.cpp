#include <iostream>
#include <pthread.h>
#include "dispatcher.h"

using namespace std;

int main()
{
    queue<RSSRecord>* rssQueue = new queue<RSSRecord>;
    RSSReceiver* rss = new RSSReceiver(rssQueue);
    rss->addSource("urlHere");
    // rss.run;

    /*queue<TestRecord>* testQueue = new queue<TestRecord>;
    TestReceiver* test = new TestReceiver(testQueue);
    // test.run; */
    return 0;
}

RSSReceiver::RSSReceiver(queue<RSSRecord>*)
{

}
