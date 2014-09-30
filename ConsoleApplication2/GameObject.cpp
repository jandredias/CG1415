#include "stdafx.h"
#include "GameObject.h"
#include "DynamicObject.h"

GameObject::GameObject(){}
GameObject::~GameObject(){}
void GameObject::update(double delta_t){
	DynamicObject* v = dynamic_cast<DynamicObject*>(this);
	if (v != 0) {
		// old was safely casted to NewType
		v->update(delta_t);
	}

}