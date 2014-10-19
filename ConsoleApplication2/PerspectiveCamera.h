#pragma once
#ifndef __PERSPECTIVECAMERA__
#define __PERSPECTIVECAMERA__

#include "Camera.h"
#include "GL/glut.h"
class PerspectiveCamera : public Camera {
	double _fovy;
	double _aspect;
	Frog* frog;
public:
	PerspectiveCamera();
	PerspectiveCamera(double fovy,double aspect, double zNear, double zFar);
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Frog *a);
	~PerspectiveCamera();
	void update(GLsizei w, GLsizei h);
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};


#endif