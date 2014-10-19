#pragma once

#include <iostream>
#include "GL/GLUT.h"

#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
class Car : public DynamicObject{
	Vector3 _color;
public:
	Car();
	Car(double x, double y, double z);
	Car::Car(double x, double y, double z, double w);
	~Car();
	void draw();
};

#endif