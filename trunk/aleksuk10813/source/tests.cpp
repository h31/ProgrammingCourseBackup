#include <iostream>
#include <fstream>
#include <condition_variable>
#include <mutex>

#include "tests.h"
#include "shared.h"

void TestRSSReceiver::downloadSource(const string url)
{
    rawResponce = url; // Хак
}

void Tester::runTest(bool (Tester::* test)(), const char *name)
{
    string out = "Tester" + string(name);
    out.append(": ");

    if (true == (this->*test)() )
        out.append("Ok");
    else
        out.append("FAILED");
    log(INFO, out.c_str() );
}

void Tester::testSequence()
{
    runTest(&Tester::RSSReceiverTest1, "RSSReceiver, test1 (Ошибки HTTP - случайные данные)");
    runTest(&Tester::RSSReceiverTest2, "RSSReceiver, test2 (Ошибки HTTP - ошибка сервера)");
    runTest(&Tester::RSSReceiverTest3, "RSSReceiver, test3 (Ошибки разбора XML - некорректный XML)");
    runTest(&Tester::RSSReceiverTest4, "RSSReceiver, test4 (Ошибки разбора XML - некорректный RSS №1)");
    runTest(&Tester::RSSReceiverTest5, "RSSReceiver, test5 (Ошибки разбора XML - некорректный RSS №2)");
    runTest(&Tester::RSSReceiverTest6, "RSSReceiver, test6 (Ошибки разбора XML - образцовый RSS)");
    runTest(&Tester::RSSReceiverTest7, "RSSReceiver, test7 (Ошибка сети - IPv6)");

    runTest(&Tester::RemoteControlTest1, "RemoteControl, test1 (образцовый XML)");
    runTest(&Tester::RemoteControlTest2, "RemoteControl, test2 (getMethodOfRequest)");
    runTest(&Tester::RemoteControlTest3, "RemoteControl, test3 (getMethodOfRequest)");
    runTest(&Tester::RemoteControlTest4, "RemoteControl, test4 (getRequestedPath)");
    runTest(&Tester::RemoteControlTest5, "RemoteControl, test5 (getRequestedPath)");

    runTest(&Tester::SMTPSenderTest1, "SMTPSender, test1 (обработка точек нужна)");
    runTest(&Tester::SMTPSenderTest2, "SMTPSender, test2 (обработка точек не нужна)");
    runTest(&Tester::SMTPSenderTest3, "SMTPSender, test3 (генерация e-mail)");

    runTest(&Tester::ConfigHandlerTest1, "ConfigHandler, test1 (чтение и запись GUID)");
    runTest(&Tester::ConfigHandlerTest2, "ConfigHandler, test2 (чтение и запись Directions)");
}

bool Tester::RSSReceiverTest1()
{
    TestRSSReceiver testObj;
    inputArgs.sources = new list<string>(1, "dcrfcxfdrcxrfgc");

    try
    {
        testObj(inputArgs);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool Tester::RSSReceiverTest2()
{
    TestRSSReceiver testObj;
    inputArgs.sources = new list<string>(1, "HTTP/1.1 502 Bad Gateway");

    try
    {
        testObj(inputArgs);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool Tester::RSSReceiverTest3()
{
    TestRSSReceiver testObj;
    list<string>* sources = new list<string>(1, "HTTP/1.1 200 OK\r\n\r\n<node");

    try
    {
        testObj(inputArgs);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool Tester::RSSReceiverTest4()
{
    TestRSSReceiver testObj;
    inputArgs.sources = new list<string>(1, "HTTP/1.1 200 OK\r\n\r\n<node></node>");

    try
    {
        testObj(inputArgs);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool Tester::RSSReceiverTest5()
{
    TestRSSReceiver testObj;
    inputArgs.sources = new list<string>(1, "HTTP/1.1 200 OK\r\n\r\n<rss><channel></channel></rss>");

    try
    {
        testObj(inputArgs);
        return false;
    }
    catch (RSSReceiverException& e)
    {
        return true;
    }
}

bool Tester::RSSReceiverTest6()
{
    TestRSSReceiver testObj;
    ifstream test_xml("test_xml.txt");
    string test_str;
    getline(test_xml, test_str, '\0');
    test_str = "HTTP/1.1 200 OK\r\n\r\n" + test_str;

    inputArgs.sources = new list<string>(1, test_str);

    InRecord reference_record;
    reference_record.data = "Here is some text containing an interesting description.";
    reference_record.link = "http://www.wikipedia.org/";
    reference_record.title = "Example entry";

    try
    {
        testObj(inputArgs);
        InRecord test_record = inputArgs.itemsQueue->front();
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

bool Tester::RSSReceiverTest7()
{
    RSSReceiver testObj;
    inputArgs.sources = new list<string>(1, "http://www.ipv6.mx/index.php?format=feed&type=rss");

    try
    {
        testObj(inputArgs);
        return true;
    }
    catch (RSSReceiverException& e)
    {
        return false;
    }
}

bool Tester::RemoteControlTest1()
{
    return false; // TODO
}

bool Tester::RemoteControlTest2()
{
    RemoteControl testObj;
    if (testObj.getMethodOfRequest("GET /path HTTP/1.1") == "GET")
        return true;
    else return true;
}

bool Tester::RemoteControlTest3()
{
    RemoteControl testObj;
    if (testObj.getMethodOfRequest("POST /path HTTP/1.1") == "POST")
        return true;
    else return true;
}

bool Tester::RemoteControlTest4()
{
    RemoteControl testObj;
    if (testObj.getRequestedPath("GET /path HTTP/1.1") == "path")
        return true;
    else return true;
}

bool Tester::RemoteControlTest5()
{
    RemoteControl testObj;
    if (testObj.getRequestedPath("POST /path HTTP/1.1") == "path")
        return true;
    else return true;
}

bool Tester::SMTPSenderTest1()
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

bool Tester::SMTPSenderTest2()
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

bool Tester::SMTPSenderTest3()
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

bool Tester::ConfigHandlerTest1()
{
    ConfigHandler testObj;
    testObj.guids = new map<string, set<string> >;
    try
    {
        testObj.guidsFilePath = "guids_reference.xml";
        testObj.readGuidsFile();
        testObj.guidsFilePath = "guids_test_result.xml";
        testObj.writeGuidsFile();
    }
    catch(...)
    {
        return false;
    }
    return filesAreEqual("guids_reference.xml", "guids_test_result.xml");
}

bool Tester::ConfigHandlerTest2()
{
    ConfigHandler testObj;
    testObj.directions = new list<Directions>;
    try
    {
        testObj.DirectionsFilePath = "directions_reference.xml";
        testObj.readDirectionsFile();
        testObj.DirectionsFilePath = "directions_test_result.xml";
        testObj.writeDirectionsFile();
    }
    catch(...)
    {
        return false;
    }
    return filesAreEqual("directions_reference.xml", "directions_test_result.xml");
}

bool Tester::filesAreEqual(const char *referenceFilename, const char *testResultFilename)
{
    // некогда написанный тестировщик для третьего практикума
    FILE* referenceResult;
    FILE* programResult;

    int referenceEOF;
    int programEOF;

    bool filesAreEqual = 0;

    referenceResult = fopen(referenceFilename, "r");
    programResult = fopen(testResultFilename, "r");

    if (referenceResult == NULL || programResult == NULL)
        filesAreEqual = 0;

    while (1)
    {
        referenceEOF = feof(referenceResult);
        programEOF = feof(programResult);
        if ( referenceEOF && programEOF )
        {
            // И там, и там конец файла, символы пока что совпадали - значит всё нормально
            filesAreEqual = 1;
            break;
        }
        else if ( (referenceEOF && !programEOF) || (!referenceEOF && programEOF) )
        {
            filesAreEqual = 0;
            break;
        }
        else
        {
            if (getc(referenceResult) != getc(programResult) )
            {
                filesAreEqual = 0;
                break;
            }
        }
    }

    fclose(referenceResult);
    fclose(programResult);

    if (filesAreEqual)
        return true;
    else
        return false;

}

Tester::Tester()
{
    list<Directions>* directions = new list<Directions>;

    inputArgs.itemsQueue= new queue<InRecord>;
    outputArgs.itemsQueue = new queue<OutRecord>;

    inputArgs.mutexVariable = new mutex;
    outputArgs.mutexVariable = new mutex;

    inputArgs.conditionalVariable = new condition_variable;
    outputArgs.conditionalVariable = new condition_variable;

    inputArgs.sources = new list<string>;
    outputArgs.destinations = new list<string>;

    inputArgs.guids = new map<string, set<string> >;
}
