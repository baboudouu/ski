#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"

#define WIDTH 600
#define HEIGHT 400

#define FRAMES_PER_SECOND 25

int main(int argc, char * argv[])
{
	
	int alpha = 5;
	bool continuer;
	
	//variables liées à la rotation de l'univers
	double x = -30;
	double y = 0;
	Uint8 *keystates = NULL;
	int *keystatesLen = NULL;

	//heure actuelle, derniere mise à jour
	Uint32 last_time = SDL_GetTicks();
	Uint32 current_time;
	
	//quadrique
	GLUquadricObj * quad1 = gluNewQuadric();

	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Création de la surface d'affichage qui est en OpenGL
	SDL_WM_SetCaption("Ski", NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

	// Initialisation de l'affichage OpenGL
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective (70, (double) WIDTH / HEIGHT, 1, 1000);
	SDL_Flip(ecran);
	glEnable(GL_TEXTURE_2D);
	GLuint texture_visage = loadTexture("images/visage.jpg");
	GLuint texture_haut= loadTexture("images/vetement_haut.jpg");
	GLuint texture_bas= loadTexture("images/vetement_bas.jpg");

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

		//~ glMatrixMode(GL_PROJECTION);
		//~ glLoadIdentity();
		//~ gluPerspective (70, (double) WIDTH / HEIGHT, 1, 1000);
		//~ glMatrixMode(GL_MODELVIEW);
		//~ glLoadIdentity();
		
		// Placement de la caméra
		gluLookAt(1.5, -0.5, 0, 0, -0.5, 0, 0, 1, 0);
		
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
		
		//tete
		gluQuadricTexture(quad1,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture_visage);
		gluQuadricDrawStyle(quad1, GLU_FILL);
		glColor3ub(174, 86, 35);
		glPushMatrix();
			glRotated(-90, 1, 0, 0);
			gluSphere(quad1, 0.13, 20, 20);
		glPopMatrix();
			
		//corps
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, texture_haut);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1);
			glVertex3d(-0.15, -0.12, -0.05);
			glTexCoord2d(1, 1);
			glVertex3d(0.15, -0.12, -0.05);
			glTexCoord2d(1, 0);
			glVertex3d(0.15, -0.12, 0.05);
			glTexCoord2d(0, 0);
			glVertex3d(-0.15, -0.12, 0.05);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1);
			glVertex3d(-0.15, -0.62, -0.05);
			glTexCoord2d(1, 1);
			glVertex3d(0.15, -0.62, -0.05);
			glTexCoord2d(1, 0);
			glVertex3d(0.15, -0.62, 0.05);
			glTexCoord2d(0, 0);
			glVertex3d(-0.15, -0.62, 0.05);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1);
			glVertex3d(-0.15, -0.12, -0.05);
			glTexCoord2d(0.5, 1);
			glVertex3d(0.15, -0.12, -0.05);
			glTexCoord2d(0.5, 0);
			glVertex3d(0.15, -0.62, -0.05);
			glTexCoord2d(0, 0);
			glVertex3d(-0.15, -0.62, -0.05);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1);
			glVertex3d(-0.15, -0.12, 0.05);
			glTexCoord2d(0.5, 1);
			glVertex3d(0.15, -0.12, 0.05);
			glTexCoord2d(0.5, 0);
			glVertex3d(0.15, -0.62, 0.05);
			glTexCoord2d(0, 0);
			glVertex3d(-0.15, -0.62, 0.05);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1);
			glVertex3d(-0.15, -0.12, -0.05);
			glTexCoord2d(0.2, 1);
			glVertex3d(-0.15, -0.12, 0.05);
			glTexCoord2d(0.2, 0);
			glVertex3d(-0.15, -0.62, 0.05);
			glTexCoord2d(0, 0);
			glVertex3d(-0.15, -0.62, -0.05);
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1);
			glVertex3d(0.15, -0.12, -0.05);
			glTexCoord2d(0.2, 1);
			glVertex3d(0.15, -0.12, 0.05);
			glTexCoord2d(0.2, 0);
			glVertex3d(0.15, -0.62, 0.05);
			glTexCoord2d(0, 0);
			glVertex3d(0.15, -0.62, -0.05);
		glEnd();
			
		//bras
		glColor3ub(68, 86, 122);
		gluQuadricTexture(quad1,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture_bas);
		glPushMatrix();
			glTranslated(-0.15, -0.14, -0.02);
			glRotated(45, 1, 0, 0);
			gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslated(-0.15, -0.34, 0.17);
			glRotated(-30, 1, 0, 0);
			gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
		glPopMatrix();
		glColor3ub(0, 0, 0);
		glPushMatrix();
			glTranslated(-0.15, -0.22, 0.38);
			gluSphere(quad1, 0.05, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslated(-0.15, -0.18, 0.36);
			glRotated(-60, 1, 0, 0);
			gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
		glPopMatrix();
		
		glColor3ub(68, 86, 122);
		glPushMatrix();
			glTranslated(0.15, -0.14, -0.02);
			glRotated(45, 1, 0, 0);
			gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslated(0.15, -0.34, 0.17);
			glRotated(-30, 1, 0, 0);
			gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
		glPopMatrix();
		glColor3ub(0, 0, 0);
		glPushMatrix();
			glTranslated(0.15, -0.22, 0.38);
			gluSphere(quad1, 0.05, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslated(0.15, -0.18, 0.36);
			glRotated(-60, 1, 0, 0);
			gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
		glPopMatrix();
			
		//jambes
		glColor3ub(68, 86, 122);
		glPushMatrix();
			glTranslated(0.11, -0.62, -0.02);
			glRotated(45, 1, 0, 0);
			gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslated(0.11, -0.87, 0.25);
			glRotated(90, 1, 0, 0);
			gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glColor3ub(0, 0, 0);
			glRotated(-30, 1, 0, 0);
			glTranslated(0, 0.06, -0.67);
			glBegin(GL_QUADS);
				glVertex3d(0.15, -1.26, 0.22);
				glVertex3d(0.07, -1.26, 0.22);
				glVertex3d(0.08, -1.27, 0.40);
				glVertex3d(0.14, -1.27, 0.40);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(0.15, -1.30, 0.22);
				glVertex3d(0.07, -1.30, 0.22);
				glVertex3d(0.08, -1.30, 0.40);
				glVertex3d(0.14, -1.30, 0.40);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(0.15, -1.26, 0.22);
				glVertex3d(0.07, -1.26, 0.22);
				glVertex3d(0.07, -1.30, 0.22);
				glVertex3d(0.15, -1.30, 0.22);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(0.08, -1.27, 0.40);
				glVertex3d(0.14, -1.27, 0.40);
				glVertex3d(0.14, -1.30, 0.40);
				glVertex3d(0.08, -1.30, 0.40);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(0.15, -1.26, 0.22);
				glVertex3d(0.14, -1.27, 0.40);
				glVertex3d(0.14, -1.30, 0.40);
				glVertex3d(0.15, -1.30, 0.22);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(0.07, -1.26, 0.22);
				glVertex3d(0.08, -1.27, 0.40);
				glVertex3d(0.08, -1.30, 0.40);
				glVertex3d(0.07, -1.30, 0.22);
			glEnd();
			
			// ski
			gluQuadricTexture(quad1,GL_FALSE);
			glColor3ub(168, 26, 22);
			glBegin(GL_QUADS);
				glVertex3d(0.15, -1.30, -0.2);
				glVertex3d(0.07, -1.30, -0.2);
				glVertex3d(0.07, -1.30, 1.2);
				glVertex3d(0.15, -1.30, 1.2);
			glEnd();
		glPopMatrix();
		
		gluQuadricTexture(quad1,GL_TRUE);
		glColor3ub(68, 86, 122);
		glPushMatrix();
			glTranslated(-0.11, -0.62, -0.02);
			glRotated(45, 1, 0, 0);
			gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslated(-0.11, -0.87, 0.25);
			glRotated(90, 1, 0, 0);
			gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
		glPopMatrix();
		glPushMatrix();
			glColor3ub(0, 0, 0);
			glRotated(-30, 1, 0, 0);
			glTranslated(0, 0.06, -0.67);
			glBegin(GL_QUADS);
				glVertex3d(-0.15, -1.26, 0.22);
				glVertex3d(-0.07, -1.26, 0.22);
				glVertex3d(-0.08, -1.27, 0.40);
				glVertex3d(-0.14, -1.27, 0.40);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(-0.15, -1.30, 0.22);
				glVertex3d(-0.07, -1.30, 0.22);
				glVertex3d(-0.08, -1.30, 0.40);
				glVertex3d(-0.14, -1.30, 0.40);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(-0.15, -1.26, 0.22);
				glVertex3d(-0.07, -1.26, 0.22);
				glVertex3d(-0.07, -1.30, 0.22);
				glVertex3d(-0.15, -1.30, 0.22);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(-0.08, -1.27, 0.40);
				glVertex3d(-0.14, -1.27, 0.40);
				glVertex3d(-0.14, -1.30, 0.40);
				glVertex3d(-0.08, -1.30, 0.40);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(-0.15, -1.26, 0.22);
				glVertex3d(-0.14, -1.27, 0.40);
				glVertex3d(-0.14, -1.30, 0.40);
				glVertex3d(-0.15, -1.30, 0.22);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(-0.07, -1.26, 0.22);
				glVertex3d(-0.08, -1.27, 0.40);
				glVertex3d(-0.08, -1.30, 0.40);
				glVertex3d(-0.07, -1.30, 0.22);
			glEnd();
			
			// ski
			gluQuadricTexture(quad1,GL_FALSE);
			glColor3ub(168, 26, 22);
			glBegin(GL_QUADS);
				glVertex3d(-0.15, -1.30, -0.2);
				glVertex3d(-0.07, -1.30, -0.2);
				glVertex3d(-0.07, -1.30, 1.2);
				glVertex3d(-0.15, -1.30, 1.2);
			glEnd();
		glPopMatrix();
	

		// double buffering
		glFlush();
		SDL_GL_SwapBuffers();
	 }

	SDL_Quit();
	return 0;
}
