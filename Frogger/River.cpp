
#include "River.h"
#include "GL/glut.h"

River::River(){ setSize(1000, 60, 20); }
River::River(double x, double y, double z): River(){setPosition(x, y, z);}
River::~River(){}
void River::draw(){
	glPushMatrix();
		glTranslated(	getPosition().getX(),
						getPosition().getY(),
						getPosition().getZ() - getSize().getZ() / 2 );
	
		glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
		defineMaterial(	0.20, 0.20, 1.00, 1.00,	//Ambient
						0.20, 0.20, 1.00, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0, 0, 1);
		glutSolidCube(1);
	glPopMatrix();
}
