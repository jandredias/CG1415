#include "GL/glut.h"
#include <cstdlib>

#include <iostream>
#include <ctime>
#include "Polygon.h"
#include "TimberLog.h"
TimberLog::TimberLog(){ setSpeed(0, 0, 0); }
TimberLog::TimberLog(double x, double y, double z) : TimberLog(){ setPosition(x, y, z);  setSize((rand() % 5 + 1) * 30, 10, 2); }
TimberLog::TimberLog(double x, double y, double z, double w) : TimberLog(x,y,z){ setSpeed(w, 0, 0); }
TimberLog::~TimberLog(){}
void TimberLog::draw(){
	glPushMatrix();
	glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ()+0.01);

		defineMaterial(	0.50, 0.35, 0.05, 1.00,	//Ambient
						0.50, 0.35, 0.05, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0.5, 0.35, 0.05);
		//glScalef(getSize().getX(), getSize().getY(), 1);
		//glutSolidCube(1);
		Polygon::execute(getSize().getX(), 10, 10, 4);
		glPopMatrix();
}
