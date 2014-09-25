#pragma once
#include "StaticObject.h"
#ifndef __ROAD__
#define __ROAD__
class Road : public StaticObject
{
public:
	Road();
	~Road();
	void draw();
};


#endif