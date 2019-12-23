//------------------------------------------------------------------------------
//Filename       TCPIP.h
//System         WinXp 32
//Author         Christian Berth
//Date           01/05/05
//Description    aares TCP Header
//Remarks        Array Support added 09/04/06 by Richard Wollenheit
//------------------------------------------------------------------------------

#ifndef _TCPIP_H_
#define _TCPIP_H_

#include <stdio.h>
#include "../Network/network.h"
#include <string.h>
#include <string>
#include <vector>
using namespace std;
#include <winsock2.h>
#include <windows.h>

#define LabelCount 512				//Maximalanzahl der Labels
#define ArrayCount 512	//FIXME Dringend! wer baut sowas?			//Maximalanzahl der Array-Labels

// Client
typedef struct
{
	char status; /*0 = Off, 1 = On*/
	char nr; /*1-3*/

	char text[336];
	char color[336];
	char size[336];
}
#ifdef __GNUC__
__attribute__((packed))
#endif
MCDU_Data;

//FIXME 1Byte Struct alignment nesseary
class TCPIP
{
public:
	TCPIP(bool aares);
	~TCPIP(void);

	int InitLabel(TcpSocket &server);
	int Reciever(TcpSocket &server);
	int Transmitter(TcpSocket &server);
	int Get_Value(char *data, int size);
	int Get_MCDU_Value(unsigned short readpos);
	int Get_Array(char *data, int size);
	int Get_Array_Element(char *data, int size);
	int Set_Value(TcpSocket &server, string Label,float fValue);
	int iLCounter;

	struct sLabel
	{
		char szLabel[64];
		char cType;
		union
		{
			short int	siVal; //added 09/04/06 R.W.
			int			iVal;
			float		fVal;
			double		dVal;
			char		cVal;
		} v;

	}sLabelS[LabelCount];

	char Label[LabelCount][32];

	//added for Array Support
	struct sArrayInfo
	{
		char Label[16];
		char levelofdimensions;
		int dim1;
		int dim2;
		int dim3;
		int dim4;
		int dim5;
		int dataSize;
		union
		{
			char *cVal;
			short int *siVal; //added 19/07/06 R.W.
			int *iVal;
			float *fVal;
			double *dVal;
		} ptoArray;
	}ArrayS[ArrayCount];

	char ArrayLabel[ArrayCount][32];
	int iALCounter;

	MCDU_Data mcdu_data[3];


protected :

	bool aares;
	SOCKET s;
	string LabelS;
	string TransmitterL;
	bool Check_ID(int bytesRecv);

};

#endif
