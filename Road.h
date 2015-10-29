#ifndef __ROAD__
#define __ROAD__

#include "StaticObject.h"

class Road : public StaticObject
{
public:
	Road();
	Road(double x, double y, double z);
	~Road();
	void draw();
};


#endif
