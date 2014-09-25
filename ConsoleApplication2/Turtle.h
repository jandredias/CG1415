#pragma once
#include "DynamicObject.h"
#ifndef __TURTLE__
#define __TURTLE__
class Turtle : public DynamicObject
{
public:
	Turtle();
	~Turtle();
	void draw();
};


#endif