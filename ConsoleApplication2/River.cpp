#include "stdafx.h"
#include "River.h"
#include "GL/GLUT.h"

River::River(){}
River::River(double x, double y, double z){setPosition(x, y, z);}
River::~River(){}
void River::draw(){
	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

	glPushMatrix();
		glColor3f(0, 0, 1);
		glScalef(400, 60, 1);
		glutSolidCube(1);
		glPopMatrix();
		glPopMatrix();
}