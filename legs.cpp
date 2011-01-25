#include "legs.h"

#define POSITION_INIT 0
#define POSITION_READY_TO_PUSH 1
#define POSITION_PUSH 2
#define POSITION_TURN_LEFT 3
#define POSITION_TURN_RIGHT 4
#define POSITION_SHOOS 5
#define POSITION_FALLEN 6

Legs::Legs(float px, float py, float pz, GLUquadricObj * quadrique, GLuint ptexture_bas)
{
	this->x = px;
	this->y = py;
	this->z = pz;
	this->position = POSITION_INIT;
	
	this->texture_bas = ptexture_bas;
	this->quad1 = quadrique;
}

void Legs::draw()
{
	switch(this->position){
		case POSITION_INIT:
		case POSITION_READY_TO_PUSH:
		case POSITION_PUSH:
			//left leg
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x+0.11, this->y-0.62,  this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x+0.11, this->y-0.62, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluDisk(quad1, 0, 0.06, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x+0.11, this->y-0.97, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
			glEnd();
			// ski
			gluQuadricTexture(quad1,GL_FALSE);
			glColor3ub(168, 26, 22);
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.41, this->z-0.48);
				glVertex3d(this->x+0.07, this->y-1.41, this->z-0.48);
				glVertex3d(this->x+0.07, this->y-1.41, this->z+1.08);
				glVertex3d(this->x+0.15, this->y-1.41, this->z+1.08);
			glEnd();
			
			//right leg
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x-0.11, this->y-0.62,  this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x-0.11, this->y-0.62, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluDisk(quad1, 0, 0.06, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x-0.11, this->y-0.97, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
			glEnd();
			// ski
			gluQuadricTexture(quad1,GL_FALSE);
			glColor3ub(168, 26, 22);
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.41, this->z-0.48);
				glVertex3d(this->x-0.07, this->y-1.41, this->z-0.48);
				glVertex3d(this->x-0.07, this->y-1.41, this->z+1.08);
				glVertex3d(this->x-0.15, this->y-1.41, this->z+1.08);
			glEnd();
			break;
		case POSITION_TURN_LEFT:
			//left leg
			glPushMatrix();
				glTranslated(0.8, -0.20, 0);
				glRotated(-35, 0, 0, 1);
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.76,  this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.76, this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluDisk(quad1, 0, 0.06, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-1.04, this->z+0.20);
					glRotated(125, 1, 0, 0);
					gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glEnd();
				// ski
				gluQuadricTexture(quad1,GL_FALSE);
				glColor3ub(168, 26, 22);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z+1.08);
					glVertex3d(this->x+0.15, this->y-1.41, this->z+1.08);
				glEnd();
			glPopMatrix();
			
			//right leg
			glPushMatrix();
				glTranslated(0.8, -0.30, 0);
				glRotated(-35, 0, 0, 1);
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x-0.11, this->y-0.76,  this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x-0.11, this->y-0.76, this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluDisk(quad1, 0, 0.06, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x-0.11, this->y-1.04, this->z+0.20);
					glRotated(125, 1, 0, 0);
					gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
				glEnd();
				// ski
				gluQuadricTexture(quad1,GL_FALSE);
				glColor3ub(168, 26, 22);
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.41, this->z-0.48);
					glVertex3d(this->x-0.07, this->y-1.41, this->z-0.48);
					glVertex3d(this->x-0.07, this->y-1.41, this->z+1.08);
					glVertex3d(this->x-0.15, this->y-1.41, this->z+1.08);
				glEnd();
			glPopMatrix();
			break;
		case POSITION_TURN_RIGHT:
			//left leg
			glPushMatrix();
				glTranslated(-0.8, -0.30, 0);
				glRotated(35, 0, 0, 1);
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.76,  this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.76, this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluDisk(quad1, 0, 0.06, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-1.04, this->z+0.20);
					glRotated(125, 1, 0, 0);
					gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glEnd();
				// ski
				gluQuadricTexture(quad1,GL_FALSE);
				glColor3ub(168, 26, 22);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z+1.08);
					glVertex3d(this->x+0.15, this->y-1.41, this->z+1.08);
				glEnd();
			glPopMatrix();
			
			//right leg
			glPushMatrix();
				glTranslated(-0.8, -0.20, 0);
				glRotated(35, 0, 0, 1);
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x-0.11, this->y-0.76,  this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x-0.11, this->y-0.76, this->z-0.03);
					glRotated(55, 1, 0, 0);
					gluDisk(quad1, 0, 0.06, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x-0.11, this->y-1.04, this->z+0.20);
					glRotated(125, 1, 0, 0);
					gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
				glEnd();
				// ski
				gluQuadricTexture(quad1,GL_FALSE);
				glColor3ub(168, 26, 22);
				glBegin(GL_QUADS);
					glVertex3d(this->x-0.15, this->y-1.41, this->z-0.48);
					glVertex3d(this->x-0.07, this->y-1.41, this->z-0.48);
					glVertex3d(this->x-0.07, this->y-1.41, this->z+1.08);
					glVertex3d(this->x-0.15, this->y-1.41, this->z+1.08);
				glEnd();
			glPopMatrix();
			break;
		case POSITION_SHOOS:
			//left leg
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x+0.11, this->y-0.76,  this->z-0.03);
				glRotated(55, 1, 0, 0);
				gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x+0.11, this->y-0.76, this->z-0.03);
				glRotated(55, 1, 0, 0);
				gluDisk(quad1, 0, 0.06, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x+0.11, this->y-1.04, this->z+0.20);
				glRotated(125, 1, 0, 0);
				gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
			glEnd();
			// ski
			gluQuadricTexture(quad1,GL_FALSE);
			glColor3ub(168, 26, 22);
			glBegin(GL_QUADS);
				glVertex3d(this->x+0.15, this->y-1.41, this->z-0.48);
				glVertex3d(this->x+0.07, this->y-1.41, this->z-0.48);
				glVertex3d(this->x+0.07, this->y-1.41, this->z+1.08);
				glVertex3d(this->x+0.15, this->y-1.41, this->z+1.08);
			glEnd();
			
			//right leg
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x-0.11, this->y-0.76,  this->z-0.03);
				glRotated(55, 1, 0, 0);
				gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x-0.11, this->y-0.76, this->z-0.03);
				glRotated(55, 1, 0, 0);
				gluDisk(quad1, 0, 0.06, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x-0.11, this->y-1.04, this->z+0.20);
				glRotated(125, 1, 0, 0);
				gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
				glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.14, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.14, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.15, this->y-1.40, this->z-0.06);
			glEnd();
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.07, this->y-1.36, this->z-0.06);
				glVertex3d(this->x-0.08, this->y-1.37, this->z+0.12);
				glVertex3d(this->x-0.08, this->y-1.40, this->z+0.12);
				glVertex3d(this->x-0.07, this->y-1.40, this->z-0.06);
			glEnd();
			// ski
			gluQuadricTexture(quad1,GL_FALSE);
			glColor3ub(168, 26, 22);
			glBegin(GL_QUADS);
				glVertex3d(this->x-0.15, this->y-1.41, this->z-0.48);
				glVertex3d(this->x-0.07, this->y-1.41, this->z-0.48);
				glVertex3d(this->x-0.07, this->y-1.41, this->z+1.08);
				glVertex3d(this->x-0.15, this->y-1.41, this->z+1.08);
			glEnd();
			break;
		case POSITION_FALLEN:
			glPushMatrix();
				glTranslated(0, -0.8, -0.5);
				glRotated(-90, 1, 0, 0);
				glRotated(-30, 0, 1, 0);
				//left leg
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.62,  this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.62, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.06, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.97, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glEnd();
				// ski
				gluQuadricTexture(quad1,GL_FALSE);
				glColor3ub(168, 26, 22);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z+1.08);
					glVertex3d(this->x+0.15, this->y-1.41, this->z+1.08);
				glEnd();
			glPopMatrix();
			glPushMatrix();
				glTranslated(-0.3, -0.8, -0.55);
				glRotated(-90, 1, 0, 0);
				glRotated(30, 0, 1, 0);
				//left leg
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.62,  this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.06, 0.05, 0.4, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.62, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.06, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.11, this->y-0.97, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.05, 0.04, 0.4, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.14, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.14, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.15, this->y-1.40, this->z-0.06);
				glEnd();
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.07, this->y-1.36, this->z-0.06);
					glVertex3d(this->x+0.08, this->y-1.37, this->z+0.12);
					glVertex3d(this->x+0.08, this->y-1.40, this->z+0.12);
					glVertex3d(this->x+0.07, this->y-1.40, this->z-0.06);
				glEnd();
				// ski
				gluQuadricTexture(quad1,GL_FALSE);
				glColor3ub(168, 26, 22);
				glBegin(GL_QUADS);
					glVertex3d(this->x+0.15, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z-0.48);
					glVertex3d(this->x+0.07, this->y-1.41, this->z+1.08);
					glVertex3d(this->x+0.15, this->y-1.41, this->z+1.08);
				glEnd();
			glPopMatrix();
			break;
		default:
			break;
	}
}

void Legs::initialPosition()
{
	this->position = POSITION_INIT;
}

void Legs::turnLeft()
{
	this->position = POSITION_TURN_LEFT;
}

void Legs::turnRight()
{
	this->position = POSITION_TURN_RIGHT;
}

void Legs::push()
{
	switch(this->position){
		case POSITION_PUSH:
			this->position = POSITION_INIT;
			break;
		case POSITION_READY_TO_PUSH:
			this->position = POSITION_PUSH;
			break;
		default :
			this->position = POSITION_READY_TO_PUSH;
			break;
	}
}

void Legs::shoos()
{
	this->position = POSITION_SHOOS;
}

void Legs::fall()
{
	this->position = POSITION_FALLEN;
}

Legs::~Legs()
{
}