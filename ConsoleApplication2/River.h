#pragma once
#include "StaticObject.h"
#ifndef __RIVER__
#define __RIVER__
class River : public StaticObject
{
public:
	River();
	~River();
	void draw();
};


#endif