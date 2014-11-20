#include "GL/glut.h"
#include <cstdlib>

#include <iostream>
#include <ctime>
#include "Polygon.h"
#include "TimberLog.h"
#include "GameManager.h"
extern GameManager *gm;
TimberLog::TimberLog(){ setSpeed(0, 0, 0); }
TimberLog::TimberLog(double x, double y, double z) : TimberLog(){ setPosition(x, y, z);  setSize((rand() % 5 + 1) * 15, 5, 1); }
TimberLog::TimberLog(double x, double y, double z, double w) : TimberLog(x,y,z){ setSpeed(w, 0, 0); }
TimberLog::~TimberLog(){}
void TimberLog::draw(){
	glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ()+0.01);
		defineMaterial(	0.01, 0.01, 0.01, 1.00,	//Ambient
						0.39, 0.25, 0.05, 1.00,	//Diffuse
						0.00, 0.00, 0.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						128);					//SHININESS
		glColor3f(0.2275, 0.1490, 0.0314);
		Polygon::execute(2 * getSize().getX(), 10, gm->getSettings().getNrPolygons(), gm->getSettings().getNrPolygons());
	glPopMatrix();
}
