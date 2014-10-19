#include "stdafx.h"
#include "Roadside.h"
#include "GameManager.h"
#include <iostream>

#include "gl/glut.h"
extern GameManager *gm;

Roadside::Roadside(){ setSize(200, 20, 20); }
Roadside::Roadside(double x, double y, double z) : Roadside() { setPosition(x, y, z); }
Roadside::~Roadside(){}
void Roadside::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX() + getSize().getX() / 2,
						getPosition().getY() + getSize().getY() / 2,
						getPosition().getZ() - getSize().getZ() / 2 );
		//std::cout << getSize().getX() << std::endl;
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glColor3f(0.7, 0.7, 0.7);
			glutSolidCube(1);
	glPopMatrix();
}