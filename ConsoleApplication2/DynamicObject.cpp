#include "stdafx.h"
#include "DynamicObject.h"
#include "Frog.h"
#include <iostream>
DynamicObject::DynamicObject()
{
}


DynamicObject::~DynamicObject()
{
}

void DynamicObject::update(double delta_t){
	Frog* v = dynamic_cast<Frog*>(this);
	if (v != 0) {
		setPosition(getPosition()->getX() + getSpeed()->getX(), getPosition()->getY() + getSpeed()->getY(), getPosition()->getZ());
	}
	else{
		//std::cout << getSpeed()->getX();
		setPosition(getPosition()->getX() + getSpeed()->getX(), getPosition()->getY(), getPosition()->getZ());
	}
	
}
Vector3* DynamicObject::setSpeed(Vector3* speed){
	_speed.set(speed->getX(), speed->getY(),speed->getZ());
	return &_speed;
}
Vector3* DynamicObject::setSpeed(double x, double y, double z){
	_speed.set(x, y, z);
	//std::cout << _speed.getX();
	return &_speed;
}
Vector3* DynamicObject::getSpeed(){
	return &_speed;
}

bool DynamicObject::OutOfScene(){
	if (getPosition()->getX() + _size / 2 > 100){ std::cout << 'T' << 1 << '\n'; return true; }
	/*std::cout << 0;*/return false;
}

int DynamicObject::setSize(int a){ _size = a; return _size; }
int DynamicObject::getSize(){ return _size; }