#pragma once
#ifndef __TIMBERLOG__
#define __TIMBERLOG__

#include "DynamicObject.h"
class TimberLog : public DynamicObject
{
public:
	TimberLog();
	~TimberLog();
	void draw();
};


#endif