#include "stdafx.h"
#include "DynamicObject.h"
#include "GameManager.h"
#include "Frog.h"
extern GameManager *gm;
DynamicObject::DynamicObject(){}
DynamicObject::~DynamicObject(){}

void DynamicObject::update(double delta_t){
	setPosition(getPosition()->getX() + getSpeed()->getX()*delta_t, getPosition()->getY() + getSpeed()->getY()*delta_t, getPosition()->getZ());
	Frog* v = dynamic_cast<Frog*>(this);
	
	if (v != 0){
		//Testa movimento do sapo fora do mapa X
		if (getPosition()->getX() > 90)
			setPosition(90, getPosition()->getY(), getPosition()->getZ());
		else if (getPosition()->getX() < -90)
			setPosition(-90, getPosition()->getY(), getPosition()->getZ());

		//Testa movimento do sapo fora do mapa Y
		if (getPosition()->getY() > 195)
			setPosition(getPosition()->getX(), 195, getPosition()->getZ());
		else if (getPosition()->getY() < 13)
			setPosition(getPosition()->getX(), 13, getPosition()->getZ());
	}
	
	/*
	Frog* v = dynamic_cast<Frog*>(this);
	if (v != 0) {
	}
	else{
		//std::cout << getSpeed()->getX();
		setPosition(getPosition()->getX() + getSpeed()->getX(), getPosition()->getY(), getPosition()->getZ());
	}
	//setSpeed(0, 0, 0);*/
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
Vector3* DynamicObject::getSpeed(){	return &_speed; }

bool DynamicObject::OutOfScene(){
	if (getSpeed()->getX() > 0 && getPosition()->getX() - _size / 2 > 100){
		return true;
	}
	else{
		if (getSpeed()->getY() < 0 && abs(getPosition()->getX()) + _size / 2 + 100 > 100)
			return true;
	}
	return false;
}

int DynamicObject::setSize(int a){ _size = a; return _size; }
int DynamicObject::getSize(){ return _size; }