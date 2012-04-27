#include <algorithm>

#include "senders.h"
#include "shared.h"

void SMTPSender::sendEmail(OutRecord addresses, string payload)
{
    const string from = "aaa@h31.ishere.ru"; // TODO
    string login = "artem"; // TODO
    string password = "artem"; // TODO
    string encodedAuthData;
    PartsOfURL addressForConnection;
    addressForConnection.address = "localhost"; // TODO
    addressForConnection.port = 25; // TODO

    connect_wrapper(addressForConnection);

    receive_wrapper(); // Приветствие
    send_command("EHLO somehost\r\n");

    encodedAuthData = base64_encode_wrapper(login + '\0' + login + '\0' + password);
    // AUTH PLAIN позволяет отправлять письма от чужого имени.
    // Нам это не нужно, просто отправляем логин дважды
    send_command("AUTH PLAIN " + encodedAuthData + "\r\n");

    send_command("MAIL FROM:<" + from + ">\r\n");
    send_command("RCPT TO:<" + addresses.to + ">\r\n");
    send_command("DATA\r\n");

    send_command(payload + "\r\n.\r\n");

    send_command("QUIT\r\n");
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

void SMTPSender::operator()(SenderArgs args)
{
    while (1)
    {
        string formedEmail;

        // чтобы подолгу не блокировать очередь, сразу получаем из неё все элементы.
        unique_lock<mutex> lk(*args.mutexVariable);
        args.conditionalVariable->wait(lk);
            queue<OutRecord>* items = new queue<OutRecord>;
            swap(args.itemsQueue, items);
        lk.unlock();

        while (items->size() > 0)
        {
            OutRecord currentItem = items->front();
            items->pop();

            if (!addressesCorrectness(currentItem) )
                throw AddressCorrectnessException();
            formedEmail = generateEmail(currentItem);
            sendEmail(currentItem, formedEmail);
        }
    }
}

void SMTPSender::connect_wrapper(PartsOfURL url)
{
    clientSocket = connect_helper(url);
}

string SMTPSender::receive_wrapper()
{
    string request = "";
    int recvStatus;
    char buf[1280];

    do {
        recvStatus = recv(clientSocket, buf, sizeof(buf), 0);
        request.append(buf, recvStatus);
        // TODO: проверка на зависание
        int i = request.find('\n');
    } while (request.find('\n') == string::npos);
    // delete uf; // TODO
    //recvStatus == sizeof(buf)  Если значение меньше sizeof(buf), то все данные уже получены, иначе нужно продолжать
    return request;
}

int SMTPSender::send_command(string data)
{
    send_helper(clientSocket, data);
    string receivedData = receive_wrapper();
    return receivedData[0] - '0';
}

string SMTPSender::base64_decode_wrapper(string data)
{
    return base64_decode(data);
}

string SMTPSender::base64_encode_wrapper(string data)
{
    return base64_encode(reinterpret_cast<const unsigned char*>(data.c_str() ), data.length() );

}