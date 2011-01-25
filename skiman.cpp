#include "skiman.h"

#define POSITION_INIT 0
#define POSITION_READY_TO_PUSH 1
#define POSITION_PUSH 2
#define POSITION_TURN_LEFT 3
#define POSITION_TURN_RIGHT 4
#define POSITION_SHOOS 5
#define POSITION_FALLEN 6

Skiman::Skiman(float px, float py, float pz, GLUquadricObj * quadrique, GLuint ptexture_visage, GLuint ptexture_haut, GLuint ptexture_bas, GLuint ptexture_snow)
{
	this->x = px;
	this->y = py;
	this->z = pz;
	this->position = POSITION_INIT;
	
	this->texture_visage = ptexture_visage;
	this->texture_haut = ptexture_haut;
	this->texture_snow = ptexture_snow;
	this->quad1 = quadrique;
	
	this->legs = new Legs(px, py, pz, quadrique, ptexture_bas);
	this->arms = new Arms(px, py, pz, quadrique, ptexture_bas);
}

void Skiman::draw()
{
	glPushMatrix();
		glTranslated(0, 1.41, 0);
		switch(this->position){
			case POSITION_INIT:
			case POSITION_READY_TO_PUSH:
				//head
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_visage);
				gluQuadricDrawStyle(quad1, GLU_FILL);
				glColor3ub(174, 86, 35);
				glPushMatrix();
					glTranslated(this->x, this->y, this->z);
					glRotated(-90, 1, 0, 0);
					gluSphere(quad1, 0.13, 20, 20);
				glPopMatrix();
				
				//body
				glColor3ub(255, 255, 255);
				glBindTexture(GL_TEXTURE_2D, texture_haut);
				glBegin(GL_QUADS);
					glTexCoord2d(0, 1);
					glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
					glTexCoord2d(1, 1);
					glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
					glTexCoord2d(1, 0);
					glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
					glTexCoord2d(0, 0);
					glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
				glEnd();
				glBegin(GL_QUADS);
					glTexCoord2d(0, 1);
					glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glTexCoord2d(1, 1);
					glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
					glTexCoord2d(1, 0);
					glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
					glTexCoord2d(0, 0);
					glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
				glEnd();
				glBegin(GL_QUADS);
					glTexCoord2d(0, 1);
					glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
					glTexCoord2d(0.5, 1);
					glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
					glTexCoord2d(0.5, 0);
					glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
					glTexCoord2d(0, 0);
					glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
				glEnd();
				glBegin(GL_QUADS);
					glTexCoord2d(0, 1);
					glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
					glTexCoord2d(0.5, 1);
					glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
					glTexCoord2d(0.5, 0);
					glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
					glTexCoord2d(0, 0);
					glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
				glEnd();
				glBegin(GL_QUADS);
					glTexCoord2d(0, 1);
					glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
					glTexCoord2d(0.2, 1);
					glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
					glTexCoord2d(0.2, 0);
					glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glTexCoord2d(0, 0);
					glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
				glEnd();
				glBegin(GL_QUADS);
					glTexCoord2d(0, 1);
					glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
					glTexCoord2d(0.2, 1);
					glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
					glTexCoord2d(0.2, 0);
					glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
					glTexCoord2d(0, 0);
					glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
				glEnd();
				gluQuadricTexture(quad1,GL_FALSE);
				break;
			case POSITION_PUSH:
				glPushMatrix();
					glTranslated(0, -0.21, 0.40);
					glRotated(45, 1, 0, 0);
					//head
					gluQuadricTexture(quad1,GL_TRUE);
					glBindTexture(GL_TEXTURE_2D, texture_visage);
					gluQuadricDrawStyle(quad1, GLU_FILL);
					glColor3ub(174, 86, 35);
					glPushMatrix();
						glTranslated(this->x, this->y, this->z);
						glRotated(-90, 1, 0, 0);
						gluSphere(quad1, 0.13, 20, 20);
					glPopMatrix();
					
					//body
					glColor3ub(255, 255, 255);
					glBindTexture(GL_TEXTURE_2D, texture_haut);
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
					glEnd();
					gluQuadricTexture(quad1,GL_FALSE);
				glPopMatrix();
				break;
			case POSITION_TURN_LEFT:
				glPushMatrix();
					glTranslated(0.37, -0.27, -0.04);
					//head
					gluQuadricTexture(quad1,GL_TRUE);
					glBindTexture(GL_TEXTURE_2D, texture_visage);
					gluQuadricDrawStyle(quad1, GLU_FILL);
					glColor3ub(174, 86, 35);
					glPushMatrix();
						glTranslated(this->x, this->y, this->z);
						glRotated(-90, 1, 0, 0);
						gluSphere(quad1, 0.13, 20, 20);
					glPopMatrix();
					
					//body
					glColor3ub(255, 255, 255);
					glBindTexture(GL_TEXTURE_2D, texture_haut);
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
					glEnd();
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				break;
			case POSITION_TURN_RIGHT:
				glPushMatrix();
					glTranslated(-0.37, -0.27, -0.04);
					//head
					gluQuadricTexture(quad1,GL_TRUE);
					glBindTexture(GL_TEXTURE_2D, texture_visage);
					gluQuadricDrawStyle(quad1, GLU_FILL);
					glColor3ub(174, 86, 35);
					glPushMatrix();
						glTranslated(this->x, this->y, this->z);
						glRotated(-90, 1, 0, 0);
						gluSphere(quad1, 0.13, 20, 20);
					glPopMatrix();
					
					//body
					glColor3ub(255, 255, 255);
					glBindTexture(GL_TEXTURE_2D, texture_haut);
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
					glEnd();
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				break;
			case POSITION_SHOOS:
				glPushMatrix();
					glTranslated(0, -0.51, 0.50);
					glRotated(70, 1, 0, 0);
					//head
					gluQuadricTexture(quad1,GL_TRUE);
					glBindTexture(GL_TEXTURE_2D, texture_visage);
					gluQuadricDrawStyle(quad1, GLU_FILL);
					glColor3ub(174, 86, 35);
					glPushMatrix();
						glTranslated(this->x, this->y, this->z);
						glRotated(-145, 1, 0, 0);
						gluSphere(quad1, 0.13, 20, 20);
					glPopMatrix();
					
					//body
					glColor3ub(255, 255, 255);
					glBindTexture(GL_TEXTURE_2D, texture_haut);
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 1);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(1, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.5, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x-0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x-0.15, this->y-0.62, this->z-0.05);
					glEnd();
					glBegin(GL_QUADS);
						glTexCoord2d(0, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z-0.05);
						glTexCoord2d(0.2, 1);
						glVertex3d(this->x+0.15, this->y-0.12, this->z+0.05);
						glTexCoord2d(0.2, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z+0.05);
						glTexCoord2d(0, 0);
						glVertex3d(this->x+0.15, this->y-0.62, this->z-0.05);
					glEnd();
					gluQuadricTexture(quad1,GL_FALSE);
				glPopMatrix();
				break;
			case POSITION_FALLEN:
				//body
				gluQuadricTexture(quad1,GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture_snow);
				gluQuadricDrawStyle(quad1, GLU_FILL);
				glColor3ub(255, 255, 255);
				glPushMatrix();
					glTranslated(this->x, this->y-0.81, this->z);
					glRotated(-90, 1, 0, 0);
					gluSphere(quad1, 0.6, 20, 20);
				glPopMatrix();
				gluQuadricTexture(quad1,GL_FALSE);
				break;
			default:
				break;
		}
		
		//legs + shoes + skis
		this->legs->draw();
		
		//arms + hands + bastons
		this->arms->draw();
	glPopMatrix();
}

void Skiman::initialPosition()
{
	this->position = POSITION_INIT;
	this->legs->initialPosition();
	this->arms->initialPosition();
}

void Skiman::turnLeft()
{
	this->position = POSITION_TURN_LEFT;
	this->legs->turnLeft();
	this->arms->turnLeft();
}

void Skiman::turnRight()
{
	this->position = POSITION_TURN_RIGHT;
	this->legs->turnRight();
	this->arms->turnRight();
}

void Skiman::push()
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
	this->legs->push();
	this->arms->push();
}

void Skiman::shoos()
{
	this->position = POSITION_SHOOS;
	this->legs->shoos();
	this->arms->shoos();
}

void Skiman::fall()
{
	this->position = POSITION_FALLEN;
	this->legs->fall();
	this->arms->fall();
}

Skiman::~Skiman()
{
}