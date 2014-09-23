#include "stdafx.h"
#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far)
{
	Camera(near, far);
	this->_left = left;
	this->_right = right;
	this->_top = top;
	this->_bottom = bottom;
}


OrthogonalCamera::~OrthogonalCamera()
{
}

void update();
void computeProjectionMatrix(){

}
void computeVisualizationMatrix(){

}