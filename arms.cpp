#include "arms.h"

#define POSITION_INIT 0
#define POSITION_READY_TO_PUSH 1
#define POSITION_PUSH 2
#define POSITION_TURN_LEFT 3
#define POSITION_TURN_RIGHT 4
#define POSITION_SHOOS 5
#define POSITION_FALLEN 6

Arms::Arms(float px, float py, float pz, GLUquadricObj * quadrique, GLuint ptexture_bas)
{
	this->x = px;
	this->y = py;
	this->z = pz;
	this->position = POSITION_INIT;
	
	this->texture_bas = ptexture_bas;
	this->quad1 = quadrique;
}

void Arms::draw()
{
	switch(this->position){
		case POSITION_INIT:
			//left arm
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.39, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.66, this->z-0.02);
				gluSphere(quad1, 0.05, 15, 15);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.64, this->z+0.02);
				glRotated(40, 1, 0, 0);
				gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
			glPopMatrix();
			//baston
			glColor3ub(132, 132, 132);
			glPushMatrix();
				glTranslated(this->x+0.185, this->y-0.66, this->z-0.02);
				glRotated(180, 1, 0, 0);
				gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x+0.185, this->y-0.66, this->z+-0.75);
				glRotated(180, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 10, 10);
			glPopMatrix();
			
			//right arm
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.39, this->z-0.02);
				glRotated(90, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.66, this->z-0.02);
				gluSphere(quad1, 0.05, 15, 15);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.64, this->z+0.02);
				glRotated(40, 1, 0, 0);
				gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
			glPopMatrix();
			//baston
			glColor3ub(132, 132, 132);
			glPushMatrix();
				glTranslated(this->x-0.185, this->y-0.66, this->z-0.02);
				glRotated(180, 1, 0, 0);
				gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x-0.185, this->y-0.66, this->z+-0.75);
				glRotated(180, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 10, 10);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			break;
		case POSITION_READY_TO_PUSH:
			//left arm
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glColor3ub(68, 86, 122);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
				glRotated(45, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
				glRotated(45, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.34, this->z+0.17);
				glRotated(-30, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.22, this->z+0.38);
				gluSphere(quad1, 0.05, 15, 15);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x+0.19, this->y-0.18, this->z+0.36);
				glRotated(-60, 1, 0, 0);
				gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
			glPopMatrix();
			//baston
			glColor3ub(132, 132, 132);
			glPushMatrix();
				glTranslated(this->x+0.185, this->y-0.20, this->z+0.37);
				glRotated(60, 1, 0, 0);
				gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x+0.185, this->y-0.82, this->z+0.73);
				glRotated(60, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 10, 10);
			glPopMatrix();
			
			//right arm
			glColor3ub(68, 86, 122);
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
				glRotated(45, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
				glRotated(45, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 15, 15);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture_bas);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.34, this->z+0.17);
				glRotated(-30, 1, 0, 0);
				gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
			glPopMatrix();
			glColor3ub(0, 0, 0);
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.22, this->z+0.38);
				gluSphere(quad1, 0.05, 15, 15);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x-0.19, this->y-0.18, this->z+0.36);
				glRotated(-60, 1, 0, 0);
				gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
			glPopMatrix();
			//baston
			glColor3ub(132, 132, 132);
			glPushMatrix();
				glTranslated(this->x-0.185, this->y-0.20, this->z+0.37);
				glRotated(60, 1, 0, 0);
				gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
			glPopMatrix();
			glPushMatrix();
				glTranslated(this->x-0.185, this->y-0.82, this->z+0.73);
				glRotated(60, 1, 0, 0);
				gluDisk(quad1, 0, 0.04, 10, 10);
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			break;
		case POSITION_PUSH:
			glPushMatrix();
				glTranslated(0, -0.18, 0.17);
				glRotated(-45, 1, 0, 0);
				//left arm
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.39, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(0, -0.14, -0.47);
					glRotated(-45, 1, 0, 0);
					glPushMatrix();
						glTranslated(this->x+0.19, this->y-0.66, this->z-0.02);
						gluSphere(quad1, 0.05, 15, 15);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x+0.19, this->y-0.64, this->z+0.02);
						glRotated(40, 1, 0, 0);
						gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
					glPopMatrix();
					//baston
					glColor3ub(132, 132, 132);
					glPushMatrix();
						glTranslated(this->x+0.185, this->y-0.66, this->z-0.02);
						glRotated(180, 1, 0, 0);
						gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x+0.185, this->y-0.66, this->z-0.81);
						glRotated(180, 1, 0, 0);
						gluDisk(quad1, 0, 0.04, 10, 10);
					glPopMatrix();
				glPopMatrix();
				
				//right arm
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.39, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(0, -0.14, -0.47);
					glRotated(-45, 1, 0, 0);
					glPushMatrix();
						glTranslated(this->x-0.19, this->y-0.66, this->z-0.02);
						gluSphere(quad1, 0.05, 15, 15);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x-0.19, this->y-0.64, this->z+0.02);
						glRotated(40, 1, 0, 0);
						gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
					glPopMatrix();
					//baston
					glColor3ub(132, 132, 132);
					glPushMatrix();
						glTranslated(this->x-0.185, this->y-0.66, this->z-0.02);
						glRotated(180, 1, 0, 0);
						gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x-0.185, this->y-0.66, this->z+-0.81);
						glRotated(180, 1, 0, 0);
						gluDisk(quad1, 0, 0.04, 10, 10);
					glPopMatrix();
					gluQuadricTexture(quad1,GL_FALSE);
				glPopMatrix();
			glPopMatrix();
			break;
		case POSITION_TURN_LEFT:
			glPushMatrix();
				glTranslated(0.37, -0.27, -0.04);
				//left arm
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(45, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(45, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.34, this->z+0.17);
					glRotated(-30, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.22, this->z+0.38);
					gluSphere(quad1, 0.05, 15, 15);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.18, this->z+0.36);
					glRotated(-60, 1, 0, 0);
					gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.20, this->z+0.37);
					glRotated(60, 1, 0, 0);
					gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.82, this->z+0.73);
					glRotated(60, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 10, 10);
				glPopMatrix();
				
				//right arm
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.39, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.66, this->z-0.02);
					gluSphere(quad1, 0.05, 15, 15);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.64, this->z+0.02);
					glRotated(40, 1, 0, 0);
					gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(this->x-0.185, this->y-0.66, this->z-0.02);
					glRotated(180, 1, 0, 0);
					gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x-0.185, this->y-0.66, this->z+-0.75);
					glRotated(180, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 10, 10);
				glPopMatrix();
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			break;
		case POSITION_TURN_RIGHT:
			glPushMatrix();
				glTranslated(-0.37, -0.27, -0.04);
				//left arm
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.39, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.66, this->z-0.02);
					gluSphere(quad1, 0.05, 15, 15);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.64, this->z+0.02);
					glRotated(40, 1, 0, 0);
					gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.66, this->z-0.02);
					glRotated(180, 1, 0, 0);
					gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.66, this->z+-0.75);
					glRotated(180, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 10, 10);
				glPopMatrix();
			
				//right arm
				glColor3ub(68, 86, 122);
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
					glRotated(45, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
					glRotated(45, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.34, this->z+0.17);
					glRotated(-30, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.22, this->z+0.38);
					gluSphere(quad1, 0.05, 15, 15);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x-0.19, this->y-0.18, this->z+0.36);
					glRotated(-60, 1, 0, 0);
					gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(this->x-0.185, this->y-0.20, this->z+0.37);
					glRotated(60, 1, 0, 0);
					gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x-0.185, this->y-0.82, this->z+0.73);
					glRotated(60, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 10, 10);
				glPopMatrix();
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			break;
		case POSITION_SHOOS:
			glPushMatrix();
				glTranslated(0, -0.4, 0.37);
				//left arm
				glPushMatrix();
					glTranslated(-0.08, -0.24, -0.02);
					glRotated(60, 0, 0, 1);
					gluQuadricTexture(quad1,GL_TRUE);
					glBindTexture(GL_TEXTURE_2D, texture_bas);
					glColor3ub(68, 86, 122);
					glPushMatrix();
						glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
						glRotated(45, 1, 0, 0);
						gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
					glPopMatrix();
					gluQuadricTexture(quad1,GL_FALSE);
					glPushMatrix();
						glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
						glRotated(45, 1, 0, 0);
						gluDisk(quad1, 0, 0.04, 15, 15);
					glPopMatrix();
					gluQuadricTexture(quad1,GL_TRUE);
					glPushMatrix();
						glTranslated(this->x+0.205, this->y-0.335, this->z+0.165);
						glRotated(90, 0, 0, 1);
						glRotated(-60, 1, 0, 0);
						gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
					glPopMatrix();
					glColor3ub(0, 0, 0);
					glPushMatrix();
						glTranslated(this->x-0.03, this->y-0.35, this->z+0.3);
						gluSphere(quad1, 0.05, 15, 15);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x-0.02, this->y-0.32, this->z+0.32);
						gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
					glPopMatrix();
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(0, -0.48, 0.7);
					glRotated(155, 1, 0, 0);
					glPushMatrix();
						glTranslated(this->x+0.185, this->y-0.20, this->z+0.37);
						glRotated(60, 1, 0, 0);
						gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x+0.185, this->y-0.82, this->z+0.73);
						glRotated(60, 1, 0, 0);
						gluDisk(quad1, 0, 0.04, 10, 10);
					glPopMatrix();
				glPopMatrix();
				
				//right arm
				glPushMatrix();
					glTranslated(0.08, -0.24, -0.02);
					glRotated(-60, 0, 0, 1);
					gluQuadricTexture(quad1,GL_TRUE);
					glBindTexture(GL_TEXTURE_2D, texture_bas);
					glColor3ub(68, 86, 122);
					glPushMatrix();
						glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
						glRotated(45, 1, 0, 0);
						gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
					glPopMatrix();
					gluQuadricTexture(quad1,GL_FALSE);
					glPushMatrix();
						glTranslated(this->x-0.19, this->y-0.14, this->z-0.02);
						glRotated(45, 1, 0, 0);
						gluDisk(quad1, 0, 0.04, 15, 15);
					glPopMatrix();
					gluQuadricTexture(quad1,GL_TRUE);
					glPushMatrix();
						glTranslated(this->x-0.205, this->y-0.335, this->z+0.165);
						glRotated(-90, 0, 0, 1);
						glRotated(-60, 1, 0, 0);
						gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
					glPopMatrix();
					glColor3ub(0, 0, 0);
					glPushMatrix();
						glTranslated(this->x+0.03, this->y-0.35, this->z+0.3);
						gluSphere(quad1, 0.05, 15, 15);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x+0.02, this->y-0.32, this->z+0.32);
						gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
					glPopMatrix();
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(0, -0.48, 0.7);
					glRotated(155, 1, 0, 0);
					glPushMatrix();
						glTranslated(this->x-0.185, this->y-0.20, this->z+0.37);
						glRotated(60, 1, 0, 0);
						gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
					glPopMatrix();
					glPushMatrix();
						glTranslated(this->x-0.185, this->y-0.82, this->z+0.73);
						glRotated(60, 1, 0, 0);
						gluDisk(quad1, 0, 0.04, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			gluQuadricTexture(quad1,GL_FALSE);
			break;
		case POSITION_FALLEN:
			//left arm
			glPushMatrix();
				glTranslated(0.3, -0.9, 0);
				glRotated(90, 0, 0, 1);
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_bas);
				glColor3ub(68, 86, 122);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.04, 0.3, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.14, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 15, 15);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_TRUE);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.39, this->z-0.02);
					glRotated(90, 1, 0, 0);
					gluCylinder(quad1, 0.04, 0.035, 0.23, 15, 15);
				glPopMatrix();
				glColor3ub(0, 0, 0);
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.66, this->z-0.02);
					gluSphere(quad1, 0.05, 15, 15);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.19, this->y-0.64, this->z+0.02);
					glRotated(40, 1, 0, 0);
					gluCylinder(quad1, 0.015, 0.01, 0.05, 15, 15);
				glPopMatrix();
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.66, this->z-0.02);
					glRotated(180, 1, 0, 0);
					gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.66, this->z+-0.75);
					glRotated(180, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 10, 10);
				glPopMatrix();
			glPopMatrix();
			
			glPushMatrix();
				glTranslated(0, 0, 0.6);
				glRotated(90, 0, 1, 0);
				//baston
				glColor3ub(132, 132, 132);
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.66, this->z-0.02);
					glRotated(180, 1, 0, 0);
					gluCylinder(quad1, 0.01, 0.01, 0.8, 5, 5);
				glPopMatrix();
				glPushMatrix();
					glTranslated(this->x+0.185, this->y-0.66, this->z+-0.75);
					glRotated(180, 1, 0, 0);
					gluDisk(quad1, 0, 0.04, 10, 10);
				glPopMatrix();
			glPopMatrix();
			break;
		default:
			break;
	}
}

void Arms::initialPosition()
{
	this->position = POSITION_INIT;
}

void Arms::turnLeft()
{
	this->position = POSITION_TURN_LEFT;
}

void Arms::turnRight()
{
	this->position = POSITION_TURN_RIGHT;
}

void Arms::push()
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

void Arms::shoos()
{
	this->position = POSITION_SHOOS;
}

void Arms::fall()
{
	this->position = POSITION_FALLEN;
}

Arms::~Arms()
{
}