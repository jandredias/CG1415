#include "stdafx.h"
#include "Road.h"
#include "GL/GLUT.h"
Road::Road(){}
Road::~Road(){}
Road::Road(double x, double y, double z){setPosition(x, y, z);}
void Road::draw(){
	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

	glPushMatrix();
		glColor3f(0.9, 0.9, 0.9);
		glScalef(400, 60, 1);
		glutSolidCube(1);
		glColor3f(0.8, 0.8, 0.8);
		glutWireCube(1);
		glPopMatrix();
		glPopMatrix();
}