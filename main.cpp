#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"

#define WIDTH 600
#define HEIGHT 400

#define PAS 1

#define FRAMES_PER_SECOND 25

int main(int argc, char * argv[])
{
    double x = 0;
    double z = 0;
    int alpha = 5;
    Uint8 *keystates = NULL;
    int *keystatesLen = NULL;
    GLUquadricObj * quad1;
    GLuint wall_texture, floor_texture, baril_texture, top_baril_texture;

    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time;

	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	SDL_WM_SetCaption("Hangard", NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective (70, (double) WIDTH / HEIGHT, 1, 100);
	SDL_Flip(ecran);

	bool continuer = true;
	SDL_Event event;
	SDL_EnableKeyRepeat(10,10);
    glEnable(GL_TEXTURE_2D);

  /* Loading all textutres */
  wall_texture = loadTexture("/home/thiblahute/src/opengl/hangar/textures/wall.jpg");
  floor_texture = loadTexture("/home/thiblahute/src/opengl/hangar/textures/floor.jpg");
  top_baril_texture = loadTexture("/home/thiblahute/src/opengl/hangar/textures/barril2.jpg");
  baril_texture = loadTexture("/home/thiblahute/src/opengl/hangar/textures/barril1.jpg");

  quad1 = gluNewQuadric();
  gluQuadricTexture(quad1, GL_TRUE);

	while (continuer)
      {
        SDL_PollEvent(&event);

        switch(event.type)
          {
            case SDL_QUIT: // fin
            continuer = false;
            break;
          }

        glEnable(GL_DEPTH_TEST);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gluLookAt(5,2,-7,0,0,0,0,1,0);

        keystates = SDL_GetKeyState (keystatesLen);
        if (keystates [SDLK_RIGHT])
            {
                printf("alpha %i", alpha);
                alpha = alpha + 1;
                printf("Alpha %i\n", alpha);
            }
        if (keystates [SDLK_LEFT])
            {
                alpha = alpha + 1;
            }
        if (keystates [SDLK_UP])
            {
                x = x + PAS * cos((alpha * M_PI) / 180);
                z = z + PAS * sin((alpha * M_PI) / 180);
            }
        if (keystates [SDLK_DOWN])
            {
                printf("Down %i", x);
                x = x - (PAS * cos((alpha * M_PI) / 180));
                z = z - (PAS * sin((alpha * M_PI) / 180));
                printf("Down %%i %i\n", x, (PAS * cos((alpha * M_PI) / 180)));
            }

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(x, 2, z, x+10, 1.5, z, 0, 1, 0);

        /* Handle CPU usage cleanly */
        current_time = SDL_GetTicks();
        while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
            SDL_Delay(1000/FRAMES_PER_SECOND - (current_time - last_time));
            current_time = SDL_GetTicks();
        }
        last_time = SDL_GetTicks();

        glClearColor(0.6, 0.6, 0.6, 1);

        /* Floor */
        glBindTexture(GL_TEXTURE_2D, floor_texture);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0,1); glVertex3d(-15,0, -15);
        glTexCoord2d(1,1); glVertex3d(-15,0, 15);
        glTexCoord2d(1,0); glVertex3d(15,0, 15);
        glTexCoord2d(0,0); glVertex3d(15,0, -15);
        glEnd();

        /* Walls */
        glBindTexture(GL_TEXTURE_2D, wall_texture);

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0,1); glVertex3d(-15, 0, -15);
        glTexCoord2d(1,1); glVertex3d(-15, 3, -15);
        glTexCoord2d(1,0); glVertex3d(-15, 3, 15);
        glTexCoord2d(0,0);  glVertex3d(-15, 0, 15);
        glEnd();
        
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0,1); glVertex3d(-15, 0, 15);
        glTexCoord2d(1,1); glVertex3d(-15, 3, 15);
        glTexCoord2d(1,0); glVertex3d(15, 3, 15);
        glTexCoord2d(0,0); glVertex3d(15, 0, 15);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(200, 200,200);
        glTexCoord2d(0,1); glVertex3d(15, 0, 15);
        glTexCoord2d(1,1); glVertex3d(15, 3, 15);
        glTexCoord2d(1,0); glVertex3d(15, 3, -15);
        glTexCoord2d(0,0); glVertex3d(15, 0, -15);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255,255, 255);
        glTexCoord2d(0,1); glVertex3d(-15,0, -15);
        glTexCoord2d(1,1); glVertex3d(-15,3, -15);
        glTexCoord2d(1,0); glVertex3d(15,3, -15);
        glTexCoord2d(0,0); glVertex3d(15,0, -15);
        glEnd();

        // Affichage (en double buffering)
        glFlush();
        SDL_GL_SwapBuffers();
      }

	SDL_Quit();
	return 0;
}
