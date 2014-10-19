#include "stdafx.h"
#include "Header.h"
#include "PerspectiveCamera.h"

extern int y;
extern int z;

PerspectiveCamera::PerspectiveCamera() :Camera(-100, 100){}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zFar, zNear){ _fovy = fovy; _aspect = aspect; }
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Frog *a) : PerspectiveCamera(fovy, aspect, zNear, zFar){}

void PerspectiveCamera::computeVisualizationMatrix(){
	gluPerspective(	_fovy, 1,
					getNear(), getFar());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void PerspectiveCamera::update(GLsizei w, GLsizei h){
	
	gluLookAt(	0	,	-50	,	75,	//eyePosition
				0	,	100.0	,	0.0,	//Point Position
				0	,	0		,	1);		// Up Vector


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
