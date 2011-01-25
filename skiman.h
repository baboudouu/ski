#ifndef SKIMAN_H_INCLUDED
#define SKIMAN_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"

#include "legs.h"
#include "arms.h"

class Skiman
{
	public :
		Skiman(float px, float py, float pz, GLUquadricObj * quadrique, GLuint ptexture_visage, GLuint ptexture_haut, GLuint ptexture_bas, GLuint ptexture_snow);
		~Skiman();
		void draw();
		void initialPosition();
		void turnLeft();
		void turnRight();
		void push();
		void shoos();
		void fall();
	protected:
		float x;
		float y;
		float z;
		int position;
		Legs * legs;
		Arms * arms;
		GLUquadricObj * quad1;
		GLuint texture_visage;
		GLuint texture_haut;
		GLuint texture_snow;
};

#endif