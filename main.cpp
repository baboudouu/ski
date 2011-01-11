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
  double x = 0;
  double z = 0;
  int alpha = 5;
  bool continuer = true;
  Uint8 *keystates = NULL;
   int *keystatesLen = NULL;

   Uint32 last_time = SDL_GetTicks();
  Uint32 current_time;

  // Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

  SDL_WM_SetCaption("Ski", NULL);
  SDL_Surface* ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluPerspective (70, (double) WIDTH / HEIGHT, 1, 100);
  SDL_Flip(ecran);

  SDL_Event event;
  SDL_EnableKeyRepeat(10,10);
  glEnable(GL_TEXTURE_2D);

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
      /*TODO*/
     }
    if (keystates [SDLK_LEFT])
     {
      /*TODO*/
     }
    if (keystates [SDLK_UP])
     {
      /*TODO*/
     }
    if (keystates [SDLK_DOWN])
     {
      /*TODO*/
     }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(x, 2, z, x+10, 1.5, z, 0, 1, 0);

    /* Handle CPU usage cleanly */
    current_time = SDL_GetTicks();
    while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
      SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
      current_time = SDL_GetTicks();
    }
    last_time = SDL_GetTicks();

    // double buffering
    glFlush();
    SDL_GL_SwapBuffers();
   }

  SDL_Quit();
  return 0;
}
