#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"
#include "skiman.h"
#include "snowman.h"
#include "tree.h"

#define WIDTH 600
#define HEIGHT 400

#define FRAMES_PER_SECOND 25

int main(int argc, char * argv[])
{
	int alpha = 5;
	bool continuer;
	
	//variables liées à la rotation de l'univers
	double x = 0;
	double y = 0;
	Uint8 *keystates = NULL;
	int *keystatesLen = NULL;

	//heure actuelle, derniere mise à jour
	Uint32 last_time = SDL_GetTicks();
	Uint32 current_time;

	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Création de la surface d'affichage qui est en OpenGL
	SDL_WM_SetCaption("Ski", NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

	// Initialisation de l'affichage OpenGL
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective (70, (double) WIDTH / HEIGHT, 0.5, 1000);
	SDL_Flip(ecran);
	glEnable(GL_TEXTURE_2D);

	// Boucle d'évènements
	SDL_Event event;
	SDL_EnableKeyRepeat(10,10);
	
	continuer = true;
	while (continuer)
	 {
		SDL_PollEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT: // fin
			continuer = false;
			break;
		}

		// z-buffer
		glEnable(GL_DEPTH_TEST);

		// On efface la fenêtre
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// Placement de la caméra
		gluLookAt(0, 0.5, 1.5, 0, 0.5, 0, 0, 1, 0);
		//~ gluLookAt(1, -0.8, 1, 0, -0.8, 0, 0, 1, 0);
		//~ gluLookAt(1.3, -0.8, 0, 0, -0.8, 0, 0, 1, 0);
		
		//actions liées au clavier
		keystates = SDL_GetKeyState (keystatesLen);
		if (keystates [SDLK_RIGHT])
		 {
			x =x+2;
			/*TODO*/
		 }
		if (keystates [SDLK_LEFT])
		 {
			x =x-2;
			/*TODO*/
		 }
		if (keystates [SDLK_UP])
		 {
			y =y+2;
			/*TODO*/
		 }
		if (keystates [SDLK_DOWN])
		 {
			y =y-2;
			/*TODO*/
		 }
		 
		// Initialisation de la matrice de modélisation
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Rotation de l'univers
		glRotated(y, 1, 0, 0);
		glRotated(x, 0, 1, 0);

		/* Handle CPU usage cleanly */
		current_time = SDL_GetTicks();
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		last_time = SDL_GetTicks();
		
		
		if (keystates [SDLK_l])
		 {
			skiman->turnLeft();
		 }
		if (keystates [SDLK_r])
		 {
			skiman->turnRight();
		 }
		if (keystates [SDLK_p])
		 {
			skiman->push();
		 }
		if (keystates [SDLK_s])
		 {
			skiman->shoos();
		 }
		if (keystates [SDLK_i])
		 {
			skiman->initialPosition();
		 }
		if (keystates [SDLK_f])
		 {
			skiman->fall();
		 }
		
		// double buffering
		glFlush();
		SDL_GL_SwapBuffers();
	 }

	SDL_Quit();
	return 0;
}
