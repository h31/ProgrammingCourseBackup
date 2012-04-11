#ifndef TESTS_H
#define TESTS_H

#include "dispatcher.h"
#include "remote_control.h"

class TestRSSReceiver : public RSSReceiver
{
protected:
    string downloadSource(const string url);
};

void runTest( bool (*test)(), const char *name = "" );
void testSequence();

bool RSSReceiverTest1();
bool RSSReceiverTest2();
bool RSSReceiverTest3();
bool RSSReceiverTest4();
bool RSSReceiverTest5();
bool RSSReceiverTest6();
bool RSSReceiverTest7();

bool RemoteControlTest1();

bool SMTPSenderTest1();
bool SMTPSenderTest2();
bool SMTPSenderTest3();

#endif // TESTS_H
