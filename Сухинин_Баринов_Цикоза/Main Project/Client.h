//сервер работает на порту 12345
//клиент 12346



#ifndef _CLIENT_
#define _CLIENT_

//#define _WINSOCKAPI_    // stops windows.h including winsock.h
//#include <windows.h>
//#include <conio.h>
//#include "include\enet\enet.h"
#include <boost\thread.hpp>
#include <boost\timer.hpp>
#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <boost\bind.hpp>
#include <boost\shared_ptr.hpp>
#include <string>
#include <queue>
#include "Data.h"
#include <sstream>
using namespace boost;
using namespace std;
using boost::asio::ip::udp;

class Message
{
public:
	/*boost::array<char, 2> header;
	void* storage;
	unsigned short len;
	boost::array<char, 100> body;*/
	Message(){this->size=0;}
	unsigned char size;
	boost::array<char,100> data;

};


class Client
{
private:
	Data *data;
	//потоки 
	thread thread_handler,//разборщик 
		thread_out,
		thread_in;
	mutex mut_Handler,mut_queue_in,mut_queue_out,mut_Out,mut_In;

	bool Handler_stop,Out_stop,In_stop;//флаги остановки потоков
	void Handle_receive();//вызывается если пакет принят//
	void LoopOut();//цикл отправки пакетов на сервер(поток)
	void LoopIn();//цикл приема(поток)
	void HandlerLoop();//функция потока обработки сообщений
	void Handle_send(unsigned int);//вызывается если пакет отправлен//
public://debug
	std::queue<Message*> queue_in,queue_out;
private:
	//udp client test
	udp::endpoint remote_endpoint_;
	//boost::array<char, 10> recv_buffer_;
	udp::socket socket_;
	void start_send(boost::shared_ptr<std::string>);
	void start_receive(Message *);
	void start_receive(void*,unsigned short);
	void handle_send();
	void handle_send(boost::shared_ptr<std::string> /*message*/,const boost::system::error_code& /*error*/,std::size_t /*bytes_transferred*/);
	void handle_receive(const boost::system::error_code& error,std::size_t /*bytes_transferred*/);
	void connect(string dest,boost::asio::io_service& io_service)
	{
		//udp::resolver resolver(io_service);
		//udp::resolver::query query( dest,"daytime");
		//remote_endpoint_ = *resolver.resolve(query);
		remote_endpoint_ = udp::endpoint(
    boost::asio::ip::address::from_string(dest), 12345);
	}
	void Stop();
	Message * incoming;//для только што принятых сообщений
public:
	
	Client(boost::asio::io_service& io_service,Data * data):socket_(io_service, 
		udp::endpoint(udp::v4(), 12346))
	{
		this->data=data;
		//udp::resolver resolver(io_service);
		//udp::resolver::query query( "127.0.0.1","daytime");
		//remote_endpoint_ = *resolver.resolve(query);
		this->connect("127.0.0.1",io_service);
		this->Out_stop=false;
		this->Handler_stop=false;
		this->In_stop=false;
		thread_out = thread(&Client::LoopOut,this);
		thread_handler = thread(&Client::HandlerLoop,this);
		//thread_in=thread(&Client::LoopIn,this);
	}
	~Client()
	{
		this->Stop();
			
	}
	
};



#endif