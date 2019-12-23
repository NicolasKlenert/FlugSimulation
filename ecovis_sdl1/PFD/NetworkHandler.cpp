/*
 * NetworkHandler.cpp
 *
 *  Created on: Jan 20, 2009
 *      Author: st
 */

#include "NetworkHandler.h"
#include <assert.h>

extern bool A330_TCP_COM_Active;
extern bool A330_UDP_COM_Active;


NetworkHandler::NetworkHandler(char* hostAddr, char* hostAddrUDP_BC):
	quit(false),
	sockets(4),
	tcp(hostAddr, TCP_PORT),
	udp(hostAddrUDP_BC, 5805) //udp(hostAddr, UDP_PORT)  //cb2014
{
	//UDPhandler->InitW();
	//Host TCP Comm (Threaded)
	tcp.connect();

	sockets.add(udp);

	TransmitterTimer = 0;
}

NetworkHandler::~NetworkHandler() {
	if(tcp.isConnected()) tcp.disconnect();

}

void NetworkHandler::process(){   //DEAD

	int result = sockets.check(0);
	if(result == -1)
	{
		exit(1);
		//TODO
	}

	if(result > 0)
	{
		//TCP Connection to SIM HOST
		if(sockets.isReady(tcp)) 
		{
			TCPhandler->Reciever(tcp);
			UDPhandler->RecieverW();

		}
	
		//UDP Connection to SIM HOST
		//if(sockets.isReady(udp))
		//{
		//	UDPhandler->Reciever(udp);
		//	
		//	//UDPhandler->Transmitter(udp);
		//}
	}
}

void NetworkHandler::run()  //
{

	//int ret;

	////init answer to establish connection
	////ret = TcpClientHandler->TCPClient_Init(tcp_c);

	//while(!quit)
	//{
	//	int result = sockets.check(-1);
	//	
	//	if(result == -1)
	//		{
	//			quit = true;
	//		}
			
			/*if(result > 0 && sockets.isReady(tcp_c))
			{	
					ret = TcpClientHandler->TCPClient_Receiver(tcp_c, "10.0.6.20");
					if(ret < 0)
					{
						quit = true;
						return;
					}
			}*/
			
		//cb2014
			UDPhandler->RecieverW();
			//UDPhandler->TransmitterW();

			/*if(sockets.isReady(udp))
			{
				UDPhandler->Reciever(udp);
				UDPhandler->Transmitter(udp);
			}*/
		//cb2014
		//}
}

void NetworkHandler::processUdp()
{
	//UDPhandler->Transmitter(udp);
	UDPhandler->RecieverW();
	UDPhandler->TransmitterW();
}
//Threaded
int NetworkHandler::processTcp()
{
		
	return TCPhandler->Reciever(tcp);
	
}


void NetworkHandler::setHandlers(TCPIP *TCPhandler,	CUDP *UDPhandler){
	this->TCPhandler = TCPhandler;
	this->UDPhandler = UDPhandler;
	
	defineLabels(*TCPhandler);
	char cmd[128];
	sprintf(cmd, "binary\nmcdu %d on\n", 1);   //TODO FIX MCDU NR HARDWIRED !!!
	if(tcp.send(cmd, (int) strlen(cmd) + 1) > 0)
	{
		printf("NetworkHandler: not connected\n");
	}
	TCPhandler->InitLabel(tcp);
	TCPhandler->Transmitter(tcp);
	/*Sleep(20);
	TCPhandler->Reciever(tcp);*/
}
