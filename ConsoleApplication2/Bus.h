#pragma once
#ifndef __BUS__
#define __BUS__

#include "DynamicObject.h"

class Bus : public DynamicObject {
public:
	Bus();
	~Bus();
	void draw();
};

#endif

