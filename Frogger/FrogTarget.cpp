#include "FrogTarget.h"
#ifndef __GLUT__
#define __GLUT__
#include "GL/glut.h"
#endif
FrogTarget::FrogTarget(){
	setSize(15, 15, 1);
}


FrogTarget::~FrogTarget(){}

FrogTarget::FrogTarget(double x, double y, double z):FrogTarget(){
	setPosition(x, y, z);
}
void FrogTarget::draw(){
	glPushMatrix();
		glTranslatef(getPosition().getX(), getPosition().getY() - 2.5, getPosition().getZ());
		glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
		glColor3f(0, 0, 1);
		glutSolidCube(1);

	glPopMatrix();
}
