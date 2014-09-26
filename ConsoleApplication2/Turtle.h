#pragma once
#ifndef __TURTLE__
#define __TURTLE__

#include "DynamicObject.h"
class Turtle : public DynamicObject
{
public:
	Turtle();
	~Turtle();
	void draw();
};


#endif