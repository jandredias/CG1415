#include "stdafx.h"
#include "TimberLog.h"
#include "GL/GLUT.h"
#include <iostream>
TimberLog::TimberLog(){}
TimberLog::TimberLog(double x, double y, double z){ setPosition(x, y, z); setSpeed(0.5, 0, 0); setSize((rand() % 5 + 1) * 4); }
TimberLog::TimberLog(double x, double y, double z, double w){ setPosition(x, y, z); setSpeed(w, 0, 0); setSize((rand() % 5 + 1) * 4); }
TimberLog::~TimberLog(){}
void TimberLog::draw(){
	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

	glPushMatrix();
		glColor3f(0.5, 0.35, 0.05);
		glScalef(getSize(), 3, 0);
		glutSolidCube(3);
		glPopMatrix();
		glPopMatrix();
}