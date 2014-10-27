#ifndef __RIVER__
#define __RIVER__

#include "StaticObject.h"
class River : public StaticObject
{
public:
	River();
	River(double x, double y, double z);
	~River();
	void draw();
};


#endif