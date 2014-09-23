#include "stdafx.h"
#include "Entity.h"


Entity::Entity(){
	Vector3* _position = new Vector3;
}

Entity::~Entity(){
	delete _position;
}

Vector3* Entity::getPosition(){
	return this->_position;
}

Vector3* Entity::setPosition(double x, double y, double z){
	this->_position[0] = x;
	this->_position[1] = y;
	this->_position[2] = z;
	return this->_position;
}

Vector3* Entity::setPosition(const Vector3* p){
	this->_position[0] = p[0];
	this->_position[1] = p[1];
	this->_position[2] = p[2];
	return this->_position;
}