#ifndef TESTS_H
#define TESTS_H

#include "dispatcher.h"

class TestRSSReceiver : public RSSReceiver
{
protected:
    string downloadSource(const string url);
};

void runTest( bool (*test)(), const char *name = "" );
void testSequence();
bool test1();
bool test2();
bool test3();
bool test4();
bool test5();

#endif // TESTS_H
