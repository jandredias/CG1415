#include "stdafx.h"
#include "Frog.h"
#include "GameManager.h"
#include <iostream>

#include "gl/glut.h"
extern GameManager *gm;

extern GameManager *gm;
Frog::Frog(){}
Frog::Frog(double x, double y, double z){
	setPosition(x, y, z);
	setSize(10, 10, 10);
	setSpeed(0, 0, 0);
}
Frog::~Frog(){}
void Frog::draw(){
	glPushMatrix();
		std::cout << "SAPO: "	<< getPosition().getX() - getSize().getX() / 2 << " " 
								<< getPosition().getY() - getSize().getY() / 2 << " " 
								<< getPosition().getZ() - getSize().getZ() / 2 << std::endl;
		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ()-getSize().getZ());

		if (gm->_debug){
			glColor3f(0,1,0);
			glutWireCube(10);
		}
		
		glColor3f(0, 1, 0);
		//glTranslated(0, -1, 1);
		//glScalef(1, 0.8, 1);
		glutSolidCube(5);
	glPopMatrix();
	/*
	glColor3f(1, 1, 1);
	glutWireCube(16);
	//printf("%d\n", getSpeed().getY());
	//Cubo da cabeça
		glPushMatrix();
			glTranslated(0, -1, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
			glColor3f(0, 0.9, 0);
			//glutWireCube(5);
		glPopMatrix();
		//Cubo do corpo
		glPushMatrix();
			glTranslated(0, -5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
			glColor3f(0, 0.9, 0);
			//glutWireCube(5);
		glPopMatrix();
		//Cubo de parte da pata superior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(3, -1, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo do resto da pata superior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(4, 0, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo de parte da pata superior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-3, -1, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo do resto da pata superior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-4, 0, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo de parte da pata inferior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(3, -5, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo do resto da pata inferior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(4, -6.5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 4, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo de parte da pata inferior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-3, -5, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();
		//Cubo do resto da pata inferior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-4, -6.5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 4, 1);
			glutSolidCube(1);
			glColor3f(0, 0.9, 0);
			//glutWireCube(1);
		glPopMatrix();

		//Olho esquerdo do sapo
		glPushMatrix();
			glTranslated(-2, 1, 0);
			glColor3f(1, 0, 0);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

		//Olho direito do sapo
		glPushMatrix();
			glTranslated(2, 1, 0);
			glColor3f(1, 0, 0);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

		glPopMatrix();*/
}
