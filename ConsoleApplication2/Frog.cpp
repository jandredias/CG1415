#include "stdafx.h"

#include "Frog.h"
#include "Header.h"
#include "gl/glut.h"
Frog::Frog(){}
Frog::Frog(double x, double y, double z){
	//std::cout << "Posicao SAPO: " << x << " | " << y << " | " << z << "\n";

	setPosition(x, y, z);
	//std::cout << "Posicao SAPO: " << getPosition()->getX() << " | " << getPosition()->getY() << " | " << getPosition()->getZ() << "\n";

	setSpeed(0, 0, 0);
}
Frog::~Frog(){}
void Frog::draw(){
	glPushMatrix();
	//glScalef(10, 10, 10);
	//std::cout << "Posicao SAPO: " << getPosition()->getX() << " | " << getPosition()->getY() << " | " << getPosition()->getZ() << "\n";

	glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());//
	//printf("%d\n", getSpeed()->getY());
	/*Cubo da cabeça*/
		glPushMatrix();
			glTranslated(0, -1, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
			glColor3f(0, 0.9, 0);
			//glutWireCube(5);
		glPopMatrix();
		/*Cubo do corpo*/
		glPushMatrix();
			glTranslated(0, -5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
			glColor3f(0, 0.9, 0);
			//glutWireCube(5);
		glPopMatrix();
		/*Cubo de parte da pata superior direita que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(3, -1, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo do resto da pata superior direita que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(4, 0, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo de parte da pata superior esquerda que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(-3, -1, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo do resto da pata superior esquerda que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(-4, 0, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo de parte da pata inferior direita que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(3, -5, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo do resto da pata inferior direita que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(4, -6.5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 4, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo de parte da pata inferior esquerda que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(-3, -5, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		/*Cubo do resto da pata inferior esquerda que está encostada ao corpo*/
		glPushMatrix();
			glTranslated(-4, -6.5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 4, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();

		/*Olho esquerdo do sapo*/
		glPushMatrix();
			glTranslated(-2, 1, 0);
			glColor3f(1, 0, 0);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

		/*Olho direito do sapo*/
		glPushMatrix();
			glTranslated(2, 1, 0);
			glColor3f(1, 0, 0);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

		glPopMatrix();
}
