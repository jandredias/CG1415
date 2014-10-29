
#include "LimitMap.h"
#ifndef __GLUT__
#define __GLUT__
#include "GL/glut.h"
#endif
LimitMap::LimitMap(Vector3 a, Vector3 b){
	setSize(a.getX(), a.getY(), a.getZ());
	setPosition(b.getX(), b.getY(), b.getZ());
}
LimitMap::~LimitMap(){}
void LimitMap::draw(){}
