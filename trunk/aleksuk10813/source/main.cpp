#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <signal.h>

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

        inputArgs.mutexForQueue = new mutex;
        outputArgs.mutexVariable = new mutex;

        inputArgs.conditionalVariableForQueue = new condition_variable;
        outputArgs.conditionalVariable = new condition_variable;

        inputArgs.guids = new map<string, set<string> >;
        inputArgs.directions = directions;

        inputArgs.rssSettings = new RSSSettings;
        outputArgs.smtpSettings = new SMTPSettings;

        configHandlerArgs.argc = argc;
        configHandlerArgs.argv = argv;
        configHandlerArgs.guids = inputArgs.guids;
        configHandlerArgs.directions = directions;
        configHandlerArgs.rssSettings = inputArgs.rssSettings;
        configHandlerArgs.smtpSettings = outputArgs.smtpSettings;

        TestReceiver testReceiver;
        RSSReceiver rssReceiver;

        Dispatcher dispatcher;

        TestSender testOut;
        SMTPSender smtpOut;

        RemoteControl remoteControl;
        ConfigHandler configHandler(configHandlerArgs);

        thread receiver2(testReceiver, inputArgs);
        thread receiver(rssReceiver, inputArgs);

        thread disp(dispatcher, inputArgs, outputArgs, directions, mutexVariable);

        thread sender2(testOut, outputArgs);
        thread sender(smtpOut, outputArgs);

        thread remote(remoteControl, directions, mutexVariable);

        // TODO: оно вообще не работает.
//        struct sigaction sa;
//        sa.sa_handler = signalHandler;
//        sigaction(SIGTERM, &sa, 0);
        //sigaction(SIGINT, &sa, 0);
//        signal(SIGTERM, signalHandler);
//        signal(SIGINT, signalHandler);

        disp.join();
    }

    return 0;
}
