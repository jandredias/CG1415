#include "stdafx.h"
#include "Camera.h"


Camera::Camera(double near, double far){ _near = near; _far = far; }
Camera::~Camera(){}
double Camera::getNear(){ return _near; }
double Camera::getFar(){ return _far; }