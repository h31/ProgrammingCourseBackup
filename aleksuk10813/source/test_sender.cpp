#include "senders.h"
#include <iostream>
#include <mutex>
#include <thread>

#ifdef __MINGW32__
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#endif

using namespace std;

string mingwCodepageFix(const string u8string)
{
#ifdef __MINGW32__
    int wcharcount = u8string.length();
    wchar_t *tempWstr = new wchar_t[wcharcount];
    char out[wcharcount];
    MultiByteToWideChar(CP_UTF8, 0, u8string.c_str(), -1, tempWstr, wcharcount);
    WideCharToMultiByte(866, 0, tempWstr, -1, out, wcharcount, NULL, NULL);
    string w(out);
    delete [] tempWstr;
#else
    string w(u8string);
#endif
    return w;
}

void TestSender::operator()(queue<OutRecord>* pipe, list<string>* destinations, condition_variable* cond, mutex* m)
{
    while (1)
    {
        unique_lock<mutex> outLock(*m);
        cond->wait(outLock);

        while (pipe->size() > 0)
        {
            cout << "Queue size: " << pipe->size() << endl;
            OutRecord temp = pipe->front();
            cout << "Subject: " << mingwCodepageFix(temp.subject) << endl;
            cout << "To: " << mingwCodepageFix(temp.to) << endl;
            cout << "Text: " << mingwCodepageFix(temp.text) << endl;
            cout << endl;
            pipe->pop();
        }
    }
}
