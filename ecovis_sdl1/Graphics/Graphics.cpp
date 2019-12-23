#include "Graphics.h"
#include <string>
using namespace std;

Graphics::Graphics(string windowTitle, int width, int height, bool fullscreen)
	throw(runtime_error)
{
	if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0 )
	{
		string error(SDL_GetError());
		throw runtime_error("Failed to start SDL: " + error);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//SDL_putenv ("SDL_VIDEO_WINDOW_POS=0,0");		//cb02072015

    Uint32 flags;
    flags = SDL_WINDOW_OPENGL;
	if (fullscreen)
	{

		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}
		
	else
	{
		//flags |= SDL_WINDOW_MAXIMIZED;
		flags |= SDL_WINDOW_RESIZABLE;
		sdlWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED_DISPLAY(0), SDL_WINDOWPOS_CENTERED_DISPLAY(0), width, height, flags);
		if (sdlWindow == NULL)
		{
			SDL_Quit();
			string error(SDL_GetError());
			throw runtime_error("Failed to set SDL VideoMode: " + error);
		}

	}
								

	
	if(sdlWindow == NULL)
	{
		SDL_Quit();
		string error(SDL_GetError());
		throw runtime_error("Failed to set SDL VideoMode: " + error);
	}

	SDL_GLContext glcontext = SDL_GL_CreateContext(sdlWindow);

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(.0f, .0f, .0f, .0f);				// Black Background
	//glClearDepth(1.0f);									// Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	//glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);      // Enable Alpha Blending (disable alpha testing)
	glEnable(GL_BLEND);                                     // Enable Blending       (disable alpha testing)
}

Graphics::~Graphics()
{
	SDL_Delay(2);
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();
}

void Graphics::add(ViewPort *viewPort)
{
	viewPortList.push_back(viewPort);
}

void Graphics::drawEverything()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(vector<ViewPort*>::iterator Iter = viewPortList.begin(); Iter != viewPortList.end(); Iter++)
	{
		(*Iter)->render();
	}
	SDL_GL_SwapWindow(sdlWindow);
}

SDL_Surface* Graphics::getScreen()
{
	return m_screen;
}
