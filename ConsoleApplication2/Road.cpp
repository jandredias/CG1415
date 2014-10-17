#include "stdafx.h"
#include "Road.h"
#include "GL/GLUT.h"
Road::Road(){}
Road::~Road(){}
Road::Road(double x, double y, double z){setPosition(x, y, z);}
void Road::draw(){
	glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

		glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glScalef(400, 60, 1);
			glutSolidCube(1);
			glColor3f(0.8, 0.8, 0.8);
			glutWireCube(1);
		glPopMatrix();
		for (int i = -3; i < 4; i+= 2)
			for (int j = -5; j < 6; j++)
				desenha_traco(j*2, i*6, 1);
			
	glPopMatrix();
}
void Road::desenha_traco(int x, int y, int z){
	glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(20, 1, 1);
		glTranslated(x, y, z);
		glutSolidCube(1);
	glPopMatrix();
}