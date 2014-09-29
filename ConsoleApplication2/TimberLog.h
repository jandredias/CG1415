#pragma once
#ifndef __TIMBERLOG__
#define __TIMBERLOG__

#include "DynamicObject.h"
class TimberLog : public DynamicObject
{
public:
	TimberLog();
	TimberLog(double x, double y, double z);
	~TimberLog();
	void draw();
};


#endif