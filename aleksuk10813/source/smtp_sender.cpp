#include <algorithm>
#include <string.h>

#include "senders.h"
#include "shared.h"

void SMTPSender::operator()(SenderArgs args)
{
    while (1)
    {
        string formedEmail;
        smtpSettings = args.smtpSettings;
        from = smtpSettings->username + "@" + smtpSettings->server;

        unique_lock<mutex> lk(*args.mutexVariable);
        // Если очередь пустая, то ждем наполнения
        if (args.itemsQueue->size() == 0)
            args.conditionalVariable->wait(lk);

        while (args.itemsQueue->size() > 0)
        {
            OutRecord currentItem = args.itemsQueue->front();

            if (currentItem.senderProtocol != "smtp")
                break;
            try
            {
                formedEmail = generateEmail(currentItem);
                sendEmail(currentItem, formedEmail);
            }
            catch(...)
            {
                log(ERROR, string("Problems in SMTPSender with e-mail to " + currentItem.to) );
            }
            args.itemsQueue->pop();
        }

        lk.unlock();
    }
}

void SMTPSender::sendEmail(OutRecord addresses, string payload)
{
    string encodedAuthData;
    PartsOfURL addressForConnection;
    addressForConnection.address = smtpSettings->server;
    addressForConnection.port = 25;

    connect_wrapper(addressForConnection);

    receive_wrapper(); // Приветствие
    send_command("EHLO somehost\r\n");

    encodedAuthData = base64_encode_wrapper(smtpSettings->username + '\0'
                                            + smtpSettings->username + '\0'
                                            + smtpSettings->password);
    // AUTH PLAIN позволяет отправлять письма от чужого имени (???).
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
    formedEmail += "From: " + from + "\r\n";
    formedEmail += "To: " + input.to + "\r\n";
    formedEmail += "Subject: " + input.subject + "\r\n";
    formedEmail += "\r\n";
    formedEmail += escapeDots(input.text);
    return formedEmail;
}

string SMTPSender::escapeDots(const string input_data)
{
    string data(input_data);
    size_t currentPosition = 0;
    while ( (currentPosition = data.find("\r\n.", currentPosition) ) != string::npos &&
           data[currentPosition + strlen("\r\n.")] != '.')
        data.insert(currentPosition + strlen("\r\n."), ".");
    return data;
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
    return request;
}

void SMTPSender::send_command(string data)
{
    send_helper(clientSocket, data);
    string receivedData = receive_wrapper();
    if (receivedData[0] == '4' || receivedData[0] == '5')
        throw SMTPSenderException(ERROR, string("SMTP error: " + receivedData) );
}

string SMTPSender::base64_decode_wrapper(string data)
{
    return base64_decode(data);
}

string SMTPSender::base64_encode_wrapper(string data)
{
    return base64_encode(reinterpret_cast<const unsigned char*>(data.c_str() ), data.length() );

}
