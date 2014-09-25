#pragma once
#include "DynamicObject.h"
#ifndef __CAR__
#define __CAR__
class Car : public DynamicObject{
public:
	Car();
	~Car();
	void draw();
};

#endif