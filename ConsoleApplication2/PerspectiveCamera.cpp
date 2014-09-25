#include "stdafx.h"
#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera():Camera(5,5){

}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar):Camera(5, 5){

}

PerspectiveCamera::~PerspectiveCamera(){
}
void PerspectiveCamera::update(){

}
void PerspectiveCamera::computeProjectionMatrix(){

}
void PerspectiveCamera::computeVisualizationMatrix(){

}