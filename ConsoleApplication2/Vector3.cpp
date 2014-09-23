#include "stdafx.h"
#include "Vector3.h"


Vector3::Vector3(){
	this->_x = 0;
	this->_y = 0;
	this->_z = 0;
}

Vector3::Vector3(double x, double y, double z){
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

Vector3::~Vector3(){
	delete this;
}

double Vector3::getX(){ return this->_x; }
double Vector3::getY(){ return this->_y; }
double Vector3::getZ(){ return this->_z; }

void Vector3::set(double x, double y, double z){
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

Vector3 Vector3::operator=(Vector3 *vec){
	//this->set(vec->getX(), vec->getY(), vec->getZ());
	this->_x = vec->getX();
	this->_y = vec->getY();
	this->_z = vec->getZ();
	return *this;

}
Vector3 Vector3::operator*(double num){
	this->_x *= num;
	this->_y *= num;
	this->_z *= num;
	return *this;
}

Vector3 Vector3::operator+(Vector3 *vec){
	this->_x += vec->getX();
	this->_y += vec->getY();
	this->_z += vec->getZ();
	return *this;
}
Vector3 Vector3::operator-(Vector3 *vec){
	this->_x -= vec->getX();
	this->_y -= vec->getY();
	this->_z -= vec->getZ();
	return *this;
}