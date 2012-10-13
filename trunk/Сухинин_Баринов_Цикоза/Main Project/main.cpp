

#include <iostream>
#include "include\boost\thread.hpp"
#include "Server_2.h"
#include "Client_2.h"
using namespace std;

void main()
{
	Server serv = Server();
	serv.Init();
	serv.Start();
	//serv.SendPacket((*serv.Userlist.begin())->peer,(void*)"1111",strlen ("1111")+1,ENET_PACKET_FLAG_RELIABLE);
	Client client = Client();
	client.Init();
	client.Connect("127.0.0.1");
	client.Start();
	
	Sleep(5000);
	serv.send();
	Sleep(5000);
	serv.Stop();
	client.Stop();

}