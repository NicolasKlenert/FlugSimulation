/*
 * NetworkHandler.h
 *
 *  Created on: Jan 20, 2009
 *      Author: st
 */

#ifndef NETWORKHANDLER_H_
#define NETWORKHANDLER_H_

#undef UNICODE
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "../Network/network.h"

#include "UDP.h"
#include "TCPIP.h"
#include "labels.h"

#define TCP_PORT 6700
#define UDP_PORT 5805
#define TCP_C_PORT 23    //CLIENT PORT FOR TCP BASED COMMUNICATION WITH SIMULATOR PERIPHERY SERVER DEVICES

class NetworkHandler {
public:
	NetworkHandler(char* hostAddr, char* hostAddrUDP_BC);
	virtual ~NetworkHandler();
	void process();
	void run();
	
	void processUdp();
	int processTcp();

	void setHandlers(TCPIP *TCPhandler,	CUDP *UDPhandler);
	bool quit;
	TcpSocket tcp;

	TCPIP *TCPhandler;
	UdpSocket udp;
	//TCPIP *TCPhandler;
	CUDP *UDPhandler;

protected:
	SocketSet sockets;

	int TransmitterTimer;
	

};

#endif /* NETWORKHANDLER_H_ */
