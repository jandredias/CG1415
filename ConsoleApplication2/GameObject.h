#pragma once
class GameObject :public Entity
{
public:
	GameObject();
	~GameObject();
	void draw();
	void update(double delta_t);
};

