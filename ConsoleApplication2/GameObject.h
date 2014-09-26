#pragma once

#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
class GameObject : public Entity
{
	public:
		GameObject();
		~GameObject();
		void draw();
		void update(double delta_t);
};


#endif