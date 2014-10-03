#include "stdafx.h"
#include "Riverside.h"
#include "GL/GLUT.h"

Riverside::Riverside(){}
Riverside::Riverside(double x, double y, double z){setPosition(x, y, z);}
Riverside::~Riverside(){}
void Riverside::draw(){
	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

	glPushMatrix();
		glColor3f(0,1,0);
		glScalef(400, 20, 1);
		glutSolidCube(1);
		glPopMatrix();
		glPopMatrix();
}