
#include "Bus.h"
#include "GL/glut.h"

Bus::Bus(){	setPosition(0, 0, 0); setSpeed(0, 0, 0); }

Bus::Bus(double x, double y, double z) : Bus(){
	setPosition(x, y, z);
}
Bus::Bus(double x, double y, double z, double w) : Bus(x, y, z) { setSpeed(w, 0, 0); }
Bus::~Bus()
{
}

void Bus::draw(){
	glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
	
		//glPushMatrix();
		//glScalef(16, 10, 5);
		//glutWireCube(1);
		//glPopMatrix();
		if (getSpeed().getX() > 0) glRotatef(180, 0, 0, 1);
		glTranslated(2, 0, 0);
		
		glScaled(0.8, 0.8, 0.8);
		/*Cubo principal do corpo do carro*/
		glPushMatrix();

			glColor3f(227/255,78/255,187/255);

			glScalef(12, 8, 4);
			glutSolidCube(1);
		glPopMatrix();

		/*Cubo da frente, onde esta o motor*/
		glPushMatrix();
			glTranslated(-8.5, 0, 0);
			glColor3f(0, 0, 0);
			glScalef(5, 4, 2);
			glutSolidCube(1);
		glPopMatrix();

		/*Eixo da roda direita da frente*/
		glPushMatrix();
			glTranslated(-10, 2.5, 0);
			glColor3f(0, 0, 0);
			glScalef(2, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		/*Eixo da roda esquerda da frente*/
		glPushMatrix();
			glTranslated(-10, -2.5, 0);
			glColor3f(0, 0, 0);
			glScalef(2, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		/*Roda esquerda da frente*/
		glPushMatrix();
			glTranslated(-10, -4, 0);
			glColor3f(0, 0, 1);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 2, 16, 16);
		glPopMatrix();

		/*Roda direita da frente*/
		glPushMatrix();
			glTranslated(-10, 4, 0);
			glColor3f(0, 0, 1);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 2, 16, 16);
		glPopMatrix();

		/*Roda direita de tras*/
		glPushMatrix();
			glTranslated(1, -5, 0);
			glColor3f(0, 0, 1);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 3, 16, 16);
		glPopMatrix();

		/*Roda esquerda de tras*/
		glPushMatrix();
			glTranslated(1, 5, 0);
			glColor3f(0, 0, 1);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 3, 16, 16);
		glPopMatrix();

		/*Spoiler*/
		glPushMatrix();
			glTranslated(5.5, 0, 0);
			glColor3f(1, 0, 0);
			glScalef(3, 6, 3);
			glutSolidCube(1);
		glPopMatrix();

		/*Cockpit*/
		glPushMatrix();
			glTranslated(-2.5, 0, 0);
			glColor3f(1, 1, 1);
			glScalef(3, 4, 3);
			glutSolidCube(1);
		glPopMatrix();

	glPopMatrix();
}