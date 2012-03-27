#include <iostream>
#include <fstream>
#include <condition_variable>
#include <mutex>

#include "tests.h"
#include "shared.h"

string TestRSSReceiver::downloadSource(const string url)
{
    return url;
}

//template <class T> void Receiver<T>::addSource(const string src, int interval)
//{
//    sources.insert(src);
//}

void runTest(bool (*test)(), const char *name)
{
    string out = name;
    out.append(": ");

    if (true == test() )
        out.append("Ok");
    else
        out.append("FAILED");
    log(INFO, "Tester", out.c_str() );
}

void testSequence()
{
    runTest(test1, "test1 (Ошибки HTTP - случайные данные)");
//    runTest(test2, "test2 (Ошибки HTTP - ошибка сервера)");
//    runTest(test3, "test3 (Ошибки разбора XML - некорректный XML)");
//    runTest(test4, "test4 (Ошибки разбора XML - некорректный RSS №1)");
//    runTest(test5, "test5 (Ошибки разбора XML - некорректный RSS №2)");
//    runTest(test6, "test6 (Ошибки разбора XML - образцовый RSS)");
//    runTest(test7, "test7 (Ошибка сети - IPv6)");
}

bool test1()
{
    TestRSSReceiver testObj;
    set<string> sources;
    sources.insert("dcrfcxfdrcxrfgc");
    queue<InRecord> pipe;
    condition_variable inCond;
    mutex m;
    try
    {
        testObj(pipe, sources, inCond, m);
        return false;
    }
    catch (HTTPClientException& e)
    {
        return true;
    }
}

//bool test2()
//{
//    TestRSSReceiver testObj;
//    testObj.addSource("HTTP/1.1 502 Bad Gateway");
//    queue<InRecord>* pipe = new queue<InRecord>;
//    condition_variable* inCond = new condition_variable;
//    mutex* m = new mutex;
//    try
//    {
//        testObj(pipe, inCond, m);
//        return false;
//    }
//    catch (HTTPClientException& e)
//    {
//        return true;
//    }
//}

//bool test3()
//{
//    TestRSSReceiver testObj;
//    testObj.addSource("HTTP/1.1 200 OK\r\n\r\n<node");
//    queue<InRecord>* pipe = new queue<InRecord>;
//    condition_variable* inCond = new condition_variable;
//    mutex* m = new mutex;
//    try
//    {
//        testObj(pipe, inCond, m);
//        return false;
//    }
//    catch (XMLParserException& e)
//    {
//        return true;
//    }
//}

//bool test4()
//{
//    TestRSSReceiver testObj;
//    testObj.addSource("HTTP/1.1 200 OK\r\n\r\n<node></node>");
//    queue<InRecord>* pipe = new queue<InRecord>;
//    condition_variable* inCond = new condition_variable;
//    mutex* m = new mutex;
//    try
//    {
//        testObj(pipe, inCond, m);
//        return false;
//    }
//    catch (XMLParserException& e)
//    {
//        return true;
//    }
//}

//bool test5()
//{
//    TestRSSReceiver testObj;
//    testObj.addSource("HTTP/1.1 200 OK\r\n\r\n<rss><channel></channel></rss>");
//    queue<InRecord>* pipe = new queue<InRecord>;
//    condition_variable* inCond = new condition_variable;
//    mutex* m = new mutex;
//    try
//    {
//        testObj(pipe, inCond, m);
//        return false;
//    }
//    catch (XMLParserException& e)
//    {
//        return true;
//    }
//}

//bool test6()
//{
//    TestRSSReceiver testObj;
//    ifstream test_xml("test_xml.txt");
//    string test_str;
//    getline(test_xml, test_str, '\0');
//    test_str = "HTTP/1.1 200 OK\r\n\r\n" + test_str;

//    testObj.addSource(test_str);
//    queue<InRecord>* pipe = new queue<InRecord>;
//    condition_variable* inCond = new condition_variable;
//    mutex* m = new mutex;

//    InRecord reference_record;
//    reference_record.data = "Here is some text containing an interesting description.";
//    reference_record.link = "http://www.wikipedia.org/";
//    reference_record.title = "Example entry";

//    try
//    {
//        testObj(pipe, inCond, m);
//        InRecord test_record = pipe->front();
//        if (reference_record.data == test_record.data &&
//            reference_record.link == test_record.link &&
//            reference_record.title == test_record.title)
//            return true;
//        else
//            return false;
//    }
//    catch (XMLParserException& e)
//    {
//        return false;
//    }
//}

//bool test7()
//{
//    RSSReceiver testObj;
//    testObj.addSource("http://www.ipv6.mx/index.php?format=feed&type=rss");
//    queue<InRecord>* pipe = new queue<InRecord>;
//    condition_variable* inCond = new condition_variable;
//    mutex* m = new mutex;
//    try
//    {
//        testObj(pipe, inCond, m);
//        return true;
//    }
//    catch (HTTPClientException& e)
//    {
//        return false;
//    }
//}
