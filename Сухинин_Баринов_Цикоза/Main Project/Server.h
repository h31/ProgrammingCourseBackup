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
	//������
	thread thread_handler;
	thread thread_input;
	thread thread_output;
	mutex //����������
		mut_Handler,
		mut_Input,
		mut_Output;
	bool Handler_stop,Input_stop,Output_stop;//����� ��������� �������
	bool Init();//������������� ������� (����)
	bool ShutDown();//��������� ������� (����)
	void AddUser();//�������� ������������
	void DisconnectUser(User *);//��������� ������������
	void SendPacket();
	void InputLoop();//������� �������� ������
	void HandlerLoop();//������� ������ ��������� ���������
	void OutputLoop(float ms);//������� ������ �������� ���������
public:
	
	Server()
	{
		
		serverdata=new ServerData();
		this->Handler_stop=false;
		this->Input_stop=false;
		this->Output_stop=false;

	}
	void Start()//������ �������
	{
		thread_input =thread(&Server::InputLoop,this);
		thread_handler = thread(&Server::HandlerLoop,this);
		thread_output=thread(&Server::OutputLoop,this,50);
	}
	void Stop()//��������� �������
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