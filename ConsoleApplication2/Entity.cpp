#include "stdafx.h"
#include "Entity.h"

Entity::Entity(){}
Entity::~Entity(){}
Vector3 Entity::getPosition(void){return _position;}
void Entity::setPosition(double x, double y, double z){ _position.set(x,y,z); }
void Entity::setPosition(Vector3* p){ _position.set(p->getX(), p->getY(), p->getZ()); }
