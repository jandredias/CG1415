#pragma once

#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"

class GameObject : public Entity
{
	Vector3 _size;
	public:
		GameObject();
		~GameObject();
		virtual void draw() = 0;
		virtual void update(double delta_t);
		void setSize(double x, double y, double z);
		Vector3 getSize();
};


#endif
