#ifndef SENDERS_H
#define SENDERS_H

#include <string>
#include "receivers.h"
#include "tests.h"
#include <queue>
#include <set>
#include <condition_variable>
#include "3rdparty/base64.h"



using namespace std;

class SMTPSender
{
public:
    void operator()(SenderArgs args);
// protected: // TODO: Решить
    int clientSocket;
    SMTPSettings* smtpSettings;
    static const char* unitName;

    string generateEmail(OutRecord input);
    void sendEmail(OutRecord addresses, string payload);
    void establishClientSocket();
    string escapeDots(const string data);

    void connect_wrapper(PartsOfURL url);
    string receive_wrapper();
    int send_command(string data);
    string base64_encode_wrapper(string data);
    string base64_decode_wrapper(string data);

    friend class Tester;
};

class TestSender
{
public:
    void operator ()(SenderArgs args);
};

#endif // SENDERS_H
