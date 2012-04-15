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
    string out = "Tester" + string(name);
    out.append(": ");

    if (true == test() )
        out.append("Ok");
    else
        out.append("FAILED");
    log(INFO, out.c_str() );
}

void testSequence()
{
    runTest(RSSReceiverTest1, "RSSReceiver, test1 (Ошибки HTTP - случайные данные)");
    runTest(RSSReceiverTest2, "RSSReceiver, test2 (Ошибки HTTP - ошибка сервера)");
    runTest(RSSReceiverTest3, "RSSReceiver, test3 (Ошибки разбора XML - некорректный XML)");
    runTest(RSSReceiverTest4, "RSSReceiver, test4 (Ошибки разбора XML - некорректный RSS №1)");
    runTest(RSSReceiverTest5, "RSSReceiver, test5 (Ошибки разбора XML - некорректный RSS №2)");
    runTest(RSSReceiverTest6, "RSSReceiver, test6 (Ошибки разбора XML - образцовый RSS)");
    runTest(RSSReceiverTest7, "RSSReceiver, test7 (Ошибка сети - IPv6)");

    runTest(RemoteControlTest1, "RemoteControl, test1 (образцовый XML)");
    runTest(RemoteControlTest2, "RemoteControl, test2 (getMethodOfRequest)");

    runTest(SMTPSenderTest1, "SMTPSender, test1 (обработка точек нужна)");
    runTest(SMTPSenderTest2, "SMTPSender, test2 (обработка точек не нужна)");
    runTest(SMTPSenderTest3, "SMTPSender, test3 (генерация e-mail)");
}

bool RSSReceiverTest1()
{
    TestRSSReceiver testObj;
    set<string>* sources = new set<string>;
    sources->insert("dcrfcxfdrcxrfgc");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    try
    {
        testObj(pipe, sources, inCond, m);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool RSSReceiverTest2()
{
    TestRSSReceiver testObj;
    set<string>* sources = new set<string>;
    sources->insert("HTTP/1.1 502 Bad Gateway");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    try
    {
        testObj(pipe, sources, inCond, m);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool RSSReceiverTest3()
{
    TestRSSReceiver testObj;
    set<string>* sources = new set<string>;
    sources->insert("HTTP/1.1 200 OK\r\n\r\n<node");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    try
    {
        testObj(pipe, sources, inCond, m);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool RSSReceiverTest4()
{
    TestRSSReceiver testObj;
    set<string>* sources = new set<string>;
    sources->insert("HTTP/1.1 200 OK\r\n\r\n<node></node>");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    try
    {
        testObj(pipe, sources, inCond, m);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool RSSReceiverTest5()
{
    TestRSSReceiver testObj;
    set<string>* sources = new set<string>;
    sources->insert("HTTP/1.1 200 OK\r\n\r\n<rss><channel></channel></rss>");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    try
    {
        testObj(pipe, sources, inCond, m);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool RSSReceiverTest6()
{
    TestRSSReceiver testObj;
    ifstream test_xml("test_xml.txt");
    string test_str;
    getline(test_xml, test_str, '\0');
    test_str = "HTTP/1.1 200 OK\r\n\r\n" + test_str;

    set<string>* sources = new set<string>;
    sources->insert(test_str);
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    InRecord reference_record;
    reference_record.data = "Here is some text containing an interesting description.";
    reference_record.link = "http://www.wikipedia.org/";
    reference_record.title = "Example entry";

    try
    {
        testObj(pipe, sources, inCond, m);
        InRecord test_record = pipe->front();
        if (reference_record.data == test_record.data &&
            reference_record.link == test_record.link &&
            reference_record.title == test_record.title)
            return true;
        else
            return false;
    }
    catch (RSSReceiverException& e)
    {
        return false;
    }
}

bool RSSReceiverTest7()
{
    RSSReceiver testObj;
    set<string>* sources = new set<string>;
    sources->insert("http://www.ipv6.mx/index.php?format=feed&type=rss");
    queue<InRecord>* pipe = new queue<InRecord>;
    condition_variable* inCond = new condition_variable;
    mutex* m = new mutex;

    try
    {
        testObj(pipe, sources, inCond, m);
        return true;
    }
    catch (RSSReceiverException& e)
    {
        return false;
    }
}

bool RemoteControlTest1()
{
    return false; // TODO
}

bool RemoteControlTest2()
{
    RemoteControl testObj;
    if (testObj.getMethodOfRequest("GET /path HTTP/1.1") == "GET")
        return true;
    else return true;
}

bool SMTPSenderTest1()
{
    SMTPSender testObj;
    string input = "some text\r\n"
                   ".text\r\n";
    string reference_output = "some text\r\n"
                              "..text\r\n";
    string test_output;

    test_output = testObj.escapeDots(input);
    return test_output == reference_output;
}

bool SMTPSenderTest2()
{
    SMTPSender testObj;
    string input = "some text\r\n"
                   "text\r\n";
    string reference_output = "some text\r\n"
                              "text\r\n";
    string test_output;

    test_output = testObj.escapeDots(input);
    return test_output == reference_output;
}

bool SMTPSenderTest3()
{
    SMTPSender testObj;
    OutRecord input;
    input.subject = "Subject";
    input.to = "example@example.com";
    input.text = "Text";
    string reference_output = "From: sender@sender.com\r\n"
                              "To: example@example.com\r\n"
                              "Subject: Subject\r\n"
                              "\r\n"
                              "Text";
    string test_output;

    test_output = testObj.generateEmail(input);
    return test_output == reference_output;
}
