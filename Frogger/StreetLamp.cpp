#include "StreetLamp.h"
#include "GL\glut.h"

StreetLamp::StreetLamp(Vector3 pos, Vector3 dir){ setPosition(pos.getX(), pos.getY(), pos.getZ());
direction.set(dir.getX(), dir.getY(), dir.getZ());
setSize(1,1,20);
}
StreetLamp::~StreetLamp(){}

void StreetLamp::draw(){
	glPushMatrix();
	glScalef(direction.getX(), direction.getY(), direction.getZ());

		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
			glTranslatef(0, 0, getSize().getZ()/2);
			glScalef(getSize().getX(), getSize().getY(), getSize().getZ());
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix(),
			glTranslatef(0, 0, getSize().getZ()+0.5);
			glScalef(1, 5, 1);
			glColor3f(0.65, 0.65, 0.65);
			glutSolidCube(1);
		glPopMatrix();

	glPopMatrix();
}