#ifndef __BUS__
#define __BUS__

#include "DynamicObject.h"

class Bus : public DynamicObject {
public:
	Bus();
	Bus(double x, double y, double z);
	Bus(double x, double y, double z, double w);
	~Bus();
	void draw();
};

#endif

