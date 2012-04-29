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

void TestSender::operator()(SenderArgs args)
{
    while (1)
    {
        unique_lock<mutex> outLock(*args.mutexVariable);
        // Если очередь пустая, то ждем наполнения
        if (args.itemsQueue->size() == 0)
            args.conditionalVariable->wait(outLock);

        while (args.itemsQueue->size() > 0)
        {
            OutRecord temp = args.itemsQueue->front();
            if (temp.senderProtocol != "test")
                break;
            cout << "Queue size: " << args.itemsQueue->size() << endl;
            cout << "Subject: " << mingwCodepageFix(temp.subject) << endl;
            cout << "To: " << mingwCodepageFix(temp.to) << endl;
            cout << "Text: " << mingwCodepageFix(temp.text) << endl;
            cout << endl;
            args.itemsQueue->pop();
        }
        outLock.unlock();
    }
}
