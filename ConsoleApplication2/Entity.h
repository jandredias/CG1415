#pragma once
#ifndef __ENTITY__
#define __ENTITY__

#include "Vector3.h"
class Entity
{
	Vector3 _position;
public:
	Entity();
	~Entity();
	Vector3 getPosition(void);
	void setPosition(double x, double y, double z);
	void setPosition(Vector3*);
};

#endif