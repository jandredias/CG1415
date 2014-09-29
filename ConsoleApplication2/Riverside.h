#pragma once
#ifndef __RIVERSIDE__
#define __RIVERSIDE__

#include "StaticObject.h"
class Riverside : public StaticObject
{
public:
	Riverside();
	Riverside(double x, double y, double z);
	~Riverside();
	void draw();
};


#endif