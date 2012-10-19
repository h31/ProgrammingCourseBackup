#include "Client.h"


void Client::HandlerLoop()
{
	bool stop=false;
	Message * current;
	while (!stop)
	{
		mut_Handler.lock();
		stop= this->Handler_stop;
		mut_Handler.unlock();
		mut_queue_in.lock();
		if (!this->queue_in.empty())
		{
			current=this->queue_in.back();
			//delete current;
			this->queue_in.pop();
			//delete current;
		}
		mut_queue_in.unlock();
		
	}
}
void Client::LoopOut()
{
	bool stop=false;
	timer t;t.restart();
	stringstream ss (stringstream::in | stringstream::out);
	while (!stop)
	{
		t.restart();
		mut_Out.lock();
		stop= this->Out_stop;
		mut_Out.unlock();
		////////////
		this->mut_queue_out.lock();
		if (!this->queue_out.empty())
		{

		}
		else
		{
			mut_Data.lock();
			int x=data->My_tank->position.x,y=data->My_tank->position.y;
			mut_Data.unlock();
			ss<<x<<" "<<y;

			char*temp_= new char[20];
			ss.getline(temp_, 10);
			string temp=(const char*)temp_;
			delete temp_;
			ss.clear();
			boost::shared_ptr<std::string> message(
          new std::string(temp));
			this->start_send(message);
			
		}
		this->mut_queue_out.unlock(); 
		////////////
		double dt=50-t.elapsed();
		if (dt>0)
		Sleep(dt);	
	}
}
void Client::LoopIn()
{
	bool stop=false;
	stringstream ss (stringstream::in | stringstream::out);
	while (!stop)
	{
		mut_In.lock();
		stop= this->In_stop;
		mut_In.unlock();
		////////////
		this->mut_queue_in.lock();
		Message* m =new Message();
		//if (!queue_in.empty())
		//{
		this->start_receive(m);
		this->queue_in.push(m);
		//}
		this->mut_queue_in.unlock(); 
		
		////////////
		//Sleep(100);
	}
		
}
void Client::Handle_send(unsigned int ms)//some sort of timer working every ms msec
{
	
	double dt=50-ms;
	if (dt>0)
	Sleep(dt);
	
}
void Client::start_send(boost::shared_ptr<std::string> message)
	{
		socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
			boost::bind(&Client::handle_send, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
		
	}
void Client::start_receive(Message * message)
  {
	  //Message * mes=new Message();
	  //this->incoming=mes;
    socket_.async_receive_from(
		boost::asio::buffer(message->data), remote_endpoint_,
		boost::bind(&Client::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
  }
void Client::start_receive(void* storage,unsigned short len)
  {
    socket_.async_receive_from(
        boost::asio::buffer(storage,len), remote_endpoint_,
		boost::bind(&Client::handle_receive, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }
void Client::handle_send(boost::shared_ptr<std::string> /*message*/,const boost::system::error_code& /*error*/,std::size_t /*bytes_transferred*/)
{
}
void Client::handle_send()
{
}
void Client::handle_receive(const boost::system::error_code& error,std::size_t /*bytes_transferred*/)
{	
}
void Client::Stop()//остановка потоков
	{
		mut_Handler.lock();
		this->Handler_stop=true;
		mut_Handler.unlock();

		mut_In.lock();
		this->In_stop=true;
		mut_In.unlock();

		mut_Out.lock();
		this->Out_stop=true;
		mut_Out.unlock();

		thread_out.join();
		thread_in.join();
		thread_handler.join();
	}