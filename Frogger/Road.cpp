#include "Road.h"
#include <iostream>
#include "GL/glut.h"
#include "Polygon.h"
Road::Road(){ setSize(1000,60,20); }
Road::~Road(){}
Road::Road(double x, double y, double z): Road() {setPosition(x, y, z);}
void Road::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						0);
		glPushMatrix();
			defineMaterial(	0.00, 0.00, 0.00, 1.00,	//Ambient
							0.20, 0.20, 0.20, 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(1,1,1);
			Polygon::execute(1000,60, 50);
		glPopMatrix();
		for (int i = -3; i < 4; i+= 2)
			for (int j = -5; j < 6; j++){
				glPushMatrix();
					defineMaterial(	0.00, 0.00, 0.00, 1.00,	//Ambient
									1.00, 1.00, 1.00, 1.00,	//Diffuse
									1.00, 1.00, 1.00, 1.00,	//Specular
									0.00, 0.00, 0.00, 1.00,	//Emission
									77);					//SHININESS
					glColor3f(1, 1, 1);
					glScalef(20, 1, 0.01);
					glTranslated(j * 2, i * 6,0);
					glutSolidCube(1);
				glPopMatrix();
			}
	glPopMatrix();
}