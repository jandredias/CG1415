#include "stdafx.h"
#include "TimberLog.h"
#include "GL/GLUT.h"

TimberLog::TimberLog()
{
}


TimberLog::~TimberLog()
{
}

void TimberLog::draw(){
		glPushMatrix();
	glTranslated(0, getPosition()->getY(), 1);
	glColor3f(0.5, 0.35, 0.05);
	glScalef(8, 2, 1);
	glutSolidCube(3);
		glPopMatrix();
}