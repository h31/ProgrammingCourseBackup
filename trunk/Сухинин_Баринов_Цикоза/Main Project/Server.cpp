#include "Server.h"

bool Server::Init()
{
	     
     
	return true;
}
void Server::SendPacket()
{

}
bool Server::ShutDown()
{
	
    return true;
}
void Server::AddUser()
{
	User* user=new User();
	this->Userlist.push_back(user);
}
void Server::DisconnectUser(User * user)
{
	
}
void Server::HandlerLoop()
{
	bool stop=false;

	while (!stop)
	{
	mut_Handler.lock();
	stop= this->Handler_stop;
	mut_Handler.unlock();


	}


}
void Server::InputLoop()
{
	bool stop=false;


	while (!stop)
	{
	mut_Input.lock();
	stop= this->Input_stop;
	mut_Input.unlock();


	}
}
void Server::OutputLoop(float ms)//some sort of timer working every ms msec
{
	bool stop=false;
	timer t;
	
	while (!stop)
	{
		t.restart();
		mut_Output.lock();
		stop= this->Output_stop;
		mut_Output.unlock();
		//to do here



		//end to do
		double dt=ms-t.elapsed();
		if (dt>0)
		Sleep(dt);
	}
}