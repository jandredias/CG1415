
#include "LightSource.h"
#include "GL/glut.h"

LightSource::LightSource(unsigned long number){ _num = number; _state = true; }
LightSource::~LightSource(){ }
bool LightSource::getState(){ return _state; }
bool LightSource::setState(bool state){ 
	_state = state; 
	if (_num == 0){

		if (state) glEnable(GL_LIGHT0);
		else glDisable(GL_LIGHT0);
	}
	else {
		if (state){ glEnable(GL_LIGHT1); glEnable(GL_LIGHT2); glEnable(GL_LIGHT3); glEnable(GL_LIGHT4); glEnable(GL_LIGHT5); glEnable(GL_LIGHT6); }
		else{ glDisable(GL_LIGHT1); glDisable(GL_LIGHT2); glDisable(GL_LIGHT3); glDisable(GL_LIGHT4); glDisable(GL_LIGHT5); glDisable(GL_LIGHT6); }
	}
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

	
//	GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);

//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_shininess[] = { 50.0 };

//	GLfloat ambientColor[] = { .3, .3, .3, .1 }; 
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);


//	glShadeModel(GL_SMOOTH);

//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//luz direcional
	GLfloat lightIntensity0[] = { 0.5f, 0.5f, 0.5f, 1.0f }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity0);
	GLfloat light_position0[] = { 4, 0, 8, 0 }; //Luz direcional, 4� parametro a 0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	//candeeiro 1
	GLfloat lightIntensity1[] = { 1, 1, 1, 1 }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightIntensity1);
	GLfloat light_position1[] = { 0, 98, 0, 1 }; //Luz pontual, 4� parametro a 1
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	//candeeiro 2
	GLfloat lightIntensity2[] = { 1, 1, 1, 1 }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightIntensity2);
	GLfloat light_position2[] = { -60, 98, 0, 1 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

	//candeeiro 3
	GLfloat lightIntensity3[] = { 1, 1, 1, 1 }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lightIntensity3);
	GLfloat light_position3[] = { 60, 98, 0, 1 }; 
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);

	//candeeiro 4
	GLfloat lightIntensity4[] = { 1, 1, 1, 1 }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT4, GL_DIFFUSE, lightIntensity4);
	GLfloat light_position4[] = { 0, 2, 3, 1 };
	glLightfv(GL_LIGHT4, GL_POSITION, light_position4);

	//candeeiro 5
	GLfloat lightIntensity5[] = { 1, 1, 1, 1 }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT5, GL_DIFFUSE, lightIntensity5);
	GLfloat light_position5[] = { -60, 2, 3, 1 };
	glLightfv(GL_LIGHT5, GL_POSITION, light_position5);

	//candeeiro 6
	GLfloat lightIntensity6[] = { 1, 1, 1, 1 }; //Intesidade (0.5, 0.5, 0.5)
	glLightfv(GL_LIGHT6, GL_DIFFUSE, lightIntensity6);
	GLfloat light_position6[] = { 60, 2, 3, 1 }; 
	glLightfv(GL_LIGHT6, GL_POSITION, light_position6);
}
