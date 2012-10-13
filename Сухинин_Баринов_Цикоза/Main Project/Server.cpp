#include "Server.h"

bool Server::Init()
{
	
	if (enet_initialize () != 0)
    {
		MessageBox(NULL,"", "Error while itializing enet server", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
        return false;
    }
    atexit (enet_deinitialize);

    
        /* Bind the server to the default localhost.     */
        /* A specific host address can be specified by   */
        /* enet_address_set_host (& address, "x.x.x.x"); */
		address.host = ENET_HOST_ANY;
        address.port = 1234;
		//enet_address_set_host(& address,"127.0.0.1");
        //address.host = ENET_HOST_ANY;
			server = enet_host_create (&address, // the address to bind the server host to 
                                          32,   // allow only 1 client and/or outgoing connections
                                          2,   
                                          0,	// assume any amount of incoming bandwidth
										  0);  // assume any amount of outgoing bandwidth
            if (server == NULL) 
			{
				MessageBox(NULL,"", "Error while creating enet server", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
				return false;
            }        
     
	return true;
}
void Server::SendPacket(ENetPeer *peer,void* pack,unsigned short len,ENetPacketFlag flag)
{
	/* Create a reliable packet of size 7 containing "packet\0" */
    ENetPacket * packet = enet_packet_create ((void*)pack,len + 1,flag);

    /* Send the packet to the peer over channel id 0. */
    /* One could also broadcast the packet by         */
    /* enet_host_broadcast (host, 0, packet);         */
    enet_peer_send (peer, 0, packet);
   
	enet_packet_destroy(packet);
}
bool Server::ShutDown()
{
	for(list<User*>::iterator it=Userlist.begin();it!=Userlist.end();it++)
	{
		enet_peer_disconnect ((*it)->peer, 0);
	}
	
    /* Allow up to 3 seconds for the disconnect to succeed
       and drop any packets received packets.
     */
	while (enet_host_service (server, & event, 5000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            enet_packet_destroy (event.packet);
            break;
        case ENET_EVENT_TYPE_DISCONNECT:
			break;
            //puts ("Disconnection succeeded.");
            //return;
        }
    }
    /* We've arrived here, so the disconnect attempt didn't */
    /* succeed yet.  Force the connection down.             */
	 for(list<User*>::iterator it=Userlist.begin();it!=Userlist.end();it++)
	{
		enet_peer_reset ((*it)->peer);
	}
    return true;
}
void Server::AddUser()
{
	User* user=new User();
	this->Userlist.push_back(user);
}
void Server::DisconnectUser(User * user)
{
	if (Userlist.empty())return;
	for(list<User*>::iterator it=Userlist.begin();it!=Userlist.end();)
	{
		if ((*it)->peer->connectID==user->peer->connectID)
		{
			enet_peer_disconnect (user->peer, 0);
			while (enet_host_service (server, & event, 2000) > 0)
			{
				switch (event.type)
				{
				case ENET_EVENT_TYPE_RECEIVE:
					enet_packet_destroy (event.packet);
					break;
				case ENET_EVENT_TYPE_DISCONNECT:
					//puts ("Disconnection succeeded.");
					//return;
					break;
				}
				enet_peer_reset (user->peer);
			}
			delete (*it);
			it=Userlist.erase(it);
			return;
		}
		it++;
	}
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