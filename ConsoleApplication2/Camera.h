#pragma once
#include "Header.h"
#include "Vector3.h"

#ifndef __CAMERA__
#define __CAMERA__
class Camera : public Entity {
	Vector3 _up;
	Vector3 _at;
	double _near;
	double _far;
public:
	Camera(double near, double far);
	~Camera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
#endif