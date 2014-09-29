#pragma once

#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__

#include "GameObject.h"
#include "Vector3.h"
class DynamicObject : public GameObject
{
	Vector3 _speed;
public:
	DynamicObject();
	~DynamicObject();
	void update(double delta_t);
	Vector3* setSpeed(Vector3* speed);
	Vector3* setSpeed(double x, double y, double z);
	Vector3* getSpeed();

};

#endif