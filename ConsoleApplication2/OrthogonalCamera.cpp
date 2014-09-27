#include "stdafx.h"
#include "GL/GLUT.h"
#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far):Camera(near, far)
{ _left = left; _right = right; _top = top; _bottom = bottom; }


OrthogonalCamera::~OrthogonalCamera(){}

void OrthogonalCamera::update(){

}
void OrthogonalCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
void OrthogonalCamera::computeVisualizationMatrix(){

}