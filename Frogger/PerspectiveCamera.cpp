#include "Frog.h"
#include "FrogTarget.h"
#include "Background.h"
#include "Road.h"
#include "Roadside.h"
#include "River.h"
#include "Riverside.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "TimberLog.h"
#include "Car.h"
#include <iostream>
#include "PerspectiveCamera.h"
extern int y;
extern int z;
#define NULL 0
PerspectiveCamera::PerspectiveCamera() : Camera(0, 200){ frog = NULL; }
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zNear, zFar){ _fovy = fovy; _aspect = aspect; }
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Frog *a) : PerspectiveCamera(fovy, aspect, zNear, zFar){ frog = a; }

void PerspectiveCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Vector3 To(getAt().getX() + getUp().getX(), getAt().getY() + getUp().getZ(), getAt().getZ() - getUp().getY());
	gluLookAt(	getAt().getX(), getAt().getY(),	getAt().getZ(),					//Camera position
				To.getX(), To.getY(), To.getZ(),			// Looking at
				getUp().getX(), getUp().getY(),			getUp().getZ());				// Up Vector
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
	gluPerspective(_fovy, _aspect, getNear(), getFar());
}
