#pragma once
#ifndef __FROG__
#define __FROG__

#include "DynamicObject.h"
class Frog : public DynamicObject
{
public:
	Frog();
	Frog(double x, double y, double z);
	~Frog();
	void draw();
};

#endif