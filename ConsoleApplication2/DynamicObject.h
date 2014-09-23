#pragma once
class DynamicObject : GameObject
{
	Vector3 _speed;
public:
	DynamicObject();
	~DynamicObject();
	void update(double delta_t);
	void setSpeed(const Vector3* speed);
	void setSpeed(double x, double y, double z);
	Vector3 getSpeed();
};

