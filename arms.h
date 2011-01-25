#ifndef ARMS_H_INCLUDED
#define ARMS_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"

class Arms
{
	public :
		Arms(float px, float py, float pz, GLUquadricObj * quadrique, GLuint ptexture_bas);
		~Arms();
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
		GLUquadricObj * quad1;
		GLuint texture_bas;
};

#endif