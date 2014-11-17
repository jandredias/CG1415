#pragma once
#include "StaticObject.h"

class Background : public StaticObject {
public:
	Background();
	~Background();
	Background(double x, double y, double z);
	void draw();
};
