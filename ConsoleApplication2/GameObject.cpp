#include "stdafx.h"
#include "GameObject.h"
#include "DynamicObject.h"

GameObject::GameObject(){}
GameObject::~GameObject(){}
void GameObject::update(double delta_t){}
void GameObject::setSize(int x, int y, int z){ _size.set(x, y, z); }
Vector3 GameObject::getSize(){ return _size; }