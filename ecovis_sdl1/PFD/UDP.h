//------------------------------------------------------------------------------
//Filename       UDP.h
//System
//Author         Christian Berth
//Date           14,12,02
//Description    A330 FSIM UDP Header
//------------------------------------------------------------------------------
// Link with ws2_32.lib
#pragma comment(lib, "ws2_32.lib")
#ifndef _UDP_H_
#define _UDP_H_

#include "../Network/network.h"
#include "Structs1.h"
#include <stdio.h>      // For printf, scanf, and sprintf


#include <winsock2.h>   // For using WinSock

// Server
#define C_MAXLENGTH     8192 //4096
#define S_MAXLENGTH     4096 //FIXME buffer overflow possible

//cb2014
#define S_PORT          5805
#define S_WSVERSION     0x101

#define DESTINATION_ADDRESS "10.0.6.1"
#define DESTINATION_PORT    5801
#define RECEIVE_PORT        5805

#define DESTINATION_ADDRESS_FDC "10.0.6.255"
#define DESTINATION_PORT_FDC    5809
#define RECEIVE_PORT_FDC        5808
// cb2014


class CUDP
{
public:
	CUDP(bool aares);
    //~CUDP();
    sUDP_Struct UDP_Struct;
    bool Reciever(UdpSocket &server);
    bool Transmitter(UdpSocket &server);

	bool Transmitter_FDC();
	int Init_FDC();

	bool RecieverW();
    bool TransmitterW();
    int  InitW();

    int itest;

protected:
    // Variables
	// cb2014
    sockaddr_in sin;
    sockaddr_in sout;
	sockaddr_in sinFDC;
    sockaddr_in soutFDC;
    SOCKET s;
	SOCKET sFDC;
 
	// cb2014


    bool aares;
    unsigned short udp_send_bytes;
    char cBufferR[C_MAXLENGTH];
    char cBufferT[C_MAXLENGTH];

    //Function
    void ProcessData(char *buffer);
    void generate_packet(void);
	void generate_packet_FDC(void);
    void insert_command_id_in_buffer (unsigned short command_id);
    void insert_datasize_in_buffer(unsigned char datasize);
	void insert_datasize_in_buffer_FDC(unsigned char datasize);

    //TransmiterFunction
	void generate_EFCS_data(void);
    void generate_FDC_data(void);
    void generate_aileron_position_data(void);
    void generate_elevator_position_data(void);
    void generate_rudder_position_data(void);
    void generate_spoiler_data(void);
    void generate_scontrol_data(void);
    void generate_comnav_data(void);
    void generate_fcureq_data(void);
    void generate_fcuset_data(void);
    void generate_sim_data(void);
    void generate_EngineControl_data(void);
};

#endif
