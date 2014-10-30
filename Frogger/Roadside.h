#ifndef __ROADSIDE__
#define __ROADSIDE__

#include "StaticObject.h"

class Roadside : public StaticObject
{
public:
	Roadside();
	Roadside(double x, double y, double z);
	~Roadside();
	void draw();
};

#endif
