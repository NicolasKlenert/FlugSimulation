#ifndef NETWORK_H
#define NETWORK_H
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include <stdexcept>
using namespace std;

class TcpSocket
{
protected:
	char *hostname;
	int port;
	IPaddress address;
	TCPsocket socket;
	bool connected;

public:
	TcpSocket();

	TcpSocket(TCPsocket server); // Socket for incomming connection

	TcpSocket(char *myhostname, int myport); // Client socket

	TcpSocket(int myport); // Server socket

	virtual ~TcpSocket();

	bool connect();

	void disconnect();

	virtual int receive(void *data, int size);

	virtual int send(void *data, int size);

	bool isConnected();

	TCPsocket *getSocket(); // returns the SDLsocket
};

class UdpSocket
{
protected:
	char *hostname;
	int port;
	IPaddress address;
	UDPsocket socket;
	UDPpacket *packet;

public:
	UdpSocket(char* hostname, int port, bool broadcast = false)
		throw(runtime_error);
	virtual ~UdpSocket();

	virtual int receive(void *data, int size);

	virtual int send(void *data, int size);

	UDPsocket *getSocket(); // returns the SDLsocket
};

class SocketSet{
protected:
	SDLNet_SocketSet set;
	const int size;
public:
	SocketSet(int size);
	~SocketSet();
	void add(TcpSocket &sock);
	void add(UdpSocket &sock);
	void del(TcpSocket &sock);
	void del(UdpSocket &sock);
	int check(int timeout = -1);

	bool isReady(TcpSocket &sock);
	bool isReady(UdpSocket &sock);
};

#endif
