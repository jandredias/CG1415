
#include "LimitMap.h"

LimitMap::LimitMap(Vector3 a, Vector3 b){
	setSize(a.getX(), a.getY(), a.getZ());
	setPosition(b.getX(), b.getY(), b.getZ());
}
LimitMap::~LimitMap(){}
void LimitMap::draw(){}