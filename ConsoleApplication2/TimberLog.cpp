#include "stdafx.h"
#include "TimberLog.h"
#include "GL/GLUT.h"

TimberLog::TimberLog()
{
}
TimberLog::TimberLog(double x, double y, double z){
	setPosition(x, y, z);
}

TimberLog::~TimberLog()
{
}

void TimberLog::draw(){
	glPushMatrix();
		glColor3f(0.5, 0.35, 0.05);
		glScalef(8, 3, 1);
		glutSolidCube(3);
	glPopMatrix();
}