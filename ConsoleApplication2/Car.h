#pragma once

#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
class Car : public DynamicObject{
public:
	Car();
	Car(double x, double y, double z);
	~Car();
	void draw();
};

#endif