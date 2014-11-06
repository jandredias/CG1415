#include "FrogTarget.h"
#include "GL/glut.h"
#include "Polygon.h"
#include "GameManager.h"
FrogTarget::FrogTarget(){
	setSize(7.5,7.5,5);
}


FrogTarget::~FrogTarget(){}

FrogTarget::FrogTarget(double x, double y, double z):FrogTarget(){
	setPosition(x, y, z);
}
void FrogTarget::draw(){
			defineMaterial(	0.20, 0.20, 1.00, 1.00,	//Ambient
							0.20, 0.20, 1.00, 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
	glColor3f(0, 0, 1);
	glPushMatrix();
		glTranslatef(getPosition().getX(), getPosition().getY() - 2.5, getPosition().getZ()+0.001);
		//glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
		//glutSolidCube(1);
		Polygon::execute(2*getSize().getX(), 2*getSize().getY(), 2*getSize().getX() / NR_POLYGONS, 2*getSize().getY() / NR_POLYGONS);
	glPopMatrix();
}
