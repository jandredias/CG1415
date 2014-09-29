#include "stdafx.h"
#include "Bus.h"
#include "GL/GLUT.h"

Bus::Bus()
{
}

Bus::Bus(double x, double y, double z){
	setPosition(x, y, z);
}
Bus::~Bus()
{
}

void Bus::draw(){
	glPushMatrix();
		glTranslated(-100, getPosition()->getY(), 1);
		glColor3f(1, 1, 1);
		glScalef(7, 4, 2);
		glutSolidCube(3);
	glPopMatrix();
}