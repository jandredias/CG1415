
#include "Riverside.h"
#include "GL/GLUT.h"

Riverside::Riverside(){ setSize(1000, 20, 20); }
Riverside::Riverside(double x, double y, double z):Riverside(){setPosition(x, y, z);}
Riverside::~Riverside(){}
void Riverside::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						getPosition().getZ() - getSize().getZ() / 2 );
		
		glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
		glColor3f(0, 0.8, 0);
		glutSolidCube(1);
	glPopMatrix();
}