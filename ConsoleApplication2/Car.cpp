#include "stdafx.h"
#include "Car.h"
#include "GL/GLUT.h"

Car::Car()
{
}


Car::~Car()
{
}

void Car::draw(){
	glPushMatrix();
		glColor3f(0.7, 0.7, 0.7);
		glTranslated(0, getPosition()->getY(), 1);
		glScalef(40, 2, 1);
		glutSolidCube(10);
	glPopMatrix();
}