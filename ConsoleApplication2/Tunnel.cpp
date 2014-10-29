#include "Tunnel.h"
#include "GL\glut.h"
#include <iostream>
Tunnel::Tunnel(){ setSize(1000,60,20); }
Tunnel::Tunnel(double x, double y, double z) :Tunnel(){ setPosition(x, y, z); }
Tunnel::~Tunnel(){}
void Tunnel::draw(){
	glPushMatrix();
		//Position na colisao com a estrada, no plano Z = 0;
		glPushMatrix();
			glTranslated(-getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		
			glColor3f(0, 0, 0);

			glPushMatrix();
				glTranslatef(-getSize().getX()/2, -getSize().getY() / 2,0);
				glScalef(getSize().getX(), 2, getSize().getZ());
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-getSize().getX()/2,0, getSize().getZ() /2 );
				glScalef(getSize().getX(), getSize().getY(), 2);
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-getSize().getX()/2, getSize().getY() / 2, 0);
				glScalef(getSize().getX(), 2, getSize().getZ());
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
		glPopMatrix();

		glScalef(-1, 1, 1);
		glPushMatrix();
			glTranslated(-getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		
			glColor3f(0, 0, 0);

			glPushMatrix();
				glTranslatef(-getSize().getX()/2, -getSize().getY() / 2,0);
				glScalef(getSize().getX(), 2, getSize().getZ());
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-getSize().getX()/2,0, getSize().getZ() /2 );
				glScalef(getSize().getX(), getSize().getY(), 2);
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-getSize().getX()/2, getSize().getY() / 2, 0);
				glScalef(getSize().getX(), 2, getSize().getZ());
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
		
		glPopMatrix();

	glPopMatrix();
}
