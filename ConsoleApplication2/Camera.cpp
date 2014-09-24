#include "stdafx.h"
#include "Camera.h"


Camera::Camera(double near, double far){
	this->_near = near;
	this->_far = far;
}


Camera::~Camera(){
	delete this;
}

void update(){

}

void computeProjectionMatrix(){

}

void computeVisualizationMatrix(){

}