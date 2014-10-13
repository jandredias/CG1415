#pragma once
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
	void desenha_traco(int x, int y, int z);
};


#endif