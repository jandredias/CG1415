#pragma once
#ifndef __BUS__
#define __BUS__

#include "DynamicObject.h"

class Bus : public DynamicObject {
public:
	Bus();
	Bus(double x, double y, double z);
	~Bus();
	void draw();
};

#endif

