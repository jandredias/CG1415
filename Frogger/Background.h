#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "StaticObject.h"

class Background : public StaticObject {
public:
	Background();
	~Background();
	Background(double x, double y, double z);
	void draw();
};

#endif
