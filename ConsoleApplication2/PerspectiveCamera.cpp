#include "stdafx.h"
#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera():Camera(-100,100){}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(-100, 100){}

void PerspectiveCamera::computeVisualizationMatrix(){
	gluPerspective(	-90.0, 1.0,
					-100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void PerspectiveCamera::update(GLsizei w, GLsizei h){
	gluLookAt(0.0, -100.0, -100.0,
		0.0, 0.0, 0.0,
		0.0,-1.0, 0.0);
}
void PerspectiveCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
