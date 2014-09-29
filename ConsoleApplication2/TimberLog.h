#pragma once
#ifndef __TIMBERLOG__
#define __TIMBERLOG__

#include "DynamicObject.h"

#include <stdlib.h>
#include <time.h>
class TimberLog : public DynamicObject
{
public:
	TimberLog();
	TimberLog(double x, double y, double z);
	TimberLog(double x, double y, double z, double w);
	~TimberLog();
	void draw();
};
#endif