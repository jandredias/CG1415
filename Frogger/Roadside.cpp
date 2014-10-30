
#include "Roadside.h"
#include "GameManager.h"
#include <iostream>
#include "GL/glut.h"

extern GameManager *gm;

Roadside::Roadside(){ setSize(1000, 20, 20); }
Roadside::Roadside(double x, double y, double z) : Roadside() { setPosition(x, y, z); }
Roadside::~Roadside(){}
void Roadside::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						getPosition().getZ() - getSize().getZ() / 2 );
		
		glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
		glColor3f(0.7, 0.7, 0.7);
		glutSolidCube(1);
	glPopMatrix();
}
