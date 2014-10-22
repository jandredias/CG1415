#include "stdafx.h"
#include "Header.h"
#include "PerspectiveCamera.h"

extern int y;
extern int z;

PerspectiveCamera::PerspectiveCamera() : Camera(0, 200){}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zFar, zNear){ _fovy = fovy; _aspect = aspect; }
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Frog *a) : PerspectiveCamera(fovy, aspect, zNear, zFar){ frog = a; }

void PerspectiveCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, z,	//Camera position
		      0, 100, 0,	// Looking at
		      0, sqrt(2)/2, -sqrt(2) / 2);		// Up Vector
}
void PerspectiveCamera::update(GLsizei w, GLsizei h){
	float xmin = -100;
	float xmax = 100;
	float ymin = 0;
	float ymax = 200;
	float aspect = (float)w / h;

	float ratio = (xmax - xmin) / (ymax - ymin);
	if (ratio < 0 || aspect < 0) std::cout << "NEGATIVE SCALE";

	if (ratio < aspect) glScalef(ratio / aspect, 1, 1);
	else glScalef(1, aspect / ratio, 1);
}
void PerspectiveCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(_fovy, 1, getNear(), getFar());
	gluPerspective(90, 1, 1, 2000);
}
