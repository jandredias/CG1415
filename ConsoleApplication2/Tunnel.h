#ifndef __TUNNEL__
#define __TUNNEL__
#include "StaticObject.h"
class Tunnel : public StaticObject
{
public:
	Tunnel();
	Tunnel(double x, double y, double z);
	~Tunnel();
	void draw();
};

#endif