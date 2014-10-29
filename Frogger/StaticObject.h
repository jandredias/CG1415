#ifndef __STATICOBJECT__
#define __STATICOBJECT__

#include "GameObject.h"
class StaticObject : public GameObject{
	public:
		StaticObject();
		~StaticObject();
		bool OutOfScene();
};
#endif
