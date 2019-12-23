//------------------------------------------------------------------------------
//Filename       TCPIP.cpp
//System         WinXp 32
//Author         Christian Berth
//Date           01/06/05
//Description    aares TCP Function
//Remarks        modified 28/02/06 by Richard Wollenheit
//               Array Support added and modified 24/04/06 by R. Wollenheit
//               Endian Convert added and modified 11/07/06 by R. Wollenheit
//------------------------------------------------------------------------------

//set aares to false to enable endian convert for DFG extensions


#include "TCPIP.h"
#include "econv.h"
#include "assert.h"

#define SendBufferSize 4096
#define RecBufferSize 40960//16384 //FIXME Buffer overflow's are possile
//***********************************************************************************************************
// Declare and initialize variables

int command_id = 0;
int packet_size = 0;										//unsigned short
int startwriting = 0;										//position where to start writing the buffer
int bufferIndex = 0;										//current reading position in the buffer
int index = 0;												//current reading position in the buffer

int iTest = 0;

int bytesSent;
int bytesRecv = 1;
char sendbuf[SendBufferSize];
char recvbuf[RecBufferSize];

# pragma pack(1)
struct sUpdateInfo {
	char szLabel[64];
	char cType;
	union {
		short int siVal; //added 09/04/06 R.W.
		int iVal;
		float fVal;
		double dVal;
		char cVal;
	} v;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
		UpdateInfo;


//struct sMCDU_Data /* 1 */
//{
//  char cStatus; /*0 = Off, 1 = On*/
//  char cac_type; /*1-3*/
//
//  struct sMCDU_Displ
//	{
//		char cMCDU_Text[336];
//		char cMCDU_Color[336];
//		char cMCDU_Size[336];
//
//	} sMCDU_DisplS;
// 
//}
//#ifdef __GNUC__
//__attribute__((packed))
//#endif
//sMCDU_DataS[3];


# pragma pack()



TCPIP::TCPIP(bool aares):
	aares(aares) {
	iLCounter = 0;
	iALCounter = 0;

	for (int i = 0; i < LabelCount; i++) {
		sLabelS[i].v.cVal = 0;
	}

	LabelS = "";
	memset(Label, 0, sizeof(Label));
	memset(ArrayLabel, 0, sizeof(ArrayLabel));
	memset(ArrayS,0, sizeof(sArrayInfo)*ArrayCount);
	memset((char*) &recvbuf, 0, sizeof(recvbuf));
	memset((char*) &sendbuf, 0, sizeof(sendbuf));
}

TCPIP::~TCPIP(void) {
	for (int i = 0; i < iALCounter; i++) {
		free((void *) ArrayS[i].ptoArray.cVal);
	}
}
static int recv_all(TcpSocket &server, char* buffer, int len) {
	char *cur = buffer;
	int remaining = len;
	int ret;
	while(remaining > 0){
		ret = server.receive(cur, remaining);
		if(ret <= 0)
			return ret;
		remaining -= ret;
		cur += ret;
	}
	return len;
}

int TCPIP::Reciever(TcpSocket &server) {
	int32_t command;
	int32_t size;
	int ret = 0;

	if (!server.isConnected())
		return -1; //error detected

	ret = recv_all(server, (char*)&command, sizeof(command));
	if(ret <= 0)
		return ret ? ret : -1;
	if (!aares)
		EndianConvert((char*)&command, 4);

	ret = recv_all(server, (char*)&size, sizeof(size));
	if(ret <= 0)
		return ret ? ret : -1;
	if (!aares)
		EndianConvert((char*)&size, 4);

	assert(size <= sizeof(recvbuf));

	ret = recv_all(server, recvbuf, size);
	if(ret <= 0)
		return ret ? ret : -1;

	switch(command){
		case 500: //MCDU Text
			{
				assert(sizeof(MCDU_Data) == size);
				char ac_type = recvbuf[1];

				assert(ac_type < 4 && ac_type > 0);
				memcpy((void *)&mcdu_data[ac_type -1], recvbuf, sizeof(MCDU_Data));
			}
			break;
					
		case 10://Single-Element Labels
			//Get_Value(bufferIndex)
			Get_Value(recvbuf, size);
			break;
		
		case 12: //Array-Labels (full update)
			Get_Array(recvbuf, size);
			break;
		case 13: //Array-Labels (differential update)
			Get_Array_Element(recvbuf, size);
			break;
		default:
			break;
	}
	return 0;
}

int TCPIP::Transmitter(TcpSocket &server) {
	int iSendVal = 0;

	strcpy(sendbuf, "binary\n");
	iSendVal = server.send(sendbuf, (int) strlen(sendbuf));

	memset((char*) &sendbuf, 0, sizeof(sendbuf));

	return iSendVal;
}


//***********************************************************************************************************
// Get changed label values
int TCPIP::Get_Value(char *data, int size) {
	LabelS = "";
	//assert(size >= sizeof(sUpdateInfo));
	memcpy((void *) &UpdateInfo, data, sizeof(sUpdateInfo));
	LabelS = UpdateInfo.szLabel;

	for (int i = 0; i < iLCounter; i++) {
		if (LabelS == Label[i]) {
			if (!aares) {
				int ElementSize;
				switch (UpdateInfo.cType) {
				case '1':
				case 'B':
					ElementSize = 1;
					break;
				case 'W':
				case '2':
					ElementSize = 2;
					EndianConvert(&data[65], ElementSize);
					break;
				case 'L':
				case '4':
				case 'F':
					ElementSize = 4;
					EndianConvert(&data[65], ElementSize);
					break;
				case 'D':
					ElementSize = 8;
					EndianConvert(&data[65], ElementSize);
					break;
				default:
					ElementSize = 0;
					break;
				}
			}
			memcpy((void *) &UpdateInfo, data, sizeof(sUpdateInfo));
			strcpy(sLabelS[i].szLabel, UpdateInfo.szLabel);
			sLabelS[i].cType = UpdateInfo.cType;
			sLabelS[i].v.dVal = UpdateInfo.v.dVal;
			break;
		}
	}

	return 0;
}

int TCPIP::Get_Array(char *data, int size) {
	int i = -1;
	bool success = false;

	do {
		i++;
		if (strcmp(data, ArrayS[i].Label) == 0)
			success = true;
	} while (i < iALCounter && success == false);

	if (success == true) {
		int PosOfDim;
		char LevelOfDim;
		int DataSize = 0;
		char array_type;

		PosOfDim = (int) strlen(data) + 1 + 1;
		char * dimension_data = &data[PosOfDim + 1];
		array_type = data[PosOfDim -1];


		if (ArrayS[i].ptoArray.cVal == NULL) //first pass: no memory allocated yet
		{
			//copy everything
			LevelOfDim = data[PosOfDim];
			ArrayS[i].levelofdimensions = LevelOfDim;

			if (!aares) {
				switch (LevelOfDim) {
				case 5:
					EndianConvert(&dimension_data[4 * 4], 4);
					memcpy((void *) &ArrayS[i].dim5, (void *) &dimension_data[4 * 4], sizeof(int));
				case 4:
					EndianConvert(&dimension_data[3 * 4], 4);
					memcpy((void *) &ArrayS[i].dim4, (void *) &dimension_data[3 * 4], sizeof(int));
				case 3:
					EndianConvert(&dimension_data[2 * 4], 4);
					memcpy((void *) &ArrayS[i].dim3, (void *) &dimension_data[2 * 4], sizeof(int));
				case 2:
					EndianConvert(&dimension_data[1 * 4], 4);
					memcpy((void *) &ArrayS[i].dim2, (void *) &dimension_data[1 * 4], sizeof(int));
				case 1:
					EndianConvert(&dimension_data[0], 4);
					memcpy((void *) &ArrayS[i].dim1, (void *) &dimension_data[0], sizeof(int));
					break;
				}
			} else {
				switch (LevelOfDim) {
				case 5:
					memcpy((void *) &ArrayS[i].dim5, (void *) &dimension_data[4 * 4], sizeof(int));
				case 4:
					memcpy((void *) &ArrayS[i].dim4, (void *) &dimension_data[3 * 4], sizeof(int));
				case 3:
					memcpy((void *) &ArrayS[i].dim3, (void *) &dimension_data[2 * 4], sizeof(int));
				case 2:
					memcpy((void *) &ArrayS[i].dim2, (void *) &dimension_data[1 * 4], sizeof(int));
				case 1:
					memcpy((void *) &ArrayS[i].dim1, (void *) &dimension_data[0], sizeof(int));
					break;
				}
			}

			if (!aares)
				EndianConvert( &dimension_data[LevelOfDim * 4], 4);

			memcpy((void *) &DataSize, (void *) &dimension_data[LevelOfDim * 4], sizeof(int));
			ArrayS[i].dataSize = DataSize;
			ArrayS[i].ptoArray.cVal = (char *) malloc((size_t) DataSize);
			assert(ArrayS[i].ptoArray.cVal); //Out of memory?
		} else {
			LevelOfDim = ArrayS[i].levelofdimensions;
			DataSize = ArrayS[i].dataSize;
		}
		
		char *current_field = &dimension_data[LevelOfDim * 4];

		if (!aares) {
			int ElementSize;
			switch (array_type) {
			case '1':
			case 'B':
				ElementSize = 1;
				break;
			case 'W':
			case '2':
				ElementSize = 2;
				for (int n = 0; n < DataSize; n += ElementSize)
					EndianConvert(&current_field[4 + n], ElementSize);
				break;
			case 'L':
			case '4':
			case 'F':
				ElementSize = 4;
				for (int n = 0; n < DataSize; n += ElementSize)
					EndianConvert(&current_field[4 + n], ElementSize);
				break;
			case 'D':
				ElementSize = 8;
				for (int n = 0; n < DataSize; n += ElementSize)
					EndianConvert(&current_field[4 + n], ElementSize);
				break;
			default:
				ElementSize = 0;
				break;
			}
		}
		memcpy((void *) ArrayS[i].ptoArray.cVal,
				(void *) &current_field[4], (size_t) DataSize);
	}
	return 0;
}

int TCPIP::Get_Array_Element(char *data, int size) {
	int i = -1;
	bool success = false;

	do {
		i++;
		if (strcmp(data, ArrayS[i].Label) == 0)
			success = true;
	} while (i < iALCounter && success == false);

	if (success == true) {
		char DataType;
		int PosOfData;
		int ElementSize;
		int MemOffset = 0;

		PosOfData = (int) strlen(data) + 1 + 1;
		DataType = data[PosOfData - 1];

		switch (DataType) {
		case '1':
		case 'B':
			ElementSize = 1;
			break;
		case 'W':
		case '2':
			ElementSize = 2;
			break;
		case 'L':
		case '4':
		case 'F':
			ElementSize = 4;
			break;
		case 'D':
			ElementSize = 8;
			break;
		default:
			ElementSize = 0;
			break;
		}

		while (PosOfData < size) { //TODO check index bounds
			if (!aares)
				EndianConvert(&data[PosOfData], 4);

			memcpy((void *) &MemOffset, (void *) &data[PosOfData],
					sizeof(int));
			if (ArrayS[i].ptoArray.cVal != NULL) {
				if (!aares)
					EndianConvert(&data[PosOfData + 4],
							ElementSize);

				memcpy((void *) &ArrayS[i].ptoArray.cVal[MemOffset],
						&data[PosOfData + 4], (size_t) ElementSize);
			}
			PosOfData = PosOfData + 4 + ElementSize;
		}
	}
	return 0;
}

//***********************************************************************************************************
// Set changed label values
int TCPIP::Set_Value(TcpSocket &server,string Label, float fValue) {

	sprintf(sendbuf, "%s=%f\n", Label.c_str(), fValue);
	return server.send(sendbuf, (int) strlen(sendbuf));
}

//***********************************************************************************************************
// Init User Labels
int TCPIP::InitLabel(TcpSocket &server) {

	Transmitter(server); //we need to set transfer-mode to 'binary'
	string TransmitterL = "update ";

	//Single-Element Labels
	for (int i = 0; i < iLCounter; i++) {
		memcpy(sLabelS[i].szLabel, Label[i], 32);
		TransmitterL += Label[i];
		TransmitterL += " ";
	}

	//Array-Labels
	for (int i = 0; i < iALCounter; i++) {
		TransmitterL += ArrayLabel[i];
		TransmitterL += " ";
		memcpy(ArrayS[i].Label, ArrayLabel[i], 32);
	}

	TransmitterL += "\n";

	memcpy((void *) &sendbuf, &TransmitterL[0], TransmitterL.length());
	return server.send(sendbuf, (int) strlen(sendbuf));
}