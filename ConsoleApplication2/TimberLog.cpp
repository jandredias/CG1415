
#include "TimberLog.h"
#include "GL/GLUT.h"
#include <iostream>
TimberLog::TimberLog(){ setSpeed(0, 0, 0); }
TimberLog::TimberLog(double x, double y, double z) : TimberLog(){ setPosition(x, y, z);  setSize((rand() % 5 + 1) * 30, 10, 2); }
TimberLog::TimberLog(double x, double y, double z, double w) : TimberLog(x,y,z){ setSpeed(w, 0, 0); }
TimberLog::~TimberLog(){}
void TimberLog::draw(){
	glPushMatrix();
	glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

	
		glColor3f(0.5, 0.35, 0.05);
		glScalef(getSize().getX(), getSize().getY(), 1);
		glutSolidCube(1);
		glPopMatrix();
}