
#include "Roadside.h"
#include "GameManager.h"
#include <iostream>
#include "GL/glut.h"
#include "Polygon.h"
#include "GameManager.h"
extern GameManager *gm;

Roadside::Roadside(){ setSize(1000, 20, 20); }
Roadside::Roadside(double x, double y, double z) : Roadside() { setPosition(x, y, z); }
Roadside::~Roadside(){}
void Roadside::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
				getPosition().getY(),
				getPosition().getZ());
		defineMaterial(	0.70, 0.70, 0.70, 1.00,	//Ambient
						0.70, 0.70, 0.70, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0.7, 0.7, 0.7);
		Polygon::execute(getSize().getX(), getSize().getY(), getSize().getX() / NR_POLYGONS, getSize().getY() / NR_POLYGONS);
	glPopMatrix();
}
