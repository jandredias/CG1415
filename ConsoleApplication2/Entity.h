#pragma once
class Entity
{
	Vector3 _position;
public:
	Entity();
	~Entity();
	Vector3* getPosition();
	Vector3* setPosition(double x, double y, double z);
	Vector3* setPosition(const Vector3*);
};

