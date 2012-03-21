#ifndef TESTS_H
#define TESTS_H

#include "dispatcher.h"

class TestRSSReceiver : protected RSSReceiver
{
protected:
    string downloadSource(const string url);
};

#endif // TESTS_H
