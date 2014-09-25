#include "stdafx.h"
#include "LightSource.h"


LightSource::LightSource(unsigned long number){ _num = number; }
LightSource::~LightSource(){ }
bool LightSource::getState(){ return _state; }
bool LightSource::setState(bool state){ _state = state; return _state; }
unsigned long LightSource::getNum(){ return _num; }
void LightSource::setPosition(Vector4 * position){ _position = position; }
void LightSource::setDirection(Vector4 *direction){ _direction = direction; }
void LightSource::setCutOff(double cut_off){ _cut_off = cut_off; }
void LightSource::setExponent(double exponent){ _exponent = exponent; }
void LightSource::setAmbient(Vector4 *ambient){ _ambient = ambient; }
void LightSource::setDiffuse(Vector4 *diffuse){ _diffuse = diffuse; }
void LightSource::setSpecular(Vector4 *specular){ _specular = specular; }
void LightSource::draw(){//FALTA O DRAW!!!!!!!!!!!!!!!!!!!!!!!!!
}
