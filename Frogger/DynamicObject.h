#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__

#include "GameObject.h"
#include "Vector3.h"
class DynamicObject : public GameObject
{
	Vector3 _speed;
	public:
		DynamicObject();
		~DynamicObject();
		virtual void update(double delta_t);
		void setSpeed(Vector3* speed);
		void setSpeed(double x, double y, double z);
		Vector3 getSpeed();
		bool HasColision(GameObject *);

};

#endif