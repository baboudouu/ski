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
	
	//quadrique
	GLUquadricObj * quad1 = gluNewQuadric();
	
	//skiman
	Skiman * skiman;

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
	GLuint texture_snow = loadTexture("images/snow.jpg");
	GLuint texture_face = loadTexture("images/face.jpg");
	GLuint texture_clothes = loadTexture("images/clothes.jpg");
	GLuint texture_sleeve = loadTexture("images/sleeve.jpg");
	GLuint texture_tree = loadTexture("images/sleeve.jpg");
	GLuint texture_snowhead = loadTexture("images/snowhead.jpg");
	GLuint texture_snowbody = loadTexture("images/snowbody.jpg");

	// Boucle d'évènements
	SDL_Event event;
	SDL_EnableKeyRepeat(10,10);
	
	skiman = new Skiman(0, 0, 0, quad1, texture_face, texture_clothes, texture_sleeve, texture_snow);
	
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
		
		
		//~ skiman->draw();
		//~ Tree * arbre = new Tree(quad1, texture_tree);
		//~ arbre->draw(0, 0, 0, 1);
		//~ arbre->draw(1.2, 0, 1.2, 0.5);
		Snowman * bonhomme = new Snowman(quad1, texture_snowhead, texture_snowbody);
		bonhomme->draw(0, 0, 0, 1);
		
		
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
