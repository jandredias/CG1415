
#include "Road.h"
#include <iostream>
#include "GL/glut.h"

Road::Road(){ setSize(1000,60,20); }
Road::~Road(){}
Road::Road(double x, double y, double z): Road() {setPosition(x, y, z);}
void Road::draw(){
	glPushMatrix();
//	std::cout << "X: " << getPosition().getX() << std::endl;
//	std::cout << "Y: " << getPosition().getY() << std::endl;
//	std::cout << "Z: " << getPosition().getZ() - getSize().getZ() / 2 << std::endl;

	glTranslated(	getPosition().getX(),
					getPosition().getY(),
					getPosition().getZ() - getSize().getZ() / 2);

		glPushMatrix();
			defineMaterial(	0.20, 0.20, 0.20, 1.00,	//Ambient
							0.20, 0.20, 0.20, 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0.2, 0.2, 0.2);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();

		for (int i = -3; i < 4; i+= 2)
			for (int j = -5; j < 6; j++){
				glPushMatrix();
					defineMaterial(	1.00, 1.00, 1.00, 1.00,	//Ambient
									1.00, 1.00, 1.00, 1.00,	//Diffuse
									1.00, 1.00, 1.00, 1.00,	//Specular
									0.00, 0.00, 0.00, 1.00,	//Emission
									77);					//SHININESS
					glColor3f(1, 1, 1);
					glScalef(20, 1, 1);
					glTranslated(j * 2, i * 6, getSize().getZ() / 2);
					glutSolidCube(1);
				glPopMatrix();
			}
				
			
	glPopMatrix();
}