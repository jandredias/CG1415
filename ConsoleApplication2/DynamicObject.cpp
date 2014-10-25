#include "stdafx.h"
#include "DynamicObject.h"
#include "GameManager.h"
#include "Frog.h"
#include "staticObject.h"

extern GameManager *gm;

DynamicObject::DynamicObject(){}
DynamicObject::~DynamicObject(){}

void DynamicObject::update(double delta_t){
	Vector3 oldPosition(getPosition().getX(), getPosition().getY(), getPosition().getZ());
	setPosition(getPosition().getX() + getSpeed().getX() * delta_t * gm->getGameSpeed(),
				getPosition().getY() + getSpeed().getY() * delta_t * gm->getGameSpeed(),
				getPosition().getZ());

	Frog *v = dynamic_cast<Frog*>(this);
	if (v != 0){
		bool ColisionLimit = false;
		bool ColisionRiver = false;
		bool ColisionRiverside = false;
		bool ColisionTimberLog = false;
		bool ColisionCar = false;
		Vector3 speedLog;
		//Verify Map Limit
		for (DynamicObject *aux : gm->getDynamicObjects())
			if (dynamic_cast<TimberLog *> (aux) && HasColision(aux)){
				ColisionTimberLog = true;
				speedLog.set(aux->getSpeed().getX(), 0, 0);
			}
			else if ((dynamic_cast<Car*> (aux) && HasColision(aux))) ColisionCar = true;

		for (StaticObject *aux : gm->getStaticObjects())
			if (dynamic_cast<LimitMap *> (aux) && HasColision(aux))
				ColisionLimit = true;
			else if (dynamic_cast<River *> (aux) && HasColision(aux)) ColisionRiver = true;
			else if (dynamic_cast<Riverside *> (aux) && HasColision(aux)) ColisionRiverside = true;

			if (ColisionLimit) setPosition(oldPosition.getX(), oldPosition.getY(), oldPosition.getZ());
			else if (ColisionCar || (ColisionRiver && !(ColisionRiverside || ColisionTimberLog))){
				setSpeed(0, 0, 0);
				setPosition(0, 10, -1);
			}
			if (!ColisionTimberLog) v->setSpeedLog(0, 0, 0);
			if (ColisionTimberLog && v->getSpeedLog().getX() == 0) v->setSpeedLog(speedLog.getX(), 0, 0);
	}
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