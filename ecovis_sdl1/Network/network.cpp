#include "network.h"
#include <string>
using namespace std;

	TcpSocket::TcpSocket()
	{
	}

	TcpSocket::TcpSocket(TCPsocket server) // Socket for incomming connection
	{
		socket = SDLNet_TCP_Accept (server);
		if(socket)
		{
			address = *SDLNet_TCP_GetPeerAddress(socket);
			port = address.port;
			hostname = (char*)address.host;
			connected = true;
		}else{
			connected = false;
		}
	}

	TcpSocket::TcpSocket(char *myhostname, int myport): // Client socket
		hostname(myhostname),
		port(myport),
		connected(false)
	{
	}

	TcpSocket::TcpSocket(int myport): // Server socket
		hostname(NULL),
		port(myport),
		connected(false)
	{
		if (SDLNet_ResolveHost(&address, NULL, port) >= 0)
		{
			socket = SDLNet_TCP_Open (&address);
		}
	}

	TcpSocket::~TcpSocket()
	{
		disconnect();
	}

	bool TcpSocket::connect()
	{
		if (!connected && SDLNet_ResolveHost(&address, hostname, port) == 0)
		{
			socket = SDLNet_TCP_Open (&address);
			if (socket)
			{
				connected = true;
				return true;
			}
		}
		return false;
	}
	

	void TcpSocket::disconnect()
	{
		if(connected)
		{
			SDLNet_TCP_Close (socket);
			connected = false;
		}
	}

	int TcpSocket::receive(void *data, int size)
	{
		int result = 0;
		if(connected)
		{
		
			result = SDLNet_TCP_Recv(socket, data, size);
		
			if(result <= 0) connected = false;
		}
		return result;
	}

	int TcpSocket::send(void *data, int size)
	{
		int result = 0;
		if(connected)
		{
			result = SDLNet_TCP_Send(socket, data, size);
			if(result <= 0) connected = false;
		}
		return result;
	}

	bool TcpSocket::isConnected()
	{
		return connected;
	}

	TCPsocket *TcpSocket::getSocket() // returns the SDLsocket
	{
		return &socket;
	}

	UdpSocket::UdpSocket(char* hostname, int port, bool broadcast)
		throw(runtime_error):
		port(port)
	{
		//if(broadcast)
		//{
		//	address.host = INADDR_BROADCAST;
		//	address.port = port;
		//	socket = SDLNet_UDP_Open(0);
		//	
		//}
		//else
		//{
		//	//if(!hostname || SDLNet_ResolveHost(&address, hostname, port) != 0)
		//	if(!hostname || SDLNet_ResolveHost(&address, hostname, 5801) != 0)
		//	{
		//		address.host = INADDR_BROADCAST;
		//		address.port = port;
		//	}
		//	socket = SDLNet_UDP_Open(port);
		//}
		//if(!socket)
		//{
		//	string error(SDLNet_GetError());
		//	throw runtime_error("Failed to open UDPSocket: " + error);
		//}
		//if(SDLNet_UDP_Bind(socket,-1,&address)<0)
		//{
		//	string error(SDLNet_GetError());
		//	throw runtime_error("Failed to bind address: " + error);
		//}

		//if (!(packet = SDLNet_AllocPacket(4096)))
		//{
		//	string error(SDLNet_GetError());
		//	throw runtime_error("Failed to setup packet: " + error);
		//}
	}

	UdpSocket::~UdpSocket()
	{
		SDLNet_UDP_Close(socket);
		SDLNet_FreePacket(packet);

	}

	int UdpSocket::receive(void *data, int size)
	{
		int result = SDLNet_UDP_Recv(socket, packet);
		if( result < 0)
		{
			string error(SDLNet_GetError());
			throw runtime_error("Failed to receive UDPPacket: " + error);
		}
		if(result > 0)
		{
			memcpy(data, packet->data, packet->len);
			return packet->len;
		}
		return 0;
	}

	int UdpSocket::send(void *data, int size)
	{
		memcpy(packet->data, data, size);
		packet->len = size;
		int result =  SDLNet_UDP_Send(socket, 0, packet);
		if(result > 0){
			result = size;
		}
		return result;
	}

	UDPsocket *UdpSocket::getSocket() // returns the SDLsocket
	{
		return &socket;
	}

	SocketSet::SocketSet(int size):
		set(SDLNet_AllocSocketSet(size)),
		size(size)
	{
		if(!set) {
			printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
			exit(1); //most of the time this is a major error, but do what you want.
		}
	}

	SocketSet::~SocketSet(){
		SDLNet_FreeSocketSet(set);
	}

	void SocketSet::add(TcpSocket &sock){
		if(SDLNet_TCP_AddSocket(set,*(sock.getSocket()))==-1) {
			printf("SDLNet_AddSocket: %s\n", SDLNet_GetError());
		}
	}

	void SocketSet::add(UdpSocket &sock){
		/*if(SDLNet_UDP_AddSocket(set,*(sock.getSocket()))==-1) {
			printf("SDLNet_AddSocket: %s\n", SDLNet_GetError());*/
		/*}*/
	}

	void SocketSet::del(TcpSocket &sock){
		if(SDLNet_TCP_DelSocket(set, *(sock.getSocket())) == -1) {
		    printf("SDLNet_DelSocket: %s\n", SDLNet_GetError());
		}
	}

	void SocketSet::del(UdpSocket &sock){
		/*if(SDLNet_UDP_DelSocket(set,sock.getSocket())==-1) {
		    printf("SDLNet_DelSocket: %s\n", SDLNet_GetError());*/
		/*}*/
	}

	int SocketSet::check(int timeout)
	{
		int numready=SDLNet_CheckSockets(set, timeout);
		if(numready==-1) {
			printf("SDLNet_CheckSockets: %s\n", SDLNet_GetError());
			perror("SDLNet_CheckSockets");
		}
		return numready;
	}

	bool SocketSet::isReady(TcpSocket &sock)
	{
	    return SDLNet_SocketReady(sock.getSocket());
	}

	bool SocketSet::isReady(UdpSocket &sock)
	{
	    return SDLNet_SocketReady(sock.getSocket());
	}

