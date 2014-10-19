#include "stdafx.h"
#include "River.h"
#include "GL/GLUT.h"

River::River(){ setSize(200, 60, 20); }
River::River(double x, double y, double z): River(){setPosition(x, y, z);}
River::~River(){}
void River::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX() + getSize().getX() / 2,
						getPosition().getY() + getSize().getY() / 2,
						getPosition().getZ() - getSize().getZ() / 2 );
	
		glScalef(getSize().getX(), getSize().getY(), getSize().getZ());

		glColor3f(0, 0, 1);
		glutSolidCube(1);

	glPopMatrix();
}