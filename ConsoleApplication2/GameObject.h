#pragma once

#include "Entity.h"
#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__
class GameObject : public Entity
{
public:
	GameObject();
	~GameObject();
	void draw();
	void update(double delta_t);
};


#endif