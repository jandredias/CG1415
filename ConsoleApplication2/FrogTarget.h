#ifndef __FROG_TARGET__
#define __FROG_TARGET__
#include "StaticObject.h"

class FrogTarget : public StaticObject
{
public:
	FrogTarget();
	~FrogTarget();
	FrogTarget(double x, double y, double z);
	void draw();
};

#endif