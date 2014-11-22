#include "FrogTarget.h"
#include "GL/glut.h"
#include "Polygon.h"
#include "GameManager.h"
#include <cmath>
#include "Texture.h"
extern GameManager *gm;
FrogTarget::FrogTarget(){
	setSize(7.5, 7.5, 5);
	setTexture(Texture::loadBMP_custom("Water.bmp"), 512);
}
FrogTarget::FrogTarget(double x, double y, double z) :FrogTarget(){ setPosition(x, y, z); }
FrogTarget::~FrogTarget(){}
void FrogTarget::draw(){
	glPushMatrix();

		defineMaterial(0.01, 0.01, 0.05, 1.00,	//Ambient
			0.20, 0.20, 1.00, 1.00,	//Diffuse
			1.00, 1.00, 1.00, 1.00,	//Specular
			0.00, 0.00, 0.00, 1.00,	//Emission
			77, getTexture());					//SHININESS
		glColor3f(0.1176, 0.1176, 0.5961);
		glTranslatef(getPosition().getX(), getPosition().getY() - 2.5, getPosition().getZ()+0.01);
		Polygon::execute(	2*getSize().getX(), 2*getSize().getY(),
							gm->getSettings().getNrPolygons(),
							gm->getSettings().getNrPolygons());
		defineMaterial(	0.00, 0.10, 0.00, 1.00,	//Ambient
						0.00, 1.00, 0.00, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0, 0.6, 0);
		glTranslatef(0, 0, 0.01);
		Polygon::execute(	1 * getSize().getX(), 1 * getSize().getY(),
							gm->getSettings().getNrPolygons(),
							gm->getSettings().getNrPolygons());
	glPopMatrix();
}
