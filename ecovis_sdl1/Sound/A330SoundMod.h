//==========================================================================================
//                                      Description                                         
//==========================================================================================
//	This is the Main Class for the Sound Object.
//  It organizes the sub classes belonging to the Sound via OPENAL
//  needs openal32.dll/lib + Header
//  
//   ----------------------------------
//  | Name:			A330SoundMod.h   |								
//  | Last Edit: 	12.01.2013         |
//  | Author:		Christian Berth    |
//==========================================================================================
//                                 Includes & Definitions                                  
//==========================================================================================

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../PFD/UDP.h"
#include "../PFD/TCPIP.h"
#include "../PFD/labels.h"

//const char* SoundName[MAX_NR_OF_SOUNDFILES];




class A330SoundMod
{
public:
	A330SoundMod(CUDP *udp_handler, TCPIP *tcp_handler);
	~A330SoundMod(void);

	void Init(void);
	void Play(void);
	void Update(void);
	bool quit;

private:

	TcpSocket         *tcp;					//pointer to send informations to simulation via TCP
	TCPIP             *tcp_handler;			//pointer to receive informations from simulation via TCP

	int iBATTERY_ON;
	int iMINIMUM_VOICE;
	int iRETARD_VOICE;
	int i10_VOICE;
	int i20_VOICE;
	int i30_VOICE;
	int i40_VOICE;
	int i50_VOICE;
	int i100_VOICE;
	int i200_VOICE;
	int i300_VOICE;
	int i400_VOICE;
	int i500_VOICE;
	int i1000_VOICE;
	int i2000_VOICE;
	int i2500_VOICE;
	int iGEAR_UP;
	int iGEAR_DOWN;
	int iMAINGEAR_TD;
	int iNOSEGEAR_TD;
	int iTAXI;
	int iSYSTEMBATON;
	int iFIREWARNTESTA;
	int iFIREWARNTESTE;
	int iNOSMOKESIGN;
	int iFASTENSBSIGN;
	int iWIPERSLOW_C;
	int iWIPERFAST_C;
	int iWIPERSLOW_FO;
	int iWIPERFAST_FO;
	int iWIND;

	int iBATTERY_ON_LAST	;
	int iMINIMUM_VOICE_LAST	;
	int iRETARD_VOICE_LAST	;
	int i10_VOICE_LAST		;
	int i20_VOICE_LAST		;
	int i30_VOICE_LAST		;
	int i40_VOICE_LAST		;
	int i50_VOICE_LAST		;
	int i100_VOICE_LAST		;
	int i200_VOICE_LAST		;
	int i300_VOICE_LAST		;
	int i400_VOICE_LAST		;
	int i500_VOICE_LAST		;
	int i1000_VOICE_LAST	;
	int i2000_VOICE_LAST	;
	int i2500_VOICE_LAST	;
	int iGEAR_UP_LAST		;
	int iGEAR_DOWN_LAST		;
	int iMAINGEAR_TD_LAST	;
	int iNOSEGEAR_TD_LAST	;
	int iTAXI_LAST			;
	int iSYSTEMBATON_LAST	;
	int iFIREWARNTESTA_LAST	;
	int iFIREWARNTESTE_LAST	;
	int iNOSMOKESIGN_LAST	;
	int iFASTENSBSIGN_LAST	;
	int iWIPERSLOW_C_LAST	;
	int iWIPERFAST_C_LAST	;
	int iWIPERSLOW_FO_LAST	;
	int iWIPERFAST_FO_LAST	;
	int iWIND_LAST			;


	void PlayA330SOUND(void);
	void PlayA330ENGSound(void);
	void PlayA330SyntheticVoices(void);
	void PlayA330ExteriorNoises(void);
	void A330SoundLogic(void);

	void PlaySingle(int SoundID);
	void PlayLoop(int SoundID);
	void PauseAll(void);
	
};
