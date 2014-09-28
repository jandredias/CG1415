#include "stdafx.h"
#include "Frog.h"
#include "gl/glut.h"

Frog::Frog(){}
Frog::~Frog(){}
void Frog::draw(){
	glPushMatrix();
		glTranslated(0, getPosition()->getY(), 1);
		glPushMatrix();
		//glScalef(1.5,1,1);
			glColor3f(0, 1, 0);
			glutSolidCube(4);
			glColor3f(0, 0.9, 0);
			glutWireCube(4);
			
			glTranslated(0, -4, 1);
				glColor3f(0, 1, 0);
				glutSolidCube(4);
				glColor3f(0, 0.9, 0);
				glutWireCube(4);
			glTranslated(0, 4, -1);
		glPopMatrix();
	glPopMatrix();
}
