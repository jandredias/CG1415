#include "stdafx.h"
#include "Vector4.h"
#include "Vector3.h"


Vector4::Vector4(){	this->_w = 0; }
Vector4::Vector4(double x, double y, double z, double w):Vector3(x,y,z){ this->_w = w; }
Vector4::~Vector4(){ delete this; }
double Vector4::getW(){ return this->_w; }
void Vector4::set(double x, double y, double z, double w){ Vector3::set(x, y, z); this->_w = w; }
Vector4 Vector4::operator=(Vector4 *vec){ Vector3::set(vec->getX(), vec->getY(), vec->getZ()); this->_w = vec->getW(); }
Vector4 Vector4::operator*(double num){ Vector3::set(Vector3::getX()*num, Vector3::getY()*num,Vector3::getZ()*num);	this->_w *= num; }
Vector4 Vector4::operator+(Vector4 *vec){ 
	Vector3::set(Vector3::getX() + vec->getX(), Vector3::getY() + vec->getY(), Vector3::getZ() + vec->getZ());
	this->_w += vec->getW();
}
Vector4 Vector4::operator-(Vector4 *vec){
	Vector3::set(Vector3::getX() - vec->getX(), Vector3::getY() - vec->getY(), Vector3::getZ() - vec->getZ());
	this->_w -= vec->getW();
}
