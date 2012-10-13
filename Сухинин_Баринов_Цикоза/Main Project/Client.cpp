#include "Client.h"

bool Client::Init()
{
	
	if (enet_initialize () != 0)
    {
		MessageBox(NULL,"", "Error while itializing enet client", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
        return false;
    }
    atexit (enet_deinitialize);

    
        /* Bind the server to the default localhost.     */
        /* A specific host address can be specified by   */
        /* enet_address_set_host (& address, "x.x.x.x"); */
		//enet_address_set_host(& address,"127.0.0.1");
        //address.host = ENET_HOST_ANY;
			h_client = enet_host_create (NULL, 
                                          1,  
                                          2,   
                                          0 ,	
										  0);  
            if (!h_client) {
				MessageBox(NULL,"", "Error while creating enet client", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
				return false;
            }        
     
	return true;
}
bool Client::ShutDown()
{
	return this->Disconnect();
}
bool Client::Connect(char* destpoint)
{
	enet_address_set_host (& address, "");
    address.port = 1234;
    /* Initiate the connection, allocating the two channels 0 and 1. */
	p_server = enet_host_connect (h_client, & address, 2, 0);    
    
    if (p_server == NULL)
    {
               
    }
    
    /* Wait up to 5 seconds for the connection attempt to succeed. */
    while (enet_host_service (h_client, & event, 5000) > 0 &&
        event.type != ENET_EVENT_TYPE_CONNECT)
    //{
	return true;
}
bool Client::Disconnect()
{
	enet_peer_disconnect (p_server, 0);
	/* Allow up to 3 seconds for the disconnect to succeed
       and drop any packets received packets.
     */
	while (enet_host_service (h_client, & event, 3000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            enet_packet_destroy (event.packet);
            break;
        case ENET_EVENT_TYPE_DISCONNECT:
			//break;
            //puts ("Disconnection succeeded.");
            return true;
        }
    }
    /* We've arrived here, so the disconnect attempt didn't */
    /* succeed yet.  Force the connection down.             */
	enet_peer_reset (p_server);
	
	return true;
}
void Client::SendPacket(ENetPeer *peer,void* pack,unsigned short len,ENetPacketFlag flag)
{
	/* Create a reliable packet of size 7 containing "packet\0" */
   // ENetPacket * packet = enet_packet_create ((void*)pack,len,flag);

	 ENetPacket * packet = enet_packet_create ("test", 
                                              strlen ("test") + 1, 
                                              ENET_PACKET_FLAG_RELIABLE);
    /* Send the packet to the peer over channel id 0. */
    /* One could also broadcast the packet by         */
    /* enet_host_broadcast (host, 0, packet);         */
    enet_peer_send (peer, 0, packet);
   
	enet_packet_destroy(packet);
}
void Client::HandlerLoop()
{
	bool stop=false;

	while (!stop)
	{
	mut_Handler.lock();
	stop= this->Handler_stop;
	mut_Handler.unlock();





	}


}
void Client::InputLoop()
{
	bool stop=false;
	while (!stop)
	{
	mut_Input.lock();
	stop= this->Input_stop;
	mut_Input.unlock();





	}
}
void Client::OutputLoop(float ms)//some sort of timer working every ms msec
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