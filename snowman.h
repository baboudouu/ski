#ifndef SNOWMAN_H_INCLUDED
#define SNOWMAN_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"

class Snowman
{
	public :
		Snowman(GLUquadricObj * quadrique, GLuint ptexture_snowhead, GLuint ptexture_snowbody);
		~Snowman();
		void draw(float x, float y, float z, float size);
	protected :
		GLUquadricObj * quad1;
		GLuint texture_snowhead;
		GLuint texture_snowbody;
};

#endif