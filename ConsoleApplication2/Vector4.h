#pragma once
#include "Vector3.h"
#ifndef __VECTOR4__
#define __VECTOR4__
class Vector4 : public Vector3{
	double _w;
public:
	Vector4();
	Vector4(double x, double y, double z, double w);
	~Vector4();
	double getW();
	void set(double x, double y, double z, double w);
	Vector4 operator=(Vector4 *vec);
	Vector4 operator*(double num);
	Vector4 operator+(Vector4 *vec);
	Vector4 operator-(Vector4 *vec);
};


#endif