#include "stdafx.h"
#include "OrthogonalCamera.h"
#include "Camera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far):Camera(near, far)
{ _left = left; _right = right; _top = top; _bottom = bottom; }


OrthogonalCamera::~OrthogonalCamera(){
}

void OrthogonalCamera::update(){

}
void OrthogonalCamera::computeProjectionMatrix(){

}
void OrthogonalCamera::computeVisualizationMatrix(){

}