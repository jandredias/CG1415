
#include "DynamicObject.h"
#include "GameManager.h"
#include "Frog.h"
#include "StaticObject.h"

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
	if ((getPosition().getX() + getSize().getX()) > (a->getPosition().getX() - a->getSize().getX()) &&
		(getPosition().getX() - getSize().getX()) < (a->getPosition().getX() + a->getSize().getX()) &&

		(getPosition().getY() + getSize().getY()) > (a->getPosition().getY() - a->getSize().getY()) &&
		(getPosition().getY() - getSize().getY()) < (a->getPosition().getY() + a->getSize().getY()) &&

		(getPosition().getZ() + getSize().getZ()) > (a->getPosition().getZ() - a->getSize().getZ()) &&
		(getPosition().getZ() - getSize().getZ()) < (a->getPosition().getZ() + a->getSize().getZ()))
	{
		return 1;
	}
	return 0;
}
