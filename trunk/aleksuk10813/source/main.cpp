#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

#include "dispatcher.h"
#include "senders.h"
#include "config_handler.h"
#include "tests.h"
#include "remote_control.h"

const bool TESTING = false;

using namespace std;

int main(int argc, char **argv)
{
    if (TESTING)
    {
        Tester tester;
        tester.testSequence();
    }
    else
    {
        ReceiverArgs inputArgs;
        SenderArgs outputArgs;
        ConfigHandlerArgs configHandlerArgs;

        list<Directions>* directions = new list<Directions>;
        mutex* mutexVariable = new mutex;

        inputArgs.itemsQueue = new queue<InRecord>;
        outputArgs.itemsQueue = new queue<OutRecord>;

        inputArgs.mutexVariable = new mutex;
        outputArgs.mutexVariable = new mutex;

        inputArgs.conditionalVariable = new condition_variable;
        outputArgs.conditionalVariable = new condition_variable;

        inputArgs.sources = new list<string>;
        outputArgs.destinations = new list<string>;

        inputArgs.guids = new map<string, set<string> >;

        configHandlerArgs.argc = argc;
        configHandlerArgs.argv = argv;
        configHandlerArgs.guids = inputArgs.guids;
        configHandlerArgs.directions = new list<Directions>;
        configHandlerArgs.smtpSettings = new SMTPSettings;

        TestReceiver testReceiver;
        RSSReceiver rssReceiver;

        Dispatcher dispatcher;

        TestSender testOut;
        SMTPSender smtpOut;

        AddressRecord myAddress;
        myAddress.address = "aaa@h31.ishere.ru";

//        Directions inetFeed;
//        inetFeed.source.address = "http://news.yandex.ru/security.rss";
//        inetFeed.source.protocol = "RSS";
//        inetFeed.destinations.push_back(myAddress);
//        directions->push_back(inetFeed);

        RemoteControl remoteControl;
        ConfigHandler configHandler(configHandlerArgs);

//        Directions inetFeed;
//        inetFeed.source.address = "http://news.yandex.ru/security.rss";
//        inetFeed.source.protocol = "RSS";
//        inetFeed.destinations.push_back(myAddress);
//        directions->push_back(inetFeed);

//        Directions inetFeed;
//        inetFeed.source.address = "http://127.0.0.1/security.rss";
//        inetFeed.source.protocol = "RSS";
//        inetFeed.destinations.push_back(myAddress);
//        directions->push_back(inetFeed);

//        Directions testFeed;
//        testFeed.source.address = "TestFeed";
//        testFeed.source.protocol = "Test";
//        testFeed.destinations.push_back(myAddress);
//        directions->push_back(testFeed);

        thread receiver2(testReceiver, inputArgs);
//        thread receiver(rssReceiver, inputArgs);

        thread disp(dispatcher, inputArgs, outputArgs, directions, mutexVariable);

        thread sender2(testOut, outputArgs);
        thread sender(smtpOut, outputArgs);

        thread remote(remoteControl, directions, mutexVariable);
        //receiver.join();
        sender.join();
        //configHandler.saveConfig(1);
    }

    return 0;
}
