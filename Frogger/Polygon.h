#pragma once
#ifndef __POLYGON__
#define __POLYGON__
#include "GL/glut.h"
class Polygon
{
public:
	Polygon();
	~Polygon();
	void static execute(GLfloat w, GLfloat h, GLfloat qt);
};
#endif