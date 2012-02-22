#include <iostream>
#include <pthread.h>
#include "dispatcher.h"
#include <thread>

using namespace std;

int main()
{
    queue<RSSRecord>* rssQueue = new queue<RSSRecord>;
    RSSReceiver* rss = new RSSReceiver(rssQueue);
    rss->addSource("urlHere");

    thread t(ref(*rss));

    return 0;
}

RSSReceiver::RSSReceiver(queue<RSSRecord>*)
{

}
