#include "stdafx.h"
#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera():Camera(-100,100){}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(-100, 100){}

void PerspectiveCamera::computeVisualizationMatrix(){


	gluPerspective(	-20, 1.0,
					100, -100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void PerspectiveCamera::update(GLsizei w, GLsizei h){
	
	gluLookAt(0.0, -250.0, 100.0,
		0.0, 100.0, 0.0,
		0.0,-1.0, 0.0);
	float xmin = -100;
	float xmax = 100;
	float ymin = 0;
	float ymax = 200;
	float aspect = (float)w / h;

	float ratio = (xmax - xmin) / (ymax - ymin);
	if (ratio < aspect) glScalef(ratio / aspect, 1, 1);
	else glScalef(1, aspect / ratio, 1);
}
void PerspectiveCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
