#include "UDP.h"

int iTestCounterUdpClass = 0;

CUDP::CUDP(bool aares):
	aares(aares)
{
	memset(&UDP_Struct,0,sizeof(sUDP_Struct));
}

void CUDP::ProcessData(char *buffer)
{
    unsigned short command_size=0; 
	unsigned short next_data=0;
    unsigned short index=0;
    unsigned short command_id=1;

    while (command_id !=0)
    {
      

		memcpy((void *)&command_id,&buffer[index],sizeof(command_id));
        command_size = 4 + *(unsigned short *)(buffer + index + 2);
        next_data = index + 4;

        switch(command_id)
        {
        case 0:
            break;

        case 1:     // Time Data - OK
            memcpy((void *)&UDP_Struct.TimeData,&buffer[next_data],sizeof(sTimeData));
            index+=command_size;
            break;

        case 2:     //Aircraft Position - OK
            memcpy((void *)&UDP_Struct.AircraftPosition,&buffer[next_data],sizeof(sAircraftPosition));
            index+=command_size;
            break;

        // Aircraft Data seems to break UDP connections
        case 3:     //Aircraft Data
            memcpy((void *)&UDP_Struct.AircraftData,&buffer[next_data],sizeof(sAircraftData));
            index+=command_size;
            break;
//
//        case 4:
//            /*
//            memcpy((void *)&EnvironmentData,&buffer[index+2],sizeof(environment_data_struct));
//            if (EnvironmentData._tavmode!=OldEnvironmentData._tavmode)
//            {
//                switch(EnvironmentData._tavmode)
//                {
//                case 0:
//                    FSLink.set_scene(night);
//                    break;
//                case 1:
//                    FSLink.set_scene(dusk);
//                    break;
//                case 2:
//                    FSLink.set_scene(day);
//                    break;
//                }
//                FSLink.send_Data_to_FS();
//                FSLink.send_Data_to_FS();
//            }
//
//            if (EnvironmentData.visibility_conditions!=OldEnvironmentData.visibility_conditions)
//            {
//                switch(EnvironmentData.visibility_conditions)
//                {
//                case 0: // CAVOK
//                    VISUDPDlg.WriteLog("Visibility: CAVOK");
//                    FSLink.set_visibility(79950);
//                    FSLink.cloud_init();
//                    FSLink.set_cloud();
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 1: // Circling
//                    VISUDPDlg.WriteLog("Visibility: Circling");
//                    FSLink.set_visibility(5000);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 2: // Non Prec
//                    VISUDPDlg.WriteLog("Visibility: Non Precision");
//                    FSLink.set_visibility(2000);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 3: // Min T/O
//                    VISUDPDlg.WriteLog("Visibility: Min T/O");
//                    FSLink.set_visibility(125);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 4: // CAT I
//                    VISUDPDlg.WriteLog("Visibility: CAT I");
//                    FSLink.set_visibility(550);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 5: // CAT II
//                    VISUDPDlg.WriteLog("Visibility: CAT II");
//                    FSLink.set_visibility(300);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 6: // CAT IIIa
//                    VISUDPDlg.WriteLog("Visibility: CAT IIIa");
//                    FSLink.set_visibility(200);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 7: // CAT IIIb
//                    VISUDPDlg.WriteLog("Visibility: CAT IIIb");
//                    FSLink.set_visibility(125);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 8: // CAT IIIn
//                    VISUDPDlg.WriteLog("Visibility: CAT III NoDH");
//                    FSLink.set_visibility(75);
//                    FSLink.send_Data_to_FS();
//                    break;
//                case 9: // CAT IIIz (0/0)
//                    VISUDPDlg.WriteLog("Visibility: 0/0");
//                    FSLink.set_visibility(0);
//                    FSLink.send_Data_to_FS();
//                    break;
//                }
//            }
//            memcpy((void *)&OldEnvironmentData,&buffer[index+2],sizeof(environment_data_struct));
//            */
//            index+=(unsigned char)buffer[index+2];
//            break;
//
		case 10:    //Translatory Data
            memcpy((void *)&UDP_Struct.Weather,&buffer[next_data],sizeof(sWeather));
            index+=command_size;
            break;

        case 20:    //Translatory Data
            memcpy((void *)&UDP_Struct.TranslatoryData,&buffer[next_data],sizeof(sTranslatoryData));
            index+=command_size;
            break;

        case 21:    //Rotatory Data
            memcpy((void *)&UDP_Struct.RotatoryData,&buffer[next_data],sizeof(sRotatoryData));
            index+=command_size;
            break;

        case 22:    //Aerodynamic Data
            memcpy((void *)&UDP_Struct.AerodynamicData,&buffer[next_data],sizeof(sAerodynamicData));
            index+=command_size;
            break;

        case 23:    //Euler Data
            memcpy((void *)&UDP_Struct.EulerData,&buffer[next_data],sizeof(sEulerData));
            index+=command_size;
            break;

        case 24:    //Misc Data
            memcpy((void *)&UDP_Struct.MiscData,&buffer[next_data],sizeof(sMiscData));
            index+=command_size;
            break;

        case 25:    //CAS Data
            memcpy((void *)&UDP_Struct.CASData,&buffer[next_data],sizeof(sCASData));
            index+=command_size;
            break;

		case 30:    //Aileron Data
			memcpy((void *)&UDP_Struct.AileronData,&buffer[next_data],sizeof(sAileronData));
            index+=command_size;
            break;

        case 31:    //Elevator Data
            memcpy((void *)&UDP_Struct.ElevatorData,&buffer[next_data],sizeof(sElevatorData));
            index+=command_size;
            break;

        case 32:    //Rudder Data
            memcpy((void *)&UDP_Struct.RudderData,&buffer[next_data],sizeof(sRudderData));
            index+=command_size;
            break;

		case 33:    //Spoiler Data
            memcpy((void *)&UDP_Struct.SpoilerData,&buffer[next_data],sizeof(sSpoilerData));
            index+=command_size;
            break;

        case 34:    //SControl Data
            memcpy((void *)&UDP_Struct.SControlData,&buffer[next_data],sizeof(sSControlData));
            index+=command_size;
            break;

        case 40:    //Engine Data
            memcpy((void *)&UDP_Struct.EngineData,&buffer[next_data],sizeof(sEngineData));
            index+=command_size;
            break;

		 case 42:    //Analoge Data
            memcpy((void *)&UDP_Struct.AnalogeControlData,&buffer[next_data],sizeof(sAnalogeControlData));
            index+=command_size;
            break;

        case 50:    //ComNav Data - OK
            memcpy((void *)&UDP_Struct.ComNavData,&buffer[next_data],sizeof(sComNavData));
            index+=command_size;
            break;

        case 52:    //EIS Data - OK
            memcpy((void *)&UDP_Struct.EISData,&buffer[next_data],sizeof(sEISData));
            index+=command_size;
            break;

        case 56:    //FCUStat Data - OK
            memcpy((void *)&UDP_Struct.FCUStatData,&buffer[next_data],sizeof(sFCUStatData));
            index+=command_size;
            break;

        case 70:    //ADIRS Data1
            memcpy((void *)&UDP_Struct.ADIRSData1,&buffer[next_data],sizeof(sADIRSData1));
            index+=command_size;
            break;

        case 71:    //ADIRS Data2
            memcpy((void *)&UDP_Struct.ADIRSData2,&buffer[next_data],sizeof(sADIRSData2));
            index+=command_size;
            break;

        case 72:    //ADIRS Data3
            memcpy((void *)&UDP_Struct.ADIRSData3,&buffer[next_data],sizeof(sADIRSData3));
            index+=command_size;
            break;

        case 73:    //DMC Data1 - OK
            memcpy((void *)&UDP_Struct.PFDDataDMC1,&buffer[next_data],sizeof(sPFDDataDMC1));
            index+=command_size;
            break;

        case 74:    //DMC Data2 - OK
            memcpy((void *)&UDP_Struct.PFDDataDMC2,&buffer[next_data],sizeof(sPFDDataDMC2));
            index+=command_size;
            break;

        case 75:    //DMC Data3 - OK
            memcpy((void *)&UDP_Struct.PFDDataDMC3,&buffer[next_data],sizeof(sPFDDataDMC3));
            index+=command_size;
            break;

        case 80:    //MomentOfInertia Data
            memcpy((void *)&UDP_Struct.MomentOfInertia,&buffer[next_data],sizeof(sMomentOfInertia));
            index+=command_size;
            break;

        case 81:    //Weight Data
            memcpy((void *)&UDP_Struct.Weight,&buffer[next_data],sizeof(sWeight));
            index+=command_size;
            break;

		case 95:    //FCtrlPage
            memcpy((void *)&UDP_Struct.SD_FCTLPage,&buffer[next_data],sizeof(sSD_FCTLPage));
            index+=command_size;
            break;


        default:
            index+=command_size;
            break;
        }
    }
}

bool CUDP::Reciever(UdpSocket &server)
{
	// Clear the buffer so we don't get - (0xCC) on all characters
	memset(&cBufferR, 0, sizeof(cBufferR));

	int bytesRecvd = server.receive(cBufferR, sizeof(cBufferR));

	if(bytesRecvd > 0){
		ProcessData(cBufferR);
		return true;
	}

	

	return false;
}
/*************************************************************************************************************/
int CUDP::InitW()
{
	int opt =1;
	unsigned long dest_addr;
	int iStat = 1;
	int iResult = 0;
	BOOL bOptVal = FALSE;
	int bOptLen = sizeof (BOOL);

	WSADATA wsDat;
	WSAStartup(S_WSVERSION, &wsDat);
	
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	// Create the socket
	
	//setsockopt(s, SOL_SOCKET, SO_BROADCAST, opt, sizeof(opt));

	// Reusable Socket Option to share udp data with two or more parallel running applications
	bOptVal = TRUE;
	iResult = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *) &bOptVal, bOptLen);

	/* set address and port for outgoing UDP data */
	memset((char*) &sout, 0, sizeof (sout));
	sout.sin_family = AF_INET ;
	sout.sin_port = htons(DESTINATION_PORT);
	dest_addr = inet_addr(DESTINATION_ADDRESS);
	memcpy((void*) &sout.sin_addr.s_addr,(void*) &dest_addr, 4);


	sin.sin_addr.S_un.S_addr = INADDR_ANY;          // Set socket IP to 0.0.0.0 (local computer)
	sin.sin_family = AF_INET;                       // set the family
	sin.sin_port = htons(RECEIVE_PORT);             // Set the port
	iStat = bind(s, (sockaddr *)&sin, sizeof(sin)); // Bind the socket
	
	int i02 = WSAGetLastError();

	return iStat;
}

/*************************************************************************************************************/
// Reciever function
bool CUDP::RecieverW()
{
	unsigned long lMsg;
	if(UDP_Struct.bSimStatus)
	{
		lMsg = 5;
	}
	
	//CUDP::itest++;

	//char cBufferR[C_MAXLENGTH];

	// Clear the buffer so we don't get Ì (0xCC) on all characters
	memset(&cBufferR, 0, sizeof(cBufferR));

	// Look for incoming data

	int nMsg = ioctlsocket(s, FIONREAD, &lMsg);
	if(!nMsg && lMsg > 0)
	{
		// Size of the sockaddr_in
		int nSize = sizeof(sin);
		long dwBytesRecvd = 0;
		// Receive the data
		//bytesRecv = recv( s, recvbuf, sizeof(recvbuf), 0 );
		dwBytesRecvd = recvfrom(s, cBufferR, sizeof(cBufferR), 0, (sockaddr *)&sin, &nSize);
		if(dwBytesRecvd)
		{
			// Data received? ->Parse the data
			//ProcessData(cBuffer);
			ProcessData(cBufferR);
			//return 0;
		}
		else
		    return TRUE;
	}

	return FALSE;
}
/*************************************************************************************************************/
// Transmitter function
bool CUDP::TransmitterW()
{
			
			// Clear the buffer so we don't get Ì (0xCC) on all characters
			memset(&cBufferT, 0, sizeof(cBufferT));
			generate_packet();
			sendto(s,cBufferT,udp_send_bytes,0,(sockaddr*) &sout,sizeof(sout));


			return TRUE;
}
/*************************************************************************************************************/
// Transmitter function
bool CUDP::Transmitter(UdpSocket &server)
{
			//char cBufferT[C_MAXLENGTH];
			// Clear the buffer so we don't get - (0xCC) on all characters
			memset(&cBufferT, 0, sizeof(cBufferT));
			generate_packet();
			server.send(cBufferT, udp_send_bytes);

			//iTestCounterUdpClass++;
			

	return true;
}
/*************************************************************************************************************/

void CUDP::generate_packet()
{
	udp_send_bytes = 0;

		generate_EFCS_data();

		if(UDP_Struct.FCUStatData.iFCU_AP1_STAT != 1 && UDP_Struct.FCUStatData.iFCU_AP2_STAT != 1)
		{
			/*generate_aileron_position_data();
			generate_elevator_position_data();
			generate_rudder_position_data();
			generate_spoiler_data();*/
			
		
			
		}

		if(UDP_Struct.FCUStatData.iFCU_ATHR_STAT != 1)
		{
			
		}

		//generate_comnav_data();
		//generate_sim_data();
		//generate_scontrol_data();
		//generate_fcuset_data();
		
}

void CUDP::insert_command_id_in_buffer (unsigned short command_id)
{
	memcpy (&cBufferT [udp_send_bytes],(void*) &command_id, sizeof(command_id));
	udp_send_bytes += sizeof(command_id);
}

void CUDP::insert_datasize_in_buffer(unsigned char datasize)
{   
	memcpy(&cBufferT [udp_send_bytes],(void *)&datasize,sizeof(datasize));
	udp_send_bytes+=1;
	memcpy(&cBufferT [udp_send_bytes],"",1);
	udp_send_bytes += sizeof(datasize);
}
/* COMMAND ID 601 */
 void CUDP::generate_EFCS_data()
{
	insert_command_id_in_buffer(601);
	insert_datasize_in_buffer(sizeof(sEFCSControlsData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.EFCSControlsData, sizeof(sEFCSControlsData)+4);
	udp_send_bytes += sizeof(sEFCSControlsData);
}

/*******************************************************************/
/* COMMAND ID 30 */
 void CUDP::generate_aileron_position_data()
{
	insert_command_id_in_buffer(30);
	insert_datasize_in_buffer(sizeof(sAileronData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.AileronData, sizeof(sAileronData)+4);
	udp_send_bytes += sizeof(sAileronData);
}

/*******************************************************************/
/* COMMAND ID 31 */
void CUDP::generate_elevator_position_data()
{
    insert_command_id_in_buffer(31);
    insert_datasize_in_buffer(sizeof(sElevatorData));
    memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.ElevatorData, sizeof(sElevatorData)+4);
    udp_send_bytes += sizeof(sElevatorData);
}

/*******************************************************************/
/* COMMAND ID 32 */
void CUDP::generate_rudder_position_data()
{
	insert_command_id_in_buffer(32);
	insert_datasize_in_buffer(sizeof(sRudderData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.RudderData, sizeof(sRudderData)+4);
	udp_send_bytes += sizeof(sRudderData);
 }
/*******************************************************************/
/* COMMAND ID 33 */
 void CUDP::generate_spoiler_data()
 {
	insert_command_id_in_buffer(33);
	insert_datasize_in_buffer(sizeof(sSpoilerData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.SpoilerData, sizeof(sSpoilerData)+4);
	udp_send_bytes += sizeof(sSpoilerData);
 }
/*******************************************************************/
/* COMMAND ID 34 */
 void CUDP::generate_scontrol_data()
 {
	insert_command_id_in_buffer(34);
	insert_datasize_in_buffer(sizeof(sSControlData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.SControlData, sizeof(sSControlData)+4);
	udp_send_bytes += sizeof(sSControlData);
}

/*******************************************************************/
/* COMMAND ID 41 */
/*******************************************************************/
void CUDP::generate_EngineControl_data()
{
	insert_command_id_in_buffer(41);
	insert_datasize_in_buffer(sizeof(sEngineControlData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.EngineControlData, sizeof(sEngineControlData)+4);
	udp_send_bytes += sizeof(sEngineControlData);
}

/*******************************************************************/
/* COMMAND ID 50 */
void CUDP::generate_comnav_data()
{
	insert_command_id_in_buffer(50);
	insert_datasize_in_buffer(sizeof(sComNavData));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.ComNavData, sizeof(sComNavData)+4);
	udp_send_bytes += sizeof(sComNavData);
}

/*******************************************************************/
/* COMMAND ID 55 */
void CUDP::generate_fcureq_data()
{
    insert_command_id_in_buffer(55);
    insert_datasize_in_buffer(sizeof(sFCURqData));
    memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.FCURqData, sizeof(sFCURqData)+4);
    udp_send_bytes += sizeof(sFCURqData);
}

/*******************************************************************/
/* COMMAND ID 57 */
void CUDP::generate_fcuset_data()
{
    insert_command_id_in_buffer(57);
    insert_datasize_in_buffer(sizeof(sFCUSetData));
    memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.FCUSetData, sizeof(sFCUSetData)+4);
    udp_send_bytes += sizeof(sFCUSetData);
}

/*******************************************************************/
/* COMMAND ID 60 */
void CUDP::generate_sim_data()
{
    insert_command_id_in_buffer(60);
    insert_datasize_in_buffer(sizeof(sSimData));
    memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.SimData, sizeof(sSimData)+4);
    udp_send_bytes += sizeof(sSimData);
}



/*************************************************************************************************************/
int CUDP::Init_FDC()
{
	int opt =1;
	unsigned long dest_addr;
	int iStat = 1;

	WSADATA wsDat;
	WSAStartup(S_WSVERSION, &wsDat);
	
	sFDC = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);   // Create the socket
	
	//setsockopt(s, SOL_SOCKET, SO_BROADCAST, opt, sizeof(opt));


	/* set address and port for outgoing UDP data */
	memset((char*) &soutFDC, 0, sizeof (soutFDC));
	soutFDC.sin_family = AF_INET ;
	soutFDC.sin_port = htons(DESTINATION_PORT_FDC);
	dest_addr = inet_addr(DESTINATION_ADDRESS_FDC); //INADDR_LOOPBACK; //
	memcpy((void*) &soutFDC.sin_addr.s_addr,(void*) &dest_addr, 4);


	sinFDC.sin_addr.S_un.S_addr = INADDR_ANY;          // Set socket IP to 0.0.0.0 (local computer)
	sinFDC.sin_family = AF_INET;                       // set the family
	sinFDC.sin_port = htons(RECEIVE_PORT_FDC);         // Set the port
	iStat = bind(sFDC, (sockaddr *)&sinFDC, sizeof(sinFDC)); // Bind the socket
	
	return iStat;
}

/*************************************************************************************************************/
bool CUDP::Transmitter_FDC()
{
	//char cBufferT[C_MAXLENGTH];
			// Clear the buffer so we don't get Ì (0xCC) on all characters
			memset(&cBufferT, 0, sizeof(cBufferT));
			generate_packet_FDC();
			sendto(sFDC,cBufferT,udp_send_bytes,0,(sockaddr*) &soutFDC,sizeof(soutFDC));


			return TRUE;
			//return FALSE;
}

/*************************************************************************************************************/
void CUDP::generate_packet_FDC()
{
	udp_send_bytes = 0;
	generate_FDC_data();

}
/*************************************************************************************************************/
/* COMMAND ID 1 */ /* only for Flight Display Control on destination port 5809*/
void CUDP::generate_FDC_data()
 {
	insert_command_id_in_buffer(1);
	insert_datasize_in_buffer_FDC(sizeof(sFlightDisplayCtr));
	memcpy(&cBufferT[udp_send_bytes], (void *)&UDP_Struct.FlightDisplayCtr, sizeof(sFlightDisplayCtr)+3);
	udp_send_bytes += sizeof(sFlightDisplayCtr);
 }
/*************************************************************************************************************/
/*******************************************************************/
void CUDP::insert_datasize_in_buffer_FDC(unsigned char datasize)
{
  	  cBufferT[udp_send_bytes]=datasize+3;
	  udp_send_bytes+=1;
}
/*******************************************************************/
