#ifndef __STREET_LAMP__
#define __STREET_LAMP__

#include "StaticObject.h"
#include "Vector3.h"

class StreetLamp : public StaticObject
{
	Vector3 direction;
public:
	StreetLamp(Vector3 pos, Vector3 dir);
	~StreetLamp();
	void draw();
};

#endif
