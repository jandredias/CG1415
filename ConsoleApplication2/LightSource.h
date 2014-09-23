#pragma once
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
	void setPosition(const *Vector4 position);
	void setDirection(const *Vector4 direction);
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(const Vector4 *ambient);
	void setDiffuse(const Vector4 *diffuse);
	void setSpecular(const Vector4 *specular);
	void draw();
};

