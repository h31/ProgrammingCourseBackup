//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
using namespace std;
using boost::asio::ip::udp;
#include <sstream>


std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

class udp_server
{
public:
  udp_server(boost::asio::io_service& io_service)
    : socket_(io_service, udp::endpoint(udp::v4(), 12345))
  {
	//remote_endpoint_=udp::endpoint(udp::v4(), 1234);
    start_receive();
  }

private:
  void start_receive()
  {
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), remote_endpoint_,
        boost::bind(&udp_server::handle_receive, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

  void handle_receive(const boost::system::error_code& error,
      std::size_t s/*bytes_transferred*/)
  {
	   //cout<<"got some message"<<endl;
	  system("cls");
	   cout.write(recv_buffer_.data(),s);
	   cout<<endl;
    if (!error || error == boost::asio::error::message_size)
    {
      boost::shared_ptr<std::string> message(
          new std::string(recv_buffer_.data()));
		start_send(message);
		//Sleep(1000);
      start_receive();
    }
  }

  void handle_send(boost::shared_ptr<std::string> /*message*/,
      const boost::system::error_code& /*error*/,
      std::size_t /*bytes_transferred*/)
  {
	  //cout<<"send some message"<<endl;
  }
  void start_send(boost::shared_ptr<std::string> mes)
	{
		socket_.async_send_to(boost::asio::buffer(*mes), remote_endpoint_,
		  boost::bind(&udp_server::handle_send, this, mes,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
	}

  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  boost::array<char, 50> recv_buffer_;
};

int main()
{
  try
  {
    boost::asio::io_service io_service;
    udp_server server(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}