#include <algorithm>

#include "senders.h"
#include "shared.h"

void SMTPSender::sendEmail(OutRecord addresses, string payload)
{

}

string SMTPSender::generateEmail(OutRecord input)
{
    string formedEmail = "";
    formedEmail += "From: " + string("sender@sender.com") + "\r\n"; // TODO
    formedEmail += "To: " + input.to + "\r\n";
    formedEmail += "Subject: " + input.subject + "\r\n";
    formedEmail += "\r\n";
    formedEmail += input.text;
    return formedEmail;
}

string SMTPSender::escapeDots(const string data)
{
    return "";
}

bool SMTPSender::addressesCorrectness(OutRecord input)
{
    return true;
}

void SMTPSender::operator()(queue<OutRecord>* pipe,
                set<string>* destinations,
                condition_variable* cond,
                mutex* m)
{
    string formedEmail;

    // чтобы подолгу не блокировать очередь, сразу получаем из неё все элементы.
    unique_lock<mutex> lk(*m);
    queue<OutRecord> items(*pipe);
    lk.unlock();

    while (items.size() > 0)
    {
        OutRecord currentItem = items.front();
        items.pop();

        if (!addressesCorrectness(currentItem) )
            throw AddressCorrectnessException();
        formedEmail = generateEmail(currentItem);
        sendEmail(currentItem, formedEmail);
    }
}
