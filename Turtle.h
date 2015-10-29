#ifndef __TURTLE__
#define __TURTLE__

#include "DynamicObject.h"

class Turtle : public DynamicObject
{
public:
	Turtle();
	Turtle(double x, double y, double z);
	~Turtle();
	void draw();
};


#endif
