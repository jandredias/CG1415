#include "Tunnel.h"
#include "GL/glut.h"

#include <iostream>

Tunnel::Tunnel(){ setSize(1000,60,20); }
Tunnel::Tunnel(double x, double y, double z) :Tunnel(){ setPosition(x, y, z); }
Tunnel::~Tunnel(){}
void Tunnel::draw(){
	glPushMatrix();
		//Position na colisao com a estrada, no plano Z = 0;
		glPushMatrix();
			glTranslated(-getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
			defineMaterial(	0.50, 0.50, 0.50, 1.00,	//Ambient
							0.50, 0.50, 0.50, 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0.5, 0.5, 0.5);

			glPushMatrix();
				glTranslatef(-getSize().getX()/2, -getSize().getY() / 2,0);
				glScalef(getSize().getX(), 2, getSize().getZ());
				glutSolidCube(1); //Cubo baixo
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-getSize().getX()/2,0, getSize().getZ() /2 );
				glScalef(getSize().getX(), getSize().getY(), 2);
				glutSolidCube(1); //Cubo Cima
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
