#pragma once
#ifndef __PERSPECTIVECAMERA__
#define __PERSPECTIVECAMERA__

#include "Camera.h"
class PerspectiveCamera : public Camera {
	double _fovy;
	double _aspect;
public:
	PerspectiveCamera();
	PerspectiveCamera(double fovy,double aspect, double zNear, double zFar);
	~PerspectiveCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};


#endif