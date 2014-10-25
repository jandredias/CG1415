#pragma once
#ifndef __LIMIT_MAP__
#define __LIMIT_MAP__

#include "StaticObject.h"
#include "Vector3.h"
class LimitMap : public StaticObject
{
public:
	LimitMap(Vector3 a, Vector3 b);
	~LimitMap();
	void draw();
};

#endif