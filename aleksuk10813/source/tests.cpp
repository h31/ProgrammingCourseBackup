#include <iostream>
#include <condition_variable>
#include <mutex>

#include "tests.h"
#include "shared.h"

string TestRSSReceiver::downloadSource(const string url)
{
    return url;
}

template <class T> void Receiver<T>::addSource(const string src, int interval)
{
    sources.insert(src);
}

void runTest(bool (*test)(), const char *name)
{
    if (true == test() )
        cout << name << ": " << "Ok";
    else
        cout << name << ": " << "FAILED";
    cout << endl;
}

void testSequence()
{
    runTest(test1, "test1 (Ошибки HTTP - случайные данные)");
    runTest(test2, "test2 (Ошибки HTTP - ошибка сервера)");
    runTest(test3, "test3 (Ошибки разбора XML - некорректный XML)");
    runTest(test4, "test4 (Ошибки разбора XML - некорректный RSS №1)");
    runTest(test5, "test4 (Ошибки разбора XML - некорректный RSS №2)");
}

bool test1()
{
    TestRSSReceiver testObj;
    testObj.addSource("dcrfcxfdrcxrfgc");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;
    try
    {
        testObj(pipe, inCond, m);
        return false;
    }
    catch (HTTPClientException& e)
    {
        return true;
    }
}

bool test2()
{
    TestRSSReceiver testObj;
    testObj.addSource("HTTP/1.1 502 Bad Gateway");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;
    try
    {
        testObj(pipe, inCond, m);
        return false;
    }
    catch (HTTPClientException& e)
    {
        return true;
    }
}

bool test3()
{
    TestRSSReceiver testObj;
    testObj.addSource("HTTP/1.1 200 OK\r\n\r\n<node");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;
    try
    {
        testObj(pipe, inCond, m);
        return false;
    }
    catch (XMLParserException& e)
    {
        return true;
    }
}

bool test4()
{
    TestRSSReceiver testObj;
    testObj.addSource("HTTP/1.1 200 OK\r\n\r\n<node></node>");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;
    try
    {
        testObj(pipe, inCond, m);
        return false;
    }
    catch (XMLParserException& e)
    {
        return true;
    }
}

bool test5()
{
    TestRSSReceiver testObj;
    testObj.addSource("HTTP/1.1 200 OK\r\n\r\n<rss><channel></channel></rss>");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;
    try
    {
        testObj(pipe, inCond, m);
        return false;
    }
    catch (XMLParserException& e)
    {
        return true;
    }
}
