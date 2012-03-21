#include <tests.h>

string TestRSSReceiver::downloadSource(const string url)
{
    return set[0];
}

void runTest( bool (*test)(),
              const char *name = "" )
{
    cout << name << ": ";
    if (true == test() )
        cout << "Ok";
    else
        cout << "FAILED";
    cout << endl;
}
void testSequence() {
    runTest(test1, "test1 (Ошибки HTTP №1)");
    runTest(test2, "test2 (Ошибки HTTP №2)");
}

bool test1()
{
    TestRSSReceiver testObj;
    testObj.addSource("dcrfcxfdrcxrfgc");
    try
    {
        testObj();
        return false;
    }
    catch (HTTPException)
        return true;
}

bool test1()
{
    TestRSSReceiver testObj;
    testObj.addSource("HTTP/1.1 500 Bad Gateway");
    try
    {
        testObj();
        return false;
    }
    catch (HTTPException)
        return true;
}
