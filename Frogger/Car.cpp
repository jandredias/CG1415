#include "GL/glut.h"
#include <iostream>
#include <math.h>
#include "math.h"
#include "Car.h"
#include "GameManager.h"
extern GameManager *gm;
Car::Car(){
	setPosition(0, 0, 0);
	setSpeed(0, 0, 0);
	_color.set(new Vector3(rand() % 100 * 0.01,rand() % 100 * 0.01,rand() % 100 * 0.01));
}
Car::Car(double x, double y, double z) : Car() {  setPosition(x, y, z); setSize(7.5, 3, 5); }
Car::Car(double x, double y, double z, double w) : Car(x, y, z) { setSpeed(w, 0, 0); }
Car::~Car(){}

void Car::draw(){
	class WHEELS{
	public:
		static void executeNew(GLdouble no_sides, GLdouble size){
			float graus = 2 * PI / no_sides;
			GLfloat cos_aux = cos(graus / 2);
			GLfloat sin_aux = sin(graus / 2);
			glPushMatrix();
			for (int a = 0; a < no_sides; a++){
				glBegin(GL_QUADS);
					glNormal3f(cos_aux, 0, sin_aux); glVertex3f(cos_aux*size, 1, sin_aux*size);		//1
					glNormal3f(cos_aux, 0, -sin_aux); glVertex3f(cos_aux*size, 1, -sin_aux*size);		//1
					glNormal3f(cos_aux, 0, -sin_aux); glVertex3f(cos_aux*size, -1, -sin_aux*size);	//1
					glNormal3f(cos_aux, 0, sin_aux); glVertex3f(cos_aux*size, -1, sin_aux*size);		//1
				glEnd();
				glRotatef(360 / no_sides, 0, 1, 0);
			}
			glPopMatrix();
			for(int i = 0; i < 2; i++){
				glPushMatrix();
					glTranslatef(0, (i == 0) ? 1 : -1, 0);
					glBegin(GL_POLYGON);
					glNormal3f(0, (i == 0) ? 1 : -1, 0);
					for (int a = 0; a < no_sides; a++)
						glVertex3f(cos(graus * a + graus / 2)*size, 0, sin(graus * a + graus / 2)*size);
					glEnd();
				glPopMatrix();
			}
		}
	};

	glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		if (gm->getDebug()){
			glPushMatrix();
			glScalef(getSize().getX() * 2, getSize().getY() * 2, getSize().getZ() * 2);
			glutWireCube(1);
			glPopMatrix();
		}
		if (getSpeed().getX() < 0) glRotatef(180, 0, 0, 1);
		glTranslated(-getSize().getX(), 0, 0);
			
		//WHEELS
		defineMaterial(0.00, 0.00, 0.00, 1.00,	//Ambient
			0.01, 0.01, 0.01, 1.00,	//Diffuse
			0.50, 0.50, 0.50, 1.00,	//Specular
			0.00, 0.00, 0.00, 1.00,	//Emission
			32);					//SHININESS
		glColor3f(0.01, 0.01, 0.01);
		for (int i = 0; i < 2; i++){
			glPushMatrix();
				glTranslatef(0.0, (i == 0) ? -getSize().getY() : getSize().getY(), 0.0);
				glPushMatrix();
					glTranslatef(2, 0, 0);
					WHEELS::executeNew(8, 2);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(2 * getSize().getX() - 2, 0, 0);
					WHEELS::executeNew(8, 2);
				glPopMatrix();
			glPopMatrix();
		}
		defineMaterial(_color.getX()*0.1, _color.getY()*0.1, _color.getZ()*0.1, 1.00,	//Ambient
			_color.getX(), _color.getY(), _color.getZ(), 1.00,	//Diffuse
			_color.getX(), _color.getY(), _color.getZ(), 1.00,	//Specular
			0.00, 0.00, 0.00, 1.00,	//Emission
			77);					//SHININESS
		glColor3f(_color.getX(), _color.getY(), _color.getZ());
		for (int i = 0; i < 2; i++){
			glPushMatrix();
			glTranslatef(0.0, (i == 0) ? -getSize().getY() : getSize().getY(), 0.0);
					glBegin(GL_QUADS);
						glNormal3f(0,-1,0);
						glVertex3f(0,0,0);
						glVertex3f(2*getSize().getX(),0,0);
						glVertex3f(2*getSize().getX(),0,3);
						glVertex3f(0,0,3);
					glEnd();
			glPopMatrix();
		}
			
			glBegin(GL_POLYGON);
				glNormal3f(-1,0,0);
				glVertex3f(0,getSize().getY(),0);
				glVertex3f(0,getSize().getY(),3);
				glVertex3f(0,-getSize().getY(),3);
				glVertex3f(0,-getSize().getY(),0);
			glEnd();
			glBegin(GL_POLYGON);
				glNormal3f(1,0,0);
				glVertex3f(2*getSize().getX(),getSize().getY(),0);
				glVertex3f(2*getSize().getX(),getSize().getY(),3);
				glVertex3f(2*getSize().getX(),-getSize().getY(),3);
				glVertex3f(2*getSize().getX(),-getSize().getY(),0);
			glEnd();
			
			
			glBegin(GL_POLYGON); // Parte de baixo do carro
				glNormal3f(0,0,-1);
				glVertex3f(0,getSize().getY(),0);
				glVertex3f(2*getSize().getX(),getSize().getY(),0);
				glVertex3f(2*getSize().getX(),-getSize().getY(),0);
				glVertex3f(0,-getSize().getY(),0);
			glEnd();
			glBegin(GL_POLYGON); // Parte de cima do carro
				glNormal3f(0,0,1);
				glVertex3f(0,getSize().getY(),3);
				glVertex3f(2*getSize().getX(),getSize().getY(),3);
				glVertex3f(2*getSize().getX(),-getSize().getY(),3);
				glVertex3f(0,-getSize().getY(),3);
			glEnd();
			
			//defineMaterial(	0.05, 0.05, 0.05, 1.00,	//Ambient
			//				0.70, 0.70, 0.70, 1.00,	//Diffuse
			//				0.70, 0.70, 0.70, 1.00,	//Specular
			//				0.00, 0.00, 0.00, 1.00,	//Emission
			//				77);					//SHININESS
			//glColor3f(0.7,0.7,0.7);
			
			glBegin(GL_POLYGON); // Topo
				glNormal3f(0,0,1);
				glVertex3f(2*getSize().getX() - 6,-getSize().getY(),5);
				glVertex3f(3,-getSize().getY(),5);
				glVertex3f(3,getSize().getY(),5);
				glVertex3f(2*getSize().getX() - 6,getSize().getY(),5);
			glEnd();
			

			defineMaterial(	0.05,0.05,0.07, 1.00,	//Ambient
							0.18, 0.17, 0.23, 1.00,	//Diffuse
							0.33, 0.33, 0.35, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0.25,0.25,0.25);
			glBegin(GL_POLYGON); // Trapezio frente
				glNormal3f(0,-1,0);
				glVertex3f(2,-getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 2,-getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 6,-getSize().getY(),5);
				glVertex3f(3,-getSize().getY(),5);
			glEnd();
			

			glBegin(GL_POLYGON); // Trapezio traz
				glNormal3f(0,1,0);
				glVertex3f(2,getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 2,getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 6,getSize().getY(),5);
				glVertex3f(3,getSize().getY(),5);
			glEnd();
			glBegin(GL_POLYGON);
				glNormal3f(-2, 0, 1);
				glVertex3f(2, getSize().getY(), 3);
				glVertex3f(3, getSize().getY(), 5);
				glVertex3f(3, -getSize().getY(), 5);
				glVertex3f(2, -getSize().getY(), 3);
			glEnd();
			glBegin(GL_POLYGON);
				glNormal3f(2, 0, 4);
				glVertex3f(2 * getSize().getX() - 2, getSize().getY(), 3);
				glVertex3f(2 * getSize().getX() - 6, getSize().getY(), 5);
				glVertex3f(2 * getSize().getX() - 6, -getSize().getY(), 5);
				glVertex3f(2 * getSize().getX() - 2, -getSize().getY(), 3);
			glEnd();
		glPopMatrix();
}
