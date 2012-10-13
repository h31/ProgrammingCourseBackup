#ifndef _SERVER_
#define _SERVER_

#define _WINSOCKAPI_    // stops windows.h including winsock.h
//#include <windows.h>
#include "ServerData.h"
#include "include\enet\enet.h"
#include <list>
#include <conio.h>
#include <boost\thread.hpp>
#include <boost\timer.hpp>
using namespace std;
using namespace boost;

class User
{
public:
	ENetPeer * peer;
	User(){peer=0;}
};

class Server
{
private:
	ENetEvent event;
    ENetHost * server;
    ENetAddress address;
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
	void SendPacket(ENetPeer*,void*,unsigned short,ENetPacketFlag);
	void InputLoop();//������� �������� ������
	void HandlerLoop();//������� ������ ��������� ���������
	void OutputLoop(float ms);//������� ������ �������� ���������
public:
	
	Server()
	{
		server=0;
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
	~Server(){ delete serverdata; this->ShutDown(); enet_host_destroy(server);}
	
};



#endif