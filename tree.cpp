#include "tree.h"

Tree::Tree(GLUquadricObj * quadrique, GLuint ptexture_arbre)
{
	this->quad1 = quadrique;
	this->texture_arbre = ptexture_arbre;
}

void Tree::draw(float x, float y, float z, float size)
{
	glPushMatrix();
		//trunk
		glTranslated(0, size/4,  0);
		glColor3ub(90, 0, 0);
		gluQuadricTexture(quad1,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture_arbre);
		gluQuadricDrawStyle(quad1, GLU_FILL);
		glPushMatrix();
			glTranslated(x, y,  z);
			glRotated(90, 1, 0, 0);
			gluCylinder(quad1, size/12, size/12, size/4, 20, 20);
		glPopMatrix();
		glColor3ub(0, 90, 14);
		glPushMatrix();
			glTranslated(x, y,  z);
			glRotated(-90, 1, 0, 0);
			gluCylinder(quad1, size/12, 0, 3*size/4, 20, 20);
		glPopMatrix();
	
		//1st floor
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(45, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(90, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(135, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(180, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(225, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(270, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/9,  z);
			glRotated(315, 0, 1, 0);
			gluCylinder(quad1, size/8, 0, size/2, 20, 20);
		glPopMatrix();
		
		//2nd floor
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(22.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(67.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(112.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(157.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(202.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(247.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(292.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/4,  z);
			glRotated(327.5, 0, 1, 0);
			gluCylinder(quad1, size/10, 0, size/2.5, 20, 20);
		glPopMatrix();
		
		//3rd floor
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(45, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(90, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(135, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(180, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(225, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(270, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.7,  z);
			glRotated(315, 0, 1, 0);
			gluCylinder(quad1, size/14, 0, size/4, 20, 20);
		glPopMatrix();
		
		//4th floor
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(22.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(67.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(112.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(157.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(202.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(247.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(292.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2.3,  z);
			glRotated(327.5, 0, 1, 0);
			gluCylinder(quad1, size/18, 0, size/6, 20, 20);
		glPopMatrix();
		
		//5th floor
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(45, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(90, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(135, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(180, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(225, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(270, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/2,  z);
			glRotated(315, 0, 1, 0);
			gluCylinder(quad1, size/22, 0, size/10, 20, 20);
		glPopMatrix();
		
		//last (but not least) floor
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(22.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(67.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(112.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(157.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(202.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(247.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(292.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslated(x, y+size/1.8,  z);
			glRotated(327.5, 0, 1, 0);
			gluCylinder(quad1, size/44, 0, size/14, 20, 20);
		glPopMatrix();
	glPopMatrix();
}

Tree::~Tree()
{
}


//builder

GLuint make_texture_tree = loadTexture("images/sleeve.jpg");
GLUquadricObj * make_quad = gluNewQuadric();

Snowman * snowman_make(const char * snowman_name)
{
	if(strcmp(snowman_name, 's1') == 0){
		GLuint tree  = make_texture_tree;
	}else{
		return null;
	}
	
	return new Tree(make_quad, tree);
}