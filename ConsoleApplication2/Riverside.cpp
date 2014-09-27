#include "stdafx.h"
#include "Riverside.h"
#include "GL/GLUT.h"

Riverside::Riverside(){}
Riverside::~Riverside(){}
void Riverside::draw(){
	glPushMatrix();
		glColor3f(0,1,0);
		glTranslated(0, getPosition()->getY(), 1);
		glScalef(40, 2, 1);
		glutSolidCube(10);
	glPopMatrix();
}