#include "snowman.h"

Snowman::Snowman(GLUquadricObj * quadrique, GLuint ptexture_snowhead, GLuint ptexture_snowbody)
{
	this->quad1 = quadrique;
	this->texture_snowhead = ptexture_snowhead;
	this->texture_snowbody = ptexture_snowbody;
}

void Snowman::draw(float x, float y, float z, float size)
{
	glPushMatrix();
		glTranslated(0, 3*size/8,  0);
		//body
		gluQuadricTexture(quad1,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture_snowbody);
		gluQuadricDrawStyle(quad1, GLU_FILL);
		glColor3ub(255, 255, 255);
		glPushMatrix();
			glTranslated(x, y, z);
			glRotated(-130, 1, 0, 0);
			gluSphere(quad1, 2*size/6, 20, 20);
		glPopMatrix();
		
		//head
		glBindTexture(GL_TEXTURE_2D, texture_snowhead);
		glPushMatrix();
			glTranslated(x, y+2.8*size/6, z);
			glRotated(-120, 1, 0, 0);
			gluSphere(quad1, size/6, 20, 20);
		glPopMatrix();
	
		//nose
		gluQuadricTexture(quad1,GL_FALSE);
		glColor3ub(249, 169, 0);
		glPushMatrix();
			glTranslated(x, y+2.8*size/6,  z+0.16*size);
			gluCylinder(quad1, size/25, 0, size/6, 5, 5);
		glPopMatrix();
	
		//arms
		gluQuadricTexture(quad1,GL_FALSE);
		glColor3ub(90, 0, 0);
		glPushMatrix();
			glTranslated(x+0.2*size, y,  z);
			glRotated(-90, 1, 0, 0);
			glRotated(25, 0, 1, 0);
			gluCylinder(quad1, size/60, size/60, size, 4, 4);
		glPopMatrix();
	glPopMatrix();
}

Snowman::~Snowman()
{
}

Snowman * snowman_make(const char * snowman_name)
{
	if(strcmp(snowman_name, 'snowman1') == 0){
	}else{
		return null;
	}
	
	return new Snowman(quad1, texture_snowhead, texture_snowbody);
}


//builder

GLuint make_texture_snowhead = loadTexture("images/snowhead.jpg");
GLuint make_texture_snowbody = loadTexture("images/snowbody.jpg");
GLUquadricObj * make_quad = gluNewQuadric();

Snowman * snowman_make(const char * snowman_name)
{
	if(strcmp(snowman_name, 's1') == 0){
		GLuint snowhead  = make_texture_snowhead;
		GLuint snowbody  = make_texture_snowbody;
	}else{
		return null;
	}
	
	return new Snowman(make_quad, snowhead, snowbody);
}