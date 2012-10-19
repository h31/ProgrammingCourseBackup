#ifndef _SERVER_
#define _SERVER_


#include <boost\asio.hpp>
#include "ServerData.h"

#include <list>
#include <conio.h>
#include <boost\thread.hpp>
#include <boost\timer.hpp>

using namespace std;
using namespace boost;

class User
{
public:
	
};

class Server
{
private:
	
	ServerData *serverdata;
	list <User*> Userlist;
	//потоки
	thread thread_handler;
	thread thread_input;
	thread thread_output;
	mutex //разрешения
		mut_Handler,
		mut_Input,
		mut_Output;
	bool Handler_stop,Input_stop,Output_stop;//флаги остановки потоков
	bool Init();//инициализация сервера (сети)
	bool ShutDown();//остановка сервера (сети)
	void AddUser();//добавить пользователя
	void DisconnectUser(User *);//отключить пользователя
	void SendPacket();
	void InputLoop();//функция входного потока
	void HandlerLoop();//функция потока обработки сообщений
	void OutputLoop(float ms);//функция потока отправки сообщений
public:
	
	Server()
	{
		
		serverdata=new ServerData();
		this->Handler_stop=false;
		this->Input_stop=false;
		this->Output_stop=false;

	}
	void Start()//запуск потоков
	{
		thread_input =thread(&Server::InputLoop,this);
		thread_handler = thread(&Server::HandlerLoop,this);
		thread_output=thread(&Server::OutputLoop,this,50);
	}
	void Stop()//остановка потоков
	{
		mut_Handler.lock();
		this->Handler_stop=true;
		mut_Handler.unlock();
		mut_Input.lock();
		this->Input_stop=true;
		mut_Input.unlock();
		mut_Output.lock();
		this->Output_stop=true;
		mut_Output.unlock();

		thread_input.join();
		thread_handler.join();
		thread_output.join();
	}
	~Server(){ delete serverdata; this->ShutDown();}
	
};



#endif