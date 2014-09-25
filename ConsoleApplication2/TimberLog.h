#pragma once
#include "DynamicObject.h"
#ifndef __TIMBERLOG__
#define __TIMBERLOG__
class TimberLog : public DynamicObject
{
public:
	TimberLog();
	~TimberLog();
	void draw();
};


#endif