#include "stdafx.h"
#include "Car.h"
#include "GL/GLUT.h"

Car::Car()
{
}


Car::~Car()
{
}

Car::Car(double x, double y, double z){
	setPosition(x, y, z);
}

void Car::draw(){
		glPushMatrix();
	glTranslated(90, getPosition()->getY(), 1);
	glColor3f(1, 0, 0);
	glScalef(4, 1.5, 1);
	glutSolidCube(6);
		glPopMatrix();

}