#include "stdafx.h"
#include "Frog.h"
#include "gl/glut.h"

Frog::Frog(){}
Frog::Frog(double x, double y, double z){
	setPosition(x, y, z);
}
Frog::~Frog(){}
void Frog::draw(){
		glPushMatrix();
			glColor3f(0, 1, 0);
			glutSolidCube(4);
			glColor3f(0, 0.9, 0);
			glutWireCube(4);
		glPopMatrix();
		glPushMatrix();
			glTranslated(0, -4, 1);
			glColor3f(0, 1, 0);
			glutSolidCube(4);
			glColor3f(0, 0.9, 0);
			glutWireCube(4);
			glPopMatrix();
		glPopMatrix();
}
