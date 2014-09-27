#include "stdafx.h"
#include "Road.h"
#include "GL/GLUT.h"
Road::Road(){}
Road::~Road(){}
void Road::draw(){
	glPushMatrix();
	glTranslated(0, getPosition()->getY(), 1);
	glColor3f(0.9, 0.9, 0.9);
	glScalef(40, 10, 1);
	glutSolidCube(6);
	glPopMatrix();
}