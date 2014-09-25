#pragma once
#include "StaticObject.h"
#ifndef __ROADSIDE__
#define __ROADSIDE__
class Roadside : public StaticObject
{
public:
	Roadside();
	~Roadside();
	void draw();
};

#endif