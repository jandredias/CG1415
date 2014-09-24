#include "stdafx.h"
#include "Entity.h"
#include "Vector3.h"


Entity::Entity(){
}

Entity::~Entity(){
	delete this;
}

Vector3* Entity::getPosition(void){
	return &this->_position;
}

Vector3* Entity::setPosition(double x, double y, double z){
	this->_position.set(x,y,z);
	return &this->_position;
}

Vector3* Entity::setPosition(Vector3* p){
	this->_position.set(p->getX(), p->getY(), p->getZ());
	return &this->_position;
}