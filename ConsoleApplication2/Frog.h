#pragma once
#ifndef __FROG__
#define __FROG__

#include "DynamicObject.h"
class Frog : public DynamicObject
{
	DynamicObject *speeder;
	Vector3 speed_log;
public:
	Frog();
	Frog(double x, double y, double z);
	~Frog();
	void draw();
	void update(double delta);
	Vector3 getSpeed();
	void setSpeedLog(double x, double y, double z);
	Vector3 Frog::getSpeedLog();
};

#endif