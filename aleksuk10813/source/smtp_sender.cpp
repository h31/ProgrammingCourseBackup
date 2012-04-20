#include <algorithm>

#include "senders.h"
#include "shared.h"

void SMTPSender::sendEmail(OutRecord addresses, string payload)
{
    const string from = "artem@h31.ishere.ru"; // TODO
    string login = "artem"; // TODO
    string password = "artem"; // TODO
    string receivedData;
    string encodedAuthData;
    PartsOfURL addressForConnection;
    addressForConnection.address = "localhost"; // TODO
    addressForConnection.port = 2558; // TODO

    connect_wrapper(addressForConnection);

    receivedData = receive_wrapper(); // Приветствие
    send_wrapper("EHLO somehost\r\n");
    receivedData = receive_wrapper(); // Функциональность сервера

    encodedAuthData = base64_encode_wrapper(login + '\0' + login + '\0' + password);
    // AUTH PLAIN позволяет отправлять письма от чужого имени.
    // Нам это не нужно, просто отправляем логин дважды
    send_wrapper("AUTH PLAIN " + encodedAuthData + "\r\n");
    receivedData = receive_wrapper(); // Совершен ли вход TODO: проверять

    send_wrapper("MAIL FROM:<" + from + ">\r\n"
                 "RCPT TO:<" + addresses.to + ">\r\n"
                 "DATA\r\n");
    // TODO: работает только если сервер поддерживает pipelining
    receivedData = receive_wrapper(); // Корректность адресов

    send_wrapper(payload + "\r\n.\r\n");
    receivedData = receive_wrapper(); // Корректность данных

    send_wrapper(payload + "QUIT\r\n");
    close(clientSocket);
}

string SMTPSender::generateEmail(OutRecord input)
{
    string formedEmail = "";
    formedEmail += "From: " + string("artem@h31.ishere.ru") + "\r\n"; // TODO
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
                list<string>* destinations,
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

void SMTPSender::connect_wrapper(PartsOfURL url)
{
    clientSocket = connect_helper(url);
}

string SMTPSender::receive_wrapper()
{
    return receive_helper(clientSocket);
}

void SMTPSender::send_wrapper(string data)
{
    send_helper(clientSocket, data);
}

string SMTPSender::base64_decode_wrapper(string data)
{
    return base64_decode(data);
}

string SMTPSender::base64_encode_wrapper(string data)
{
    return base64_encode(reinterpret_cast<const unsigned char*>(data.c_str() ), data.length() );

}
