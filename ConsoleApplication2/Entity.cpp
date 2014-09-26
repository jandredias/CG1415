#include "stdafx.h"
#include "Entity.h"

Entity::Entity(){}
Entity::~Entity(){}
Vector3* Entity::getPosition(void){return &_position;}
Vector3* Entity::setPosition(double x, double y, double z){_position.set(x,y,z); return &_position; }
Vector3* Entity::setPosition(Vector3* p){ _position.set(p->getX(), p->getY(), p->getZ());	return &this->_position; }