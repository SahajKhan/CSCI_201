#pragma once
#include <iostream>
#include <string>
#include <boost/array.hpp>  //header and source
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

//create SocketClosed - inherit from exception
class SocketClosedException : public std::exception
{
public:
	//	SocketClosedException(const string message = "Socket Closed") : exception(message);
	const char* what() const throw ()
	{
		return "Socket Closed!!!";
	}
};


class MySocket {
private:
	size_t len;
	//boost::array<char, 128> buf;  
	boost::system::error_code error;
	tcp::socket* sock;
	boost::asio::io_service io_service;
	tcp::acceptor* acceptor;
public:
	MySocket() {
		sock = new tcp::socket(io_service);
	}
	~MySocket() {
		sock->close();
	}
	void bind(unsigned int port) {
		acceptor = new tcp::acceptor(io_service, tcp::endpoint(tcp::v4(), port));  // defaults to loopback (127.0.0.1)
	}
	void accept() {
		acceptor->accept(*sock);
	}
	void connect(string port, string host = "localhost") {
		tcp::resolver resolver(io_service);
		tcp::resolver::query query(host, port);  //localhost is a loopback 127.0.0.1, port = port used 
		tcp::resolver::iterator host_iterator = resolver.resolve(query);
		boost::asio::connect(*sock, host_iterator);
	}
	void write(string message) {
		boost::asio::write(*sock, boost::asio::buffer(message));
		if (error == boost::asio::error::eof)
			throw SocketClosedException(); // Connection closed cleanly by peer.
		else if (error)
			throw boost::system::system_error(error);
	}
	string read() {
		string message = "";
		boost::array<char, 128> buf;
		do {
			len = sock->read_some(boost::asio::buffer(buf), error);
			if (error == boost::asio::error::eof) {
				throw SocketClosedException(); // Connection closed cleanly by peer.
			}
			else if (error) {
				throw boost::system::system_error(error);
			}
			message += string(buf.begin(), len);
		} while (available());  //break on white space
		return message;
	}
	int available() {
		return sock->available(); //returns number of bytes readable
	}
	void close() {
		sock->close();
	}
};
