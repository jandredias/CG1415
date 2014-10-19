#include "stdafx.h"
#include "Header.h"
#include "PerspectiveCamera.h"

extern int y;
extern int z;

PerspectiveCamera::PerspectiveCamera() : Camera(0, 200){}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zFar, zNear){ _fovy = fovy; _aspect = aspect; }
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Frog *a) : PerspectiveCamera(fovy, aspect, zNear, zFar){ frog = a; }

void PerspectiveCamera::computeVisualizationMatrix(){
	//if (frog == NULL)
		gluPerspective(	_fovy, 1, getNear(), getFar());
	//else gluPerspective(_fovy, 1, getNear() + frog->getPosition().getY(), getFar() + frog->getPosition().getY());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void PerspectiveCamera::update(GLsizei w, GLsizei h){
	if (frog == NULL)
		gluLookAt(	0	,	-50	,	75,	//eyePosition
					0	,	100.0	,	0.0,	//Point Position
					0	,	0		,	1);		// Up Vector

	else{
		gluLookAt(	frog->getPosition().getX(),		frog->getPosition().getY(),	10 + frog->getPosition().getZ(),	//eyePosition
					frog->getPosition().getX(), 100.0 + frog->getPosition().getY(), 10 + frog->getPosition().getZ(),								//Point Position
					0	,	0		,	1);		// Up Vector
	}
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
