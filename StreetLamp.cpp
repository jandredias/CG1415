#include "StreetLamp.h"
#include "GL/glut.h"
#include "GameManager.h"
#include <iostream>
#include <cmath>
extern GameManager *gm;
StreetLamp::StreetLamp(Vector3 pos, Vector3 dir){
	setPosition(pos.getX(), pos.getY(), pos.getZ());
	direction.set(dir.getX(), dir.getY(), dir.getZ());
	setSize(0.5,0.5,10);
}
StreetLamp::~StreetLamp(){}

void StreetLamp::draw(){
	glPushMatrix();
		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		
		glRotatef(atan(-direction.getY()/direction.getX()) * 180 / PI, 0, 0, 1);
		if (getPosition().getX() < 0) glRotatef(180, 0, 0, 1);
		
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		defineMaterial(	0.66, 0.66, 0.66, 1.00,	//Ambient
						0.66, 0.66, 0.66, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
			glTranslatef(0, 0, 2*getSize().getZ()/2);
			glScalef(2*getSize().getX(), 2*getSize().getY(),2* getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix(),
			glTranslatef(-2, 0, 2*getSize().getZ()+0.5);
			glScalef(5, 1, 1);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-4,0,2*getSize().getZ());
			glColor3f(1.0, 1.0,0.0);
			if (gm->getLightsOn())
				defineMaterial(	1.00, 1.00, 0.00, 1.00,	//Ambient
								1.00, 1.00, 0.00, 1.00,	//Diffuse
								1.00, 1.00, 1.00, 1.00,	//Specular
								1.00, 1.00, 0.00, 1.00,	//Emission
									77);					//SHININESS
			else
				defineMaterial(	1.00, 1.00, 0.00, 1.00,	//Ambient
								1.00, 1.00, 0.00, 1.00,	//Diffuse
								1.00, 1.00, 1.00, 1.00,	//Specular
								0.00, 0.00, 0.00, 1.00,	//Emission
									77);					//SHININESS
			glutSolidSphere(0.5, 8, 8);
		glPopMatrix();
	glPopMatrix();
}
