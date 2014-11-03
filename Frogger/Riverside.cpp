
#include "Riverside.h"
#include "GL/glut.h"

Riverside::Riverside(){ setSize(1000, 20, 20); }
Riverside::Riverside(double x, double y, double z):Riverside(){setPosition(x, y, z);}
Riverside::~Riverside(){}
void Riverside::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						getPosition().getZ() - getSize().getZ() / 2 );
		
		glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
		defineMaterial(	0.00, 0.10, 0.00, 1.00,	//Ambient
						0.00, 1.00, 0.00, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0, 0.6, 0);
		glutSolidCube(1);
	glPopMatrix();
}
