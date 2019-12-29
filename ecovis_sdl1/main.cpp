#undef UNICODE
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include "Graphics/Graphics.h"
#include "Network/network.h"
#include "Graphics/Graphics.h"
#include "Graphics/LineSprite.h"
#include "Graphics/TextSprite.h"
#include "Graphics/GroupSprite.h"
#include "Graphics/RectSprite.h"
#include "Graphics/ImageSprite.h"
#include <math.h>
#include <stdexcept>
#include <string>
#include <sstream>
#include <map>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_syswm.h>


#include "PFD/NetworkHandler.h"
#include "Network/network.h"
//#include "Sound/A330SoundMod.h"


#include "EASY_SIM_CORE/EASY_SIM_CORE.h"





#ifdef WIN32
static HWND hwnd;
static RECT pRect;
static SDL_SysWMinfo info;
#endif


//#define AARES 1

using namespace std;

int iDisplayLength;								//MCDU display length
int iDisplayHeight;								//MCDU display height
int MCDULength;									//original MCDU display height
int MCDUWidth;									//original MCDU display length
int magnifMCDU;									//magnification factor for MCDU display

int iMouseX = 0;
int iMouseY = 0;

unsigned int mKey = 0;

int xPos = 0;									//x position of the clicked mouse
int yPos = 0;									//y position of the clicked mouse

bool bKeyUp = FALSE;
bool bKeyDn = FALSE;
int iWhichKey = 0;

bool quit = false;
bool headUp = true;
SDL_mutex* consoleMtx;
Perspective *view;

//PFD *my_PFD;
char messageBuffer[100];
char *messageBufferEnd = messageBuffer;



FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}

//Mouse mouse;
enum sim_mode {
	NONE = 0,
	HARDWARE,
	SOFTWARE,
	PFDND
};

enum resolution {
	NO = 0,
	FULL,
	SMALL,
	BIG
};

enum ac_type {
	a320 = 0,
	a330,
	a340,
	a350,
	a380
};
typedef struct {
	sim_mode S_Mode;
	resolution S_Resolution;
	ac_type AC_TYPE;
} CommandLine;

//A330SoundMod Sound;



//Communication Interfaces
bool A330_TCP_COM_Active = 0;
bool A330_UDP_COM_Active = 0;


//Different
Uint32 SDL_GetTicks(void);
float fps = 0;
double FrameTime = 0;
int ttic;
int t2tic;

void KeyUp(void);
void KeyDn(void);

static struct display_config
{
	enum displaymodes displaymode;
	bool fullscreen;
	int width;
	int height;
	enum data_source protocol;
	char host[64];
	int port;
	int mode_3d;
	int mask;
	int showFPS;
	/*horizon_modes horizon_mode;
	birdy_modes birdy_mode;
	gammaE_ends gammaE_end;
	gammaE_lines gammaE_line;
	gammaE_hidden gammaE_hide;
	gammaE_dots gammaE_dotornot;
	birdy_drift b_drift;
	birdy_center b_center;*/
	char repeat_to_host[64];
	int repeat_to_port;
} config;

//static inline void centerDisplay( void ) 
//{
//#ifdef WIN32
//	SDL_VERSION( &info.version );
//	if ( SDL_GetWMInfo( &info ) ) {			
//		hwnd = info.window;
//		int x,y;
//		x = GetSystemMetrics(SM_CXFULLSCREEN);
//		y = GetSystemMetrics(SM_CYFULLSCREEN);
//		SetWindowPos(hwnd, HWND_TOP, x / 2 - config.width / 2, y / 2 - config.height / 2, config.width, config.height, NULL);
//	}
//#endif
//}

string IntToString(int i)
{
	ostringstream temp;
	temp << i;
	return temp.str();
}

void interpretConsole() {
	char cmd[10];
	float value;
	sscanf(messageBuffer, "%s %f", cmd, &value);

	if (!strcmp(cmd, "posx")) view->setFocusPoint(e_X, value);
	if (!strcmp(cmd, "posy")) view->setFocusPoint(e_Y, value);
	if (!strcmp(cmd, "posz")) view->setFocusPoint(e_Z, value);

}
int eventProcessor(void *p)
{
	SDL_Event *myEvent = new SDL_Event();
	SDL_Event event;
	CommandLine *cmd = (CommandLine*)p;

	if (cmd->S_Mode == HARDWARE)
	{
		iDisplayLength = 1024;
		iDisplayHeight = 768;
	}
	else if (cmd->S_Mode == SOFTWARE)
	{
		if (cmd->S_Resolution == SMALL)
		{
			MCDULength = 146;
			MCDUWidth = 227;
			magnifMCDU = 3;
			iDisplayLength = magnifMCDU * MCDULength;
			iDisplayHeight = magnifMCDU * MCDUWidth;
		}
		else if (cmd->S_Resolution == BIG)
		{
			MCDULength = 146;
			MCDUWidth = 227;
			magnifMCDU = 4;
			iDisplayLength = magnifMCDU * MCDULength;
			iDisplayHeight = magnifMCDU * MCDUWidth;
		}
		else
		{
			printf("Type in correct Resolution code (2 or 3)\n");
		}
	}
	else if (cmd->S_Mode == PFDND)
	{
		if (cmd->S_Resolution == SMALL)
		{
			MCDULength = 146;
			MCDUWidth = 227;
			magnifMCDU = 3;
			iDisplayLength = 800;
			iDisplayHeight = 1200;
		}
		else if (cmd->S_Resolution == BIG)
		{
			MCDULength = 146;
			MCDUWidth = 227;
			magnifMCDU = 4;
			iDisplayLength = 640; //800;
			iDisplayHeight = 1024; //1200;
		}
		else
		{
			printf("Type in correct Resolution code (2 or 3)\n");
		}
	}
	else
	{
		printf("Type in correct Mode (1 or 2)\n");
	}

	while (!quit)

	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
		{
			quit = true;
			break;
		}
		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
			else if (event.key.keysym.sym == SDLK_RIGHT && !bKeyDn)
			{
				//view->setFocusPoint(e_X, view->getFocusPoint(e_X)+ 0.1);

				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_LEFT && !bKeyDn)
			{
				//view->setFocusPoint(e_X, view->getFocusPoint(e_X)- 0.1);

				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_UP && !bKeyDn)
			{
				//view->setFocusPoint(e_Y, view->getFocusPoint(e_Y)+ 0.1);


				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_DOWN && !bKeyDn)
			{
				//view->setFocusPoint(e_Y, view->getFocusPoint(e_Y)- 0.1);

				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_PERIOD)
			{
				view->setFocusPoint(e_Z, view->getFocusPoint(e_Z) + 0.1);
			}
			else if (event.key.keysym.sym == SDLK_SLASH)
			{
				view->setFocusPoint(e_Z, view->getFocusPoint(e_Z) - 0.1);
			}
			else if (event.key.keysym.sym == SDLK_1 && !bKeyDn)
			{
				iWhichKey = 1;
				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_0 && !bKeyDn)
			{
				iWhichKey = 0;
				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_2 && !bKeyDn)
			{
				iWhichKey = 2;
				bKeyDn = TRUE;
			}
			else if (event.key.keysym.sym == SDLK_3 && !bKeyDn)
			{
				iWhichKey = 3;
				bKeyDn = TRUE;
			}
			else
			{

				if (messageBufferEnd - messageBuffer < 100)
				{
					SDL_LockMutex(consoleMtx);
					if (event.key.keysym.sym == SDLK_BACKSPACE || event.key.keysym.sym == SDLK_DELETE)
					{
						if (messageBuffer != messageBufferEnd)
							messageBufferEnd--;
					}
					else if (messageBufferEnd != messageBuffer && event.key.keysym.sym == SDLK_RETURN)
					{
						interpretConsole();
						memset(messageBuffer, 0, 100);
						messageBufferEnd = messageBuffer;
					}
					else
					{
						*messageBufferEnd = event.key.keysym.sym;
						messageBufferEnd++;
					}
					*messageBufferEnd = 0;
					SDL_UnlockMutex(consoleMtx);
				}
			}
			break;
		}
		case SDL_KEYUP:
		{
			bKeyDn = FALSE;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT)
			{
				iMouseX = event.button.x;
				iMouseY = iDisplayHeight - event.button.y;

				xPos = event.button.x;
				yPos = iDisplayHeight - event.button.y;

				mKey = event.button.button;
			}

			break;
		}

		case SDL_MOUSEBUTTONUP:
		{

			break;
		}

		case SDL_MOUSEMOTION:
		{


			break;

		}
		}
	}
	//delete(myEvent);
	return 0;
}
//int SoundHandler(void *p)
//{
//	A330SoundMod *object = (A330SoundMod *) p;
//	while(!object->quit){
//		object->Play();
//		
//		SDL_Delay(1);
//	}
//	return 0;
//}
//Communication Interface Functions for UDP/TCP
int udpHandler(void *p)
{
	NetworkHandler *object = (NetworkHandler *)p;
	while (!object->quit) {
		object->processUdp();

		SDL_Delay(1);
	}
	return 0;
}

//Host TCP Receiver Thread - HOST Connection
int tcpHandler(void *p)
{
	int ret = 0;
	NetworkHandler *object = (NetworkHandler *)p;
	while (!object->quit)
	{
		object->processTcp();
		SDL_Delay(1);
		if (ret<0)
		{
			object->quit = true;
		}
	}
	return 0;
}



int networkHandler(void *p)
{
	NetworkHandler *object = (NetworkHandler *)p;
	SDL_Thread *udp;
	SDL_Thread *tcp;

	udp = SDL_CreateThread(udpHandler, "udphandler", object);
	tcp = SDL_CreateThread(tcpHandler, "tcphandler", object);

	object->run();

	SDL_WaitThread(udp, NULL);
	SDL_WaitThread(tcp, NULL);

	return 0;
}

int dataPainter(void *p)
{
	SDL_Thread *events;
	SDL_Thread *Sounds;
	SDL_Thread *network;
	CommandLine *cmd = (CommandLine*)p;
	int last_tick = SDL_GetTicks();
	int last_tickFT = last_tick;
	int frame_cnt = 0;
	int calc_count = 0;

	if (cmd->S_Mode == HARDWARE)
	{
		iDisplayLength = 1000; //1024;
		iDisplayHeight = 1000; //768;
	}
	else if (cmd->S_Mode == SOFTWARE || PFDND)
	{
		if (cmd->S_Resolution == SMALL)
		{
			iDisplayLength = 800; //1024;
			iDisplayHeight = 800; //768;
		}
		else if (cmd->S_Resolution == BIG)
		{
			iDisplayLength = 1000; //1024;
			iDisplayHeight = 1000; //768;
		}
		else
		{
			printf("Type in correct Resolution code (2 or 3)\n");
		}
	}
	else
	{
		iDisplayLength = 1000;
		iDisplayHeight = 1000;
		printf("Type in correct Mode (1 or 2)\n");
	}

	try
	{
		bool fullscreen;						//screen flag variable for Display object creation 
		string windowTitle;						//window title string for Display object creation

		if (cmd->S_Mode == HARDWARE)
		{
			windowTitle = "EASY-SIM";
			fullscreen = true;
		}
		else if (cmd->S_Mode == SOFTWARE || PFDND)
		{
			if (cmd->AC_TYPE == a320)
			{
				windowTitle = "EASY-SIM";
				fullscreen = false;
			}
			else if (cmd->AC_TYPE == a330)
			{
				windowTitle = "EASY-SIM";
				fullscreen = false;
			}
			else if (cmd->AC_TYPE == a350)
			{
				windowTitle = "EASY-SIM";
				fullscreen = false;
			}
			else
			{
				printf("Type in correct AC TYPE (0, 1 or 2)\n");
			}
		}
		else
		{
			printf("Type in correct Simulation Mode (1 or 2)\n");
		}

		fullscreen = false; //fullscreen;

		Graphics Display(windowTitle, iDisplayLength, iDisplayHeight, fullscreen);
		SDL_PumpEvents();
		events = SDL_CreateThread(eventProcessor, "p", p);
		Font defaultFont("Font/LiberationSans-Regular.ttf", 20);
		view = new Perspective;
		view->readFromFile("perspective");

		ViewPort messages(0, 0, 0, 0);
		messages.setView(view);
		Display.add(&messages);

		TextSprite console(&defaultFont, "init UDP");
		console.setPosition(100, 75);
		messages.add(&console);
		Display.drawEverything();

		if (SDLNet_Init() == -1)
		{
			printf("SDLNet_Init: %s\n", SDLNet_GetError());
			exit(1);
		}

		//cb 01072015
		//Network Initialisation
		//NetworkHandler netHandler("10.0.6.1","10.0.6.255");
		//CUDP udp(false);
		//udp.InitW();
		//
		//console.setText("init TCP");
		//Display.drawEverything();
		//TCPIP tcp(false);
		//netHandler.setHandlers(&tcp,&udp);

		////cbtest_131119
		//my_PFD = initPFD330(&tcp, &udp, 1);
		//if (!my_PFD)
		//	return 1; //Fehler


		EASY_SIM_CORE easy_sim_class(iDisplayLength, iDisplayHeight);




		////Sound Object
		//A330SoundMod Sound(netHandler.UDPhandler, netHandler.TCPhandler);
		//Sound.Init();
		//Sounds = SDL_CreateThread(SoundHandler, &Sound);

		console.setText("init PFD");
		Display.drawEverything();

		/*network = SDL_CreateThread(networkHandler, &netHandler);*/



		SDL_LockMutex(consoleMtx);
		memset(messageBuffer, 0, 100);
		SDL_UnlockMutex(consoleMtx);
		console.setText(messageBuffer);

		Display.drawEverything();
		Perspective view330;
		view330.readFromFile("perspective");




		ViewPort easy_sim_class_V(0, 0, 800, 800);
		easy_sim_class_V.enableNormed();
		easy_sim_class_V.setView(&view330);
		Display.add(&easy_sim_class_V);
		easy_sim_class_V.add(&easy_sim_class);



		glEnable(GL_POINT_SMOOTH);	// switch on antialiasing for points
		glEnable(GL_LINE_SMOOTH);	// switch on antialiasing for lines

		while (!quit)
		{
			while (easy_sim_class.crashed) {
				//draw a Game Over and a reset button
				//-> maybe to this inside of display or even inside of viewport
				//just reset for now
				easy_sim_class.reset();
			}
			int cur_tick;
			frame_cnt++;
			calc_count++;
			console.setText(messageBuffer); //FIXME race condition?
											//netHandler.process();
			Display.drawEverything();

			SDL_PumpEvents();
			SDL_Delay(1);


			//Sound.Play();
			//TIMER & FRAMECOUNTER
			cur_tick = SDL_GetTicks();
			FrameTime = (double) 1000.0f / (cur_tick - last_tickFT);
			/*if(calc_count == 16)
			{
			easy_sim_class.CalcEASY_SIM_CORE();
			calc_count = 0;
			easy_sim_class.Time = cur_tick;
			}*/


			easy_sim_class.timediff = FrameTime;

			easy_sim_class.TimeSys = cur_tick;

			easy_sim_class.extdt = (double(cur_tick) - last_tickFT) / 1000.0f;

			if (cur_tick > 4000) {

				easy_sim_class.CalcEASY_SIM_CORE();
				easy_sim_class.Time = easy_sim_class.Time + (cur_tick - last_tick);
				last_tick = cur_tick;

			}
			last_tickFT = cur_tick;

			if (bKeyDn)
			{
				if (iWhichKey == 0)
				{

				}
				if (iWhichKey == 1)
				{

				}
				if (iWhichKey == 2)
				{

				}
				if (iWhichKey == 3)
				{

				}

			}

			Sleep(2);
		}



		//Sound.quit= true;
		//netHandler.quit = true;
		//SDL_WaitThread(Sounds, NULL);
		SDL_WaitThread(events, NULL);
		//SDL_WaitThread(network, NULL);
	}
	catch (runtime_error& e)
	{
		printf("error: %s\n", e.what());
		quit = true;
	}
	catch (...)
	{
		printf("unknown error \n");
		quit = true;
	}


	return 0;
}

int main(int argc, char* argv[])
{
	SDL_Thread* draw;
	consoleMtx = SDL_CreateMutex();
	CommandLine cmd;


	cmd.S_Mode = (sim_mode)2; //(sim_mode)atoi(argv[1]); cb121018
	cmd.S_Resolution = (resolution)2; //(resolution)atoi(argv[2]); cb121018
	cmd.AC_TYPE = (ac_type)0; //(ac_type)atoi(argv[3]); cb121018


	try
	{
		if (SDLNet_Init() < 0)
		{
			string error(SDLNet_GetError());
			throw runtime_error("Failed to setup network: " + error);
		}
		draw = SDL_CreateThread(dataPainter, "EASYSIM", &cmd);
		SDL_WaitThread(draw, NULL);
		SDLNet_Quit();
	}
	catch (runtime_error& e)
	{
		printf("error: %s\n", e.what());
		quit = true;
	}
	catch (...)
	{
		printf("unknown error \n");
		quit = true;
	}
	SDL_DestroyMutex(consoleMtx);
	return 0;



}

void KeyUp()
{

}

void KeyDn()
{
}