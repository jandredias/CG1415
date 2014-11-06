
#include "Background.h"
#include <GL/glut.h>
#include "GameManager.h"
extern GameManager *gm;
Background::Background(){ setSize(10000, 10000, 1);}
Background::~Background(){}
Background::Background(double x, double y, double z) : Background(){ setPosition(x, y, z); }
void Background::draw(){
	
	glPushMatrix();
		
		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		/*glPushMatrix();
			glTranslatef(0, -getSize().getY() / 2, -getSize().getZ());
			glColor3f(0.7, 0.7, 0.7);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, getSize().getY() / 2, -getSize().getZ());
			glColor3f(0,0.8,0);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();*/
		if (gm->_modo_dia){
			defineMaterial(	0.10, 0.10, 0.00, 1.00,	//Ambient
							0.10, 0.10, 0.00, 1.00,	//Diffuse
							0.10, 0.10, 0.10, 1.00,	//Specular
							1.00, 1.00, 0.50, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0.8, 0.8, 0);
			glPushMatrix();
				glColor3f(1,1,0);
				glTranslatef(-200, 400, 200);
				glutSolidSphere(100, 32,32);
			glPopMatrix();
		}
		else{
			defineMaterial(	0.80, 0.80, 0.80, 1.00,	//Ambient
							0.80, 0.80, 0.80, 1.00,	//Diffuse
							0.80, 0.80, 0.80, 1.00,	//Specular
							0.30, 0.30, 0.30, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0.8, 0.8, 0);
			glPushMatrix();
				glColor3f(1,1,0);
				glTranslatef(200, 400, 200);
				glutSolidSphere(50, 16,16);
			glPopMatrix();
		}
	glPopMatrix();
}
