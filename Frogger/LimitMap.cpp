
#include "LimitMap.h"
#include "GL/glut.h"

LimitMap::LimitMap(Vector3 a, Vector3 b){
	setSize(a.getX()/2, a.getY()/2, a.getZ()/2);
	setPosition(b.getX(), b.getY(), b.getZ());
}
LimitMap::~LimitMap(){}
void LimitMap::draw(){}
