//==========================================================================================
//                                      Description                                         
//==========================================================================================
//	This is the Main Class for the Sound Object.
//  It organizes the sub classes belonging to the Sound via OPENAL
//  needs openal32.dll/lib + Header
//  
//   ----------------------------------
//  | Name:			A330SoundMod.cpp   |								
//  | Last Edit: 	12.01.2013         |
//  | Author:		Christian Berth    |
//==========================================================================================
//                                 Includes & definitions                                  
//==========================================================================================
#include "A330SoundMod.h"
#include "../FCC_LABEL_DEF.h"
#include <al/al.h>
#include <al/alc.h>
#include <al/alut.h>

#define NUM_BUFFERS 1
#define NUM_SOURCES 1
#define NUM_ENVIRONMENTS 1




//==========================================================================================
//                                 WAV FILES & ENUM                                 
//==========================================================================================
typedef enum SoundSources{
	sENG_Left_N1_1 = 0,
	sENG_Left_N1_2,
	sENG_Left_N1_3,
	sENG_Left_N1_4,

	sENG_Left_N2_1,
	sENG_Left_N2_2,
	sENG_Left_N2_3,
	sENG_Left_N2_4,

	sENG_Right_N1_1,
	sENG_Right_N1_2,
	sENG_Right_N1_3,
	sENG_Right_N1_4,

	sENG_Right_N2_1,
	sENG_Right_N2_2,
	sENG_Right_N2_3,
	sENG_Right_N2_4,

	sGEAR_Down,
	sGEAR_Up,
	
	sMainGear_Touchdown,
	sNWS_Touchdown,
	sTaxi_GND,
	sSystem_Sound_Bat_on,
	sBoarding_Music,
	sFireWarning,
	sNoSmoke_Ping,
	sFastenSeat_Ping,
	sWiperSound_Capt,
	sWiperSound_FO,
	sWindSound,

	sFWC_10,
	sFWC_20,
	sFWC_20_ret,
	sFWC_30,
	sFWC_40,
	sFWC_50,
	sFWC_100,
	sFWC_200,
	sFWC_300,
	sFWC_400,
	sFWC_500,
	sFWC_1000,
	sFWC_2000,
	sFWC_2500,
	sFWC_ret,
	sFWC_Minimum,
	sFWC_HundredAbove,

	MAX_NR_OF_SOUNDSOURCES
};

const char* SoundName[] =	
{	
	"Wav/ban11_GE.Wav",
	"Wav/ban12_GE.Wav",
	"Wav/ban13_GE.Wav",
	"Wav/ban14_GE.Wav",
	"Wav/ban21_GE.Wav",
	"Wav/ban22_GE.Wav",
	"Wav/ban23_GE.Wav",
	"Wav/ban24_GE.Wav",
	"Wav/ban11_GE.Wav",
	"Wav/ban12_GE.Wav",
	"Wav/ban13_GE.Wav",
	"Wav/ban14_GE.Wav",
	"Wav/ban21_GE.Wav",
	"Wav/ban22_GE.Wav",
	"Wav/ban23_GE.Wav",
	"Wav/ban24_GE.Wav",
	"Wav/BMGEARDN_new.wav",
	"Wav/BMGEARUP_new.wav",
	"Wav/A330_maintouch.wav",
	"Wav/A330_nosetouch.wav",
	"Wav/A330_taxi_new.wav",											
	"Wav/A330_system.WAV",
	"Wav/A330_boarding.wav",
	"Wav/FireWarning.wav",
	"Wav/SignPing.wav",
	"Wav/SignPing.wav",
	"Wav/AAARES_Wiper.wav",
	"Wav/AAARES_Wiper.wav",
	"Wav/Wind.wav",
	"Wav/10.wav",
	"Wav/20.wav",
	"Wav/20-retard.wav",
	"Wav/30.wav",
	"Wav/40.wav",
	"Wav/50.wav",
	"Wav/100.wav",
	"Wav/200.wav",
	"Wav/300.wav",
	"Wav/400.wav",
	"Wav/500.wav",
	"Wav/1000.wav",
	"Wav/2000.wav",
	"Wav/2500.wav",
	"Wav/retard.wav",
	"Wav/minimum.wav",
	"Wav/hundredabove.wav"
};

const int SoundName_ArraySize = sizeof(SoundName)/sizeof (SoundName[0]);
//==========================================================================================
//                                 OPENAL LABELS                                 
//==========================================================================================

ALfloat listenerPos[]={0.0,0.0,2.0};
ALfloat listenerVel[]={0.0,0.0,0.0};
ALfloat listenerOri[]={0.0,0.0,1.0, 0.0,1.0,0.0};

ALfloat source0Pos[]={ 0.0, 0.0, 0.0};
ALfloat source0Vel[]={ 0.0, 0.0, 0.0};

ALuint  buffer[SoundName_ArraySize];
ALuint  source[MAX_NR_OF_SOUNDSOURCES];
ALuint  environment[NUM_ENVIRONMENTS];

ALsizei ddsize;
ALsizei freq;
ALenum  format;
ALvoid  *dddata;

ALint val;
  
float fpitch = 0.2f;

int iCounter = 0;

sUDP_Struct *sUdpsSound = NULL;  //pointer to UDP Data Struct

//==========================================================================================
//                                 CLASS - CONSTRUCTOR                          
//==========================================================================================
A330SoundMod::A330SoundMod(CUDP *udp_handler, TCPIP *tcp_handler):
		quit(false),
		tcp_handler(tcp_handler)
{
	sUdpsSound = &udp_handler->UDP_Struct;

	iBATTERY_ON		= 0;
	iMINIMUM_VOICE	= 0;
	iRETARD_VOICE	= 0;
	i10_VOICE		= 0;
	i20_VOICE		= 0;
	i30_VOICE		= 0;
	i40_VOICE		= 0;
	i50_VOICE		= 0;
	i100_VOICE		= 0;
	i200_VOICE		= 0;
	i300_VOICE		= 0;
	i400_VOICE		= 0;
	i500_VOICE		= 0;
	i1000_VOICE		= 0;
	i2000_VOICE		= 0;
	i2500_VOICE		= 0;
	iGEAR_UP		= 0;
	iGEAR_DOWN		= 0;
	iMAINGEAR_TD	= 0;
	iNOSEGEAR_TD	= 0;
	iTAXI			= 0;
	iSYSTEMBATON	= 0;
	iFIREWARNTESTA	= 0;
	iFIREWARNTESTE	= 0;
	iNOSMOKESIGN	= 0;
	iFASTENSBSIGN	= 0;
	iWIPERSLOW_C	= 0;
	iWIPERFAST_C	= 0;
	iWIPERSLOW_FO	= 0;
	iWIPERFAST_FO	= 0;
	iWIND			= 0;

	iBATTERY_ON_LAST	= 0;
	iMINIMUM_VOICE_LAST	= 0;
	iRETARD_VOICE_LAST	= 0;
	i10_VOICE_LAST		= 0;
	i20_VOICE_LAST		= 0;
	i30_VOICE_LAST		= 0;
	i40_VOICE_LAST		= 0;
	i50_VOICE_LAST		= 0;
	i100_VOICE_LAST		= 0;
	i200_VOICE_LAST		= 0;
	i300_VOICE_LAST		= 0;
	i400_VOICE_LAST		= 0;
	i500_VOICE_LAST		= 0;
	i1000_VOICE_LAST	= 0;
	i2000_VOICE_LAST	= 0;
	i2500_VOICE_LAST	= 0;
	iGEAR_UP_LAST		= 0; //sFCCInputMARS.bGearLever_Up;
	iGEAR_DOWN_LAST		= 0; //sFCCInputMARS.bGearLever_Dn;
	iMAINGEAR_TD_LAST	= 0;
	iNOSEGEAR_TD_LAST	= 0;
	iTAXI_LAST			= 0;
	iSYSTEMBATON_LAST	= 0;
	iFIREWARNTESTA_LAST	= 0;
	iFIREWARNTESTE_LAST	= 0;
	iNOSMOKESIGN_LAST	= 0;
	iFASTENSBSIGN_LAST	= 0;
	iWIPERSLOW_C_LAST	= 0;
	iWIPERFAST_C_LAST	= 0;
	iWIPERSLOW_FO_LAST	= 0;
	iWIPERFAST_FO_LAST	= 0;
	iWIND_LAST			= 0;


}

A330SoundMod::~A330SoundMod(void)
{
	alDeleteSources(MAX_NR_OF_SOUNDSOURCES, source);
	alDeleteBuffers(MAX_NR_OF_SOUNDSOURCES, buffer);
	alutExit();
}
//==========================================================================================
//                                 INIT SOUNDS  - OPENAL                          
//==========================================================================================
void A330SoundMod::Init(void)
{
		// Init openAL
		alutInit(0, NULL);
		// Clear Error Code (so we can catch any new errors)
		alGetError();

		alListenerfv(AL_POSITION,listenerPos);
    	alListenerfv(AL_VELOCITY,listenerVel);
    	alListenerfv(AL_ORIENTATION,listenerOri);

		alGetError(); // clear any error messages
    	// Generate buffers, or else no sound will happen!
    	alGenBuffers(SoundName_ArraySize, buffer);

		//5.1Channel abfrage cb 17122013
		
		format = alGetEnumValue("AL_FORMAT_51CHN16");
		if (!format)
		{
			printf ("No support for 5.1 playback!\n");
		}
    
    	if(alGetError() != AL_NO_ERROR) 
    	{
        	printf("- Error creating buffers !!\n");
        	exit(1);
    	}
    	else
    	{
        	printf("init() - No errors yet.");
    	}

		alGetError(); /* clear error */
		// Generate Sound Sources
    	alGenSources(MAX_NR_OF_SOUNDSOURCES, source);

    	if(alGetError() != AL_NO_ERROR) 
    	{
        	printf("- Error creating sources !!\n");
        	exit(2);
    	}
    	else
    	{
        	printf("init - no errors after alGenSources\n");
    	}


		

		// LOAD ALL ENUMERATED WAV FILES - ATTACH IT TO SOUND SOURCE - SET PARAMETERS
		for(int i=0; i < MAX_NR_OF_SOUNDSOURCES; i++)
		{
			//LOADING
			alutLoadWAVFile((ALbyte *)SoundName[i],&format,&dddata,&ddsize,&freq,NULL);
			alBufferData(buffer[i],format,dddata,ddsize,freq);	
    		alutUnloadWAV(format,dddata,ddsize,freq);

			//ATTACHING
			alSourcei(source[i], AL_BUFFER,buffer[i]);

			//SETTING
			alSourcef(source[i], AL_PITCH, 0.5f);
    		alSourcef(source[i], AL_GAIN, 1.0f);
    		alSourcefv(source[i], AL_POSITION, source0Pos);
    		alSourcefv(source[i], AL_VELOCITY, source0Vel);
    		//alSourcei(source[i], AL_LOOPING, AL_TRUE);
		}

/*alSourcef(source[sENG_Left_N2_2], AL_GAIN, 0.05f);
alSourcef(source[sENG_Left_N2_2], AL_PITCH, 0.1f);
alSourcei(source[sENG_Left_N2_2], AL_LOOPING, AL_TRUE);
alSourcePlay(source[sENG_Left_N2_2]);	*/	

	

	
}
//==========================================================================================
//                                 PLAY SOUNDS                              
//==========================================================================================
void A330SoundMod::Play(void)
{
	if(!tcp_handler->sLabelS[CDB_FLIGHT_FREEZE].v.cVal)
	{
		A330SoundLogic();
		PlayA330SOUND();		
	}
	else
	{
		PauseAll();
		
	}
}
//==========================================================================================
//                                 A330 SOUND LOGIC                               
//==========================================================================================
void A330SoundMod::A330SoundLogic(void)
{
		iGEAR_UP		= 0; //sFCCInputMARS.bGearLever_Up;
		iGEAR_DOWN		= 0; // sFCCInputMARS.bGearLever_Dn;
		iSYSTEMBATON	= (int)tcp_handler->sLabelS[CDB_BAT_1].v.cVal;
		iNOSMOKESIGN	= (int)tcp_handler->sLabelS[CDB_NOSMOK_ON].v.cVal;
		iFASTENSBSIGN	= (int)tcp_handler->sLabelS[CDB_FASTSB_ON].v.cVal;

		iFIREWARNTESTA	= (int)tcp_handler->sLabelS[CDB_APU_FIRE_TEST].v.cVal;
		iFIREWARNTESTE	= (int)tcp_handler->sLabelS[CDB_ENG_FIRE_TEST].v.cVal;

		iMAINGEAR_TD    = (int)tcp_handler->sLabelS[CDB_LEFT_GEAR_ONGROUND].v.cVal;
		iNOSEGEAR_TD    = (int)tcp_handler->sLabelS[CDB_NOSE_GEAR_ONGROUND].v.cVal;
				

	



}
//==========================================================================================
//                                 A330 SOUND FUNCTIONS                                
//==========================================================================================
void A330SoundMod::PlayA330SOUND(void)
{
	PlayA330ENGSound();
	PlayA330ExteriorNoises();
	PlayA330SyntheticVoices();
	
	if(iBATTERY_ON)
	{
		
		
	}
}
void A330SoundMod::PlayA330ENGSound(void)
{

	// Just for Pitch testing
	/*	fpitch = fpitch + 0.001f;
			if (fpitch >= 1.0f)
			{
				fpitch = 1.0f;
			}*/

	
		const float N1Vol = 0.1f;
		const float N2Vol = 0.12f;
		float fENG1_N1 = sUdpsSound->EngineData.fEng1N1P/200.0f; 
		float fENG1_N2 = sUdpsSound->EngineData.fEng1N2P/200.0f; 
		float fENG2_N1 = sUdpsSound->EngineData.fEng2N1P/100.0f; 
		float fENG2_N2 = sUdpsSound->EngineData.fEng2N2P/100.0f; 

		
	
		//Frequency Pitch LEFT ENG (ENG1) A330 
		alSourcef(source[sENG_Left_N1_1], AL_PITCH, fENG1_N1);
		alSourcef(source[sENG_Left_N1_2], AL_PITCH, fENG1_N1);
		alSourcef(source[sENG_Left_N1_3], AL_PITCH, fENG1_N1);
		alSourcef(source[sENG_Left_N1_4], AL_PITCH, fENG1_N1);
		alSourcef(source[sENG_Left_N2_1], AL_PITCH, fENG1_N2);
		alSourcef(source[sENG_Left_N2_2], AL_PITCH, fENG1_N2);
		alSourcef(source[sENG_Left_N2_3], AL_PITCH, fENG1_N2);
		alSourcef(source[sENG_Left_N2_4], AL_PITCH, fENG1_N2);

		//Volume Pitch LEFT ENG (ENG1) A330 
		alSourcef(source[sENG_Left_N1_1], AL_GAIN, N1Vol);    //* fENG1_N1
		alSourcef(source[sENG_Left_N1_2], AL_GAIN, N1Vol);    //* fENG1_N1
		alSourcef(source[sENG_Left_N1_3], AL_GAIN, N1Vol);    //* fENG1_N1
		alSourcef(source[sENG_Left_N1_4], AL_GAIN, N1Vol);    //* fENG1_N1
		alSourcef(source[sENG_Left_N2_1], AL_GAIN, N2Vol);    //* fENG1_N2
		alSourcef(source[sENG_Left_N2_2], AL_GAIN, N2Vol);    //* fENG1_N2
		alSourcef(source[sENG_Left_N2_3], AL_GAIN, N2Vol);    //* fENG1_N2
		alSourcef(source[sENG_Left_N2_4], AL_GAIN, N2Vol);    //* fENG1_N2

		//Frequency Pitch RIGHT ENG (ENG2) A330 
		alSourcef(source[sENG_Right_N1_1], AL_PITCH, fENG2_N1);
		alSourcef(source[sENG_Right_N1_2], AL_PITCH, fENG2_N1);
		alSourcef(source[sENG_Right_N1_3], AL_PITCH, fENG2_N1);
		alSourcef(source[sENG_Right_N1_4], AL_PITCH, fENG2_N1);
		alSourcef(source[sENG_Right_N2_1], AL_PITCH, fENG2_N2);
		alSourcef(source[sENG_Right_N2_2], AL_PITCH, fENG2_N2);
		alSourcef(source[sENG_Right_N2_3], AL_PITCH, fENG2_N2);
		alSourcef(source[sENG_Right_N2_4], AL_PITCH, fENG2_N2);

		//Volume Pitch LEFT ENG (ENG1) A330 
		alSourcef(source[sENG_Right_N1_1], AL_GAIN, N1Vol); // * fENG2_N1);
		alSourcef(source[sENG_Right_N1_2], AL_GAIN, N1Vol); //  * fENG2_N1);
		alSourcef(source[sENG_Right_N1_3], AL_GAIN, N1Vol); //  * fENG2_N1);
		alSourcef(source[sENG_Right_N1_4], AL_GAIN, N1Vol); //  * fENG2_N1);
		alSourcef(source[sENG_Right_N2_1], AL_GAIN, N2Vol); //  * fENG2_N2);
		alSourcef(source[sENG_Right_N2_2], AL_GAIN, N2Vol); //  * fENG2_N2);
		alSourcef(source[sENG_Right_N2_3], AL_GAIN, N2Vol); //  * fENG2_N2);
		alSourcef(source[sENG_Right_N2_4], AL_GAIN, N2Vol); //  * fENG2_N2);

		PlayLoop(sENG_Left_N1_1);
		PlayLoop(sENG_Left_N1_2);
		PlayLoop(sENG_Left_N1_3);
		PlayLoop(sENG_Left_N1_4);
		PlayLoop(sENG_Left_N2_1);
		PlayLoop(sENG_Left_N2_2);
		PlayLoop(sENG_Left_N2_3);
		PlayLoop(sENG_Left_N2_4);

		PlayLoop(sENG_Right_N1_1);
		PlayLoop(sENG_Right_N1_2);
		PlayLoop(sENG_Right_N1_3);
		PlayLoop(sENG_Right_N1_4);
		PlayLoop(sENG_Right_N2_1);
		PlayLoop(sENG_Right_N2_2);
		PlayLoop(sENG_Right_N2_3);
		PlayLoop(sENG_Right_N2_4);
		
		
}

void A330SoundMod::PlayA330ExteriorNoises(void)
{
	if(iGEAR_UP != iGEAR_UP_LAST)
	{
		if(iGEAR_UP) PlaySingle(sGEAR_Up);
		iGEAR_UP_LAST = iGEAR_UP;
	}

	if(iGEAR_DOWN != iGEAR_DOWN_LAST)
	{
		if(iGEAR_DOWN) PlaySingle(sGEAR_Down);
		iGEAR_DOWN_LAST = iGEAR_DOWN;
	}

	if(iMAINGEAR_TD != iMAINGEAR_TD_LAST)
	{
		PlaySingle(sMainGear_Touchdown);
		iMAINGEAR_TD_LAST = iMAINGEAR_TD;
	}

	if(iNOSEGEAR_TD != iNOSEGEAR_TD_LAST)
	{
		PlaySingle(sNWS_Touchdown);
		iNOSEGEAR_TD_LAST = iNOSEGEAR_TD;
	}

	if(iTAXI)
	{
		PlayLoop(sTaxi_GND);
	}

	if(iSYSTEMBATON)
	{
		PlaySingle(sSystem_Sound_Bat_on);
	}

	
	if(iWIPERSLOW_C)
	{
		PlaySingle(sWiperSound_Capt);
	}
	if(iWIPERFAST_C)
	{
		PlaySingle(sWiperSound_Capt);
	}
	if(iWIPERSLOW_FO)
	{
		PlaySingle(sWiperSound_FO);
	}
	if(iWIPERFAST_FO)
	{
		PlaySingle(sWiperSound_FO);
	}
	if(iWIND)
	{
		PlaySingle(sWindSound);
	}

	
}

void A330SoundMod::PlayA330SyntheticVoices(void)
{

	if(iMINIMUM_VOICE)
	{
		PlaySingle(sFWC_Minimum);
	}

	if(iRETARD_VOICE)
	{
		PlaySingle(sFWC_ret);
	}

	if(i10_VOICE)
	{
		PlaySingle(sFWC_10);
	}

	if(i20_VOICE)
	{
		PlaySingle(sFWC_20);
	}

	if(i30_VOICE)
	{
		PlaySingle(sFWC_30);
	}

	if(i40_VOICE)
	{
		PlaySingle(sFWC_40);
	}

	if(i50_VOICE)
	{
		PlaySingle(sFWC_50);
	}

	if(i100_VOICE)
	{
		PlaySingle(sFWC_100);
	}

	if(i200_VOICE)
	{
		PlaySingle(sFWC_200);
	}

	if(i300_VOICE)
	{
		PlaySingle(sFWC_300);
	}

	if(i400_VOICE)
	{
		PlaySingle(sFWC_400);
	}

	if(i500_VOICE)
	{
		PlaySingle(sFWC_500);
	}

	if(i1000_VOICE)
	{
		PlaySingle(sFWC_1000);
	}

	if(i2000_VOICE)
	{
		PlaySingle(sFWC_2000);
	}

	if(i2500_VOICE)
	{
		PlaySingle(sFWC_2500);
	}


	//
	if(iFIREWARNTESTA)
	{
		PlaySingle(sFireWarning);
		
	}
	if(iFIREWARNTESTE)
	{
		PlaySingle(sFireWarning);
	}

	if(iNOSMOKESIGN != iNOSMOKESIGN_LAST)
	{
		if(iNOSMOKESIGN) PlaySingle(sNoSmoke_Ping);
		iNOSMOKESIGN_LAST = iNOSMOKESIGN;
	}

	if(iFASTENSBSIGN != iFASTENSBSIGN_LAST)
	{
		if(iFASTENSBSIGN) PlaySingle(sFastenSeat_Ping);
		iFASTENSBSIGN_LAST = iFASTENSBSIGN;
	}
}

//==========================================================================================
//                                 SOUND FUNCTIONS                                
//==========================================================================================
void A330SoundMod::PlaySingle(int SoundID)
{
	alSourcef(source[SoundID], AL_PITCH, 1.0f);
	alSourcei(source[SoundID], AL_LOOPING, AL_FALSE);


	alGetSourcei(source[SoundID], AL_SOURCE_STATE, &val);
                if(val != AL_PLAYING)
                    alSourcePlay(source[SoundID]);
}

void A330SoundMod::PlayLoop(int SoundID)
{
	alSourcei(source[SoundID], AL_LOOPING, AL_TRUE);
	alGetSourcei(source[SoundID], AL_SOURCE_STATE, &val);
                if(val != AL_PLAYING)
                    alSourcePlay(source[SoundID]);
}
void A330SoundMod::PauseAll(void)
{
	for(int i=0; i < MAX_NR_OF_SOUNDSOURCES; i++)
	{
			alSourcePause(source[i]);
	}
}