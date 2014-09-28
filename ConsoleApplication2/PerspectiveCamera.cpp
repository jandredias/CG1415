#include "stdafx.h"
#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera():Camera(5,5){}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar):Camera(5, 5){}

void PerspectiveCamera::update(GLsizei w, GLsizei h){}
void PerspectiveCamera::computeProjectionMatrix(){}
void PerspectiveCamera::computeVisualizationMatrix(){}