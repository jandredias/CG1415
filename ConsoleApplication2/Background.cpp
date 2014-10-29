
#include "Background.h"
#ifndef __GLUT__
#define __GLUT__
#include <GL/glut.h>
#endif
Background::Background(){ setSize(10000, 10000, 1);}
Background::~Background(){}
Background::Background(double x, double y, double z) : Background(){ setPosition(x, y, z); }
void Background::draw(){
	
	glPushMatrix();
		
		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glPushMatrix();
			glTranslatef(0, -getSize().getY() / 2, -getSize().getZ());
			glColor3f(0.7, 0.7, 0.7);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, getSize().getY() / 2, -getSize().getZ());
			glColor3f(0,0.8,0);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
}
