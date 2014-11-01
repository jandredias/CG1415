#ifndef __LIGHTSOURCE__
#define __LIGHTSOURCE__

#include "Vector4.h"
#include "Vector3.h"
#include "GL/glut.h"
class LightSource
{
	Vector4 _ambient;
	Vector4 _diffuse;
	Vector4 _specular;
	Vector4 _position;
	Vector3 _direction;
	double	_cut_off;
	double	_exponent;
	unsigned long _num;
	bool	_state;
public:
	LightSource(unsigned long number);
	~LightSource();
	bool getState();
	bool setState(bool state);
	unsigned long getNum();
	Vector4* getPosition();
	void setPosition(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setDirection(GLdouble x, GLdouble y, GLdouble z);
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setDiffuse(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setSpecular(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void draw();
};


#endif

