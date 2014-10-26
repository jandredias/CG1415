#include "stdafx.h"
#include "DynamicObject.h"
#include "GameManager.h"
#include "Frog.h"
#include "staticObject.h"

extern GameManager *gm;

DynamicObject::DynamicObject(){}
DynamicObject::~DynamicObject(){}

void DynamicObject::update(double delta_t){
	setPosition(getPosition().getX() + getSpeed().getX() * delta_t * gm->getGameSpeed() / 1000,
				getPosition().getY() + getSpeed().getY() * delta_t * gm->getGameSpeed() / 1000,
				getPosition().getZ());
}
void DynamicObject::setSpeed(Vector3* speed){ _speed.set(speed->getX(), speed->getY(),speed->getZ()); }
void DynamicObject::setSpeed(double x, double y, double z){ _speed.set(x, y, z); }
Vector3 DynamicObject::getSpeed(){	return _speed; }
bool DynamicObject::HasColision(GameObject *a){
	if ((getPosition().getX() + getSize().getX() / 2) > (a->getPosition().getX() - a->getSize().getX() / 2) &&
		(getPosition().getX() - getSize().getX() / 2) < (a->getPosition().getX() + a->getSize().getX() / 2) &&

		(getPosition().getY() + getSize().getY() / 2) > (a->getPosition().getY() - a->getSize().getY() / 2) &&
		(getPosition().getY() - getSize().getY() / 2) < (a->getPosition().getY() + a->getSize().getY() / 2) &&

		(getPosition().getZ() + getSize().getZ() / 2) > (a->getPosition().getZ() - a->getSize().getZ() / 2) &&
		(getPosition().getZ() - getSize().getZ() / 2) < (a->getPosition().getZ() + a->getSize().getZ() / 2))
	{
		return 1;
	}
	return 0;
}