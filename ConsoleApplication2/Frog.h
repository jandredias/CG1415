#pragma once
#ifndef __FROG__
#define __FROG__

#include "DynamicObject.h"
class Frog : public DynamicObject
{
public:
	Frog();
	~Frog();
	void draw();
};

#endif