#include "Camera.h"

Camera::Camera(double near, double far){
	_near = near;
	_far = far;
	_at.set(0, 10, 120);
	_up.set(0, 10, 4);
}
Camera::~Camera(){}
double Camera::getNear(){ return _near; }
double Camera::getFar(){ return _far; }

void Camera::setUp(double x, double y, double z){
	_up.set(x, y, z);
}
void Camera::setAt(double x, double y, double z){
	_at.set(x, y, z);
}
Vector3 Camera::getUp(){
	return _up;
}
Vector3 Camera::getAt(){
	return _at;
}