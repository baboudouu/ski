#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"

class Tree
{
	public :
		Tree(GLUquadricObj * quadrique, GLuint ptexture_arbre);
		~Tree();
		void draw(float x, float y, float z, float size);
	protected :
		GLUquadricObj * quad1;
		GLuint texture_arbre;
};

#endif