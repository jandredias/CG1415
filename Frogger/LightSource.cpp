
#include "LightSource.h"
#include "GL/glut.h"
#include <iostream>
LightSource::LightSource(unsigned long number){ _num = number; _state = false; }
LightSource::~LightSource(){ }
bool LightSource::getState(){ return _state; }
bool LightSource::setState(bool state){
	_state = state;
	if (state){
		glEnable(GL_LIGHT0 + _num);
	}
	else{
		glDisable(GL_LIGHT0 + _num);
	}
	return _state; 
}
unsigned long LightSource::getNum(){ return _num; }
void LightSource::setPosition(GLdouble x, GLdouble y, GLdouble z, GLdouble w){ _position.set(x, y, z, w); }
Vector4* LightSource::getPosition(){ return &_position; }
void LightSource::setDirection(GLdouble x, GLdouble y, GLdouble z){ _direction.set(x,y,z); }
void LightSource::setCutOff(double cut_off){ _cut_off = cut_off; }
void LightSource::setExponent(double exponent){ _exponent = exponent; }
void LightSource::setAmbient(GLdouble x, GLdouble y, GLdouble z, GLdouble w){ _ambient.set(x, y, z, w); }
void LightSource::setDiffuse(GLdouble x, GLdouble y, GLdouble z, GLdouble w){ _diffuse.set(x, y, z, w); }
void LightSource::setSpecular(GLdouble x, GLdouble y, GLdouble z, GLdouble w){ _specular.set(x,y,z,w); }
void LightSource::draw(){
	GLfloat light_position[] = { (GLfloat)_position.getX(), (GLfloat)_position.getY(), (GLfloat)_position.getZ(), (GLfloat)_position.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_POSITION, light_position);

	GLfloat ambient[] = { (GLfloat)_ambient.getX(), (GLfloat)_ambient.getY(), (GLfloat)_ambient.getZ(), (GLfloat)_ambient.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_AMBIENT, ambient);

	GLfloat diffuse[] = { (GLfloat)_diffuse.getX(), (GLfloat)_diffuse.getY(), (GLfloat)_diffuse.getZ(), (GLfloat)_diffuse.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_DIFFUSE, diffuse);

	GLfloat specular[] = { (GLfloat)_specular.getX(), (GLfloat)_specular.getY(), (GLfloat)_specular.getZ(),(GLfloat) _specular.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0 + _num, GL_EXP, &_exponent);
	GLfloat direction[] = { (GLfloat)_direction.getX(),(GLfloat) _direction.getY(),(GLfloat) _direction.getZ() };
	glLightfv(GL_LIGHT0 + _num, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT0 + _num, GL_SPOT_CUTOFF, _cut_off);
	glLightfv(GL_LIGHT0 + _num, GL_CONSTANT_ATTENUATION, &_exponent);
		/*GLfloat a = 0.009, b = 0.0015, c = 0.001;
		
		glLightfv(GL_LIGHT0 + _num, GL_LINEAR_ATTENUATION, &b);
		glLightfv(GL_LIGHT0 + _num, GL_QUADRATIC_ATTENUATION, &c);*/
}
