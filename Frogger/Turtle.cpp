
#include "Turtle.h"
#include "GL/glut.h"

Turtle::Turtle(){}
Turtle::Turtle(double x, double y, double z){setPosition(x, y, z);}
Turtle::~Turtle(){}
void Turtle::draw(){
	glPushMatrix();
	glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

	glPushMatrix();
		glColor3f(0, 1, 0);
		glutSolidSphere(4,8,8);
		glutSolidCube(4);
		glColor3f(0, 0.9, 0);
		glutWireSphere(4,8,8);
		glPopMatrix();
		glPopMatrix();
}