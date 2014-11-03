#include "StreetLamp.h"
#include "GL/glut.h"
#include "GameManager.h"

extern GameManager *gm;
StreetLamp::StreetLamp(Vector3 pos, Vector3 dir){ setPosition(pos.getX(), pos.getY(), pos.getZ());
direction.set(dir.getX(), dir.getY(), dir.getZ());
setSize(1,1,20);
}
StreetLamp::~StreetLamp(){}

void StreetLamp::draw(){
	glPushMatrix();
	glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
	glScalef(direction.getX(), direction.getY(), direction.getZ());

		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		defineMaterial(	0.66, 0.66, 0.66, 1.00,	//Ambient
						0.66, 0.66, 0.66, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
			glTranslatef(0, 0, getSize().getZ()/2);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix(),
			glTranslatef(-2, 0, getSize().getZ()+0.5);
			glScalef(5, 1, 1);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-4,0,getSize().getZ());
			glColor3f(1.0, 1.0,0.0);
			if (gm->_lights_on)
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
