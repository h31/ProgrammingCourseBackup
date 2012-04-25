#ifndef TESTS_H
#define TESTS_H

#include "receivers.h"
#include "remote_control.h"
#include "senders.h"

class TestRSSReceiver : public RSSReceiver
{
protected:
    void downloadSource(const string url);
};

class Tester
{
public:
    Tester();
    void testSequence();
private:
     void runTest( bool (Tester::*test)(), const char *name = "" );

    bool RSSReceiverTest1();
    bool RSSReceiverTest2();
    bool RSSReceiverTest3();
    bool RSSReceiverTest4();
    bool RSSReceiverTest5();
    bool RSSReceiverTest6();
    bool RSSReceiverTest7();

    bool RemoteControlTest1();
    bool RemoteControlTest2();
    bool RemoteControlTest3();
    bool RemoteControlTest4();
    bool RemoteControlTest5();

    bool SMTPSenderTest1();
    bool SMTPSenderTest2();
    bool SMTPSenderTest3();

    ReceiverArgs inputArgs;
    SenderArgs outputArgs;
};

#endif // TESTS_H
