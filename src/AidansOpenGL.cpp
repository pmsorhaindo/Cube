//============================================================================
// Name        : AidansOpenGL.cpp
// Author      : Mikey
// Version     :
// Copyright   : Experimental Code is Experimental, Steal and compile at your own risk
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <iostream>
#include "SetUpCube.h"
using namespace std;

#define RUN_GRAPHICS_DISPLAY 0x00 ;
SetUpCube * cube = new SetUpCube;

Uint32 display (Uint32 interval , void *param) {
	SDL_Event event;
	event.type=SDL_USEREVENT;
	event.user.code=RUN_GRAPHICS_DISPLAY;
	event.user.data1=0;
	event.user.data2=0;
	SDL_PushEvent(&event);
	return interval;
}
void display () {
	/**
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	// Reset The Current Modelview Matrix
	glLoadIdentity();
	// put the thing somewhere between the near and far clipping panes
	glTranslatef(0.0f,0.0f,-100.0f);
	// TODO: Drawing code goes here!!
	// Don�t forget to swap the buffers
	SetUpCube cube = SetUpCube();
	Face = cube.getFaceArray();
	**/
	cube->draw();
	SDL_GL_SwapBuffers();
}
int main(int argc,char * * argv ) {
	SDL_Surface * surf ;
	Uint32 width = 640 ;
	Uint32 height = 480 ;
	Uint32 colour_depth = 16 ; // in bits
	Uint32 delay = 1000/60; // in milliseconds
	// Initialise SDL - when using C/C++ i t � s common to have to
	// initialise libraries by calling a function with in them .
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) <0) {
		cout << "Failed to initialise SDL: " << SDL_GetError ( ) << endl;
		SDL_Quit ();
	}
	// When we close a window quit the SDL application
	atexit(SDL_Quit) ;
	// Create a new window with an OpenGL surface
	if (!(surf = SDL_SetVideoMode (width,height,colour_depth,SDL_OPENGL))) {
		cout << "Failed to initialise video mode : " << SDL_GetError () << endl;
		SDL_Quit ();
	}
	// Set the state of our new OpenGL context
	glViewport (0,0,(GLsizei)(width),(GLsizei)(height));
	glMatrixMode (GL_PROJECTION) ;
	glLoadIdentity () ;
	gluPerspective(45.0f,(GLfloat)(width)/(GLfloat)(height),1.0f,1000.0f);
	glMatrixMode (GL_MODELVIEW) ;
	glLoadIdentity();
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearColor(0.0f,0.0f,0.0f,0.5f); // Black Background
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable (GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc (GL_LEQUAL); //  The Type Of Depth Test i n g To Do
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ) ; // Really Nice Perspective Calculation
	SDL_AddTimer (delay,display,NULL) ; //Call the function "display (Uint32 interval, void * param )" every delay milliseconds
	// Add the main event loop
	SDL_Event event;

	while (SDL_WaitEvent(&event) ) {
		switch (event.type) {
			case SDL_QUIT:
			SDL_Quit();
			break;
			case SDL_USEREVENT:
			display ();
			break;
		}
	}
	return 0;
}
