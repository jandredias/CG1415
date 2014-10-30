
#include "LightSource.h"
#include "GL/glut.h"

LightSource::LightSource(unsigned long number){ _num = number; _state = true; }
LightSource::~LightSource(){ }
bool LightSource::getState(){ return _state; }
bool LightSource::setState(bool state){ 
	_state = state; 
	if (state) glEnable(GL_LIGHT0);
	else glDisable(GL_LIGHT0); 
	return _state; 
}
unsigned long LightSource::getNum(){ return _num; }
void LightSource::setPosition(Vector4 * position){ _position = position; }
void LightSource::setDirection(Vector4 *direction){ _direction = direction; }
void LightSource::setCutOff(double cut_off){ _cut_off = cut_off; }
void LightSource::setExponent(double exponent){ _exponent = exponent; }
void LightSource::setAmbient(Vector4 *ambient){ _ambient = ambient; }
void LightSource::setDiffuse(Vector4 *diffuse){ _diffuse = diffuse; }
void LightSource::setSpecular(Vector4 *specular){ _specular = specular; }
void LightSource::draw(){

	

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	//GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f }; //Color(0.2, 0.2, 0.2)
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);


	glShadeModel(GL_SMOOTH);

//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat light_position[] = { 0, 0, 1, 0 }; //Luz direcional, 4º parametro a 0
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


}
