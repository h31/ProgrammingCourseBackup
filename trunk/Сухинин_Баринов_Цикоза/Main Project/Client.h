#ifndef _CLIENT_
#define _CLIENT_

#define _WINSOCKAPI_    // stops windows.h including winsock.h
#include <windows.h>
#include <conio.h>
#include "include\enet\enet.h"
#include <boost\thread.hpp>
#include <boost\timer.hpp>
using namespace boost;

class Client
{
public:
	ENetEvent event;
    ENetHost * h_client;
    ENetAddress address;
	ENetPeer * p_server;
	//������
	thread thread_handler;//��������� 
	thread thread_input;
	thread thread_output;
	mutex //����������
		mut_Handler,
		mut_Input,
		mut_Output;
	bool Handler_stop,Input_stop,Output_stop;//����� ��������� �������
	void InputLoop();//������� �������� ������
	void HandlerLoop();//������� ������ ��������� ���������
	void OutputLoop(float ms);//������� ������ �������� ���������
public:
	bool Disconnect();
	bool Init();//������������� ������� (����)
	bool ShutDown();//��������� ������� (����)
	bool Connect(char*);
	void SendPacket(ENetPeer*,void*,unsigned short,ENetPacketFlag);
	void Start()//������ �������
	{
		thread_input =thread(&Client::InputLoop,this);
		thread_handler = thread(&Client::HandlerLoop,this);
		thread_output=thread(&Client::OutputLoop,this,50);
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
	Client()
	{
		h_client=0;
		p_server=0;
		this->Handler_stop=false;
		this->Input_stop=false;
		this->Output_stop=false;
	}
	~Client()
	{
		this->ShutDown();
		enet_host_destroy(h_client);
	}
	
};



#endif