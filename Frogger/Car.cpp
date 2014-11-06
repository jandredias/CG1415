#include "GL/glut.h"
#include <iostream>
#include <math.h>
#include "math.h"
#include "Car.h"
#define PI		3.14159265358979323846
						
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
		//glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		glTranslatef(getSize().getX(),0,0);
		if (getSpeed().getX() > 0) glRotatef(180, 0, 0, 1);
		glTranslated(2, 0, 0);
			defineMaterial(	0.01, 0.01, 1.00, 1.00,	//Ambient
							0.01, 0.01, 1.00, 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0, 0, 1);
			for(int i = 0; i < 2; i ++){
			glPushMatrix();
				glTranslatef(0.0,(i == 0) ? -getSize().getY() : getSize().getY(), 0.0); 
				glPushMatrix();
					glBegin(GL_QUADS);
						glNormal3f(0,-1,0);
						glVertex3f(0,0,0);
						glVertex3f(2*getSize().getX(),0,0);
						glVertex3f(2*getSize().getX(),0,3);
						glVertex3f(0,0,3);
					glEnd();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(2, 0, 0);
					WHEELS::executeNew(8, 2);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(2*getSize().getX()-2, 0, 0);
					WHEELS::executeNew(8, 2);
				glPopMatrix();
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
			
			defineMaterial(	0.05, 0.05, 0.05, 1.00,	//Ambient
							0.70, 0.70, 0.70, 1.00,	//Diffuse
							0.70, 0.70, 0.70, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(0.7,0.7,0.7);
			glBegin(GL_POLYGON); // Trapezio frente
				glNormal3f(0,-1,0);
				glVertex3f(2,-getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 2,-getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 3,-getSize().getY(),5);
				glVertex3f(3,-getSize().getY(),5);
			glEnd();
			
			glBegin(GL_POLYGON); // Trapezio traz
				glNormal3f(0,1,0);
				glVertex3f(2,getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 2,getSize().getY(),3);
				glVertex3f(2*getSize().getX() - 4,getSize().getY(),5);
				glVertex3f(3,getSize().getY(),5);
			glEnd();
			
			glBegin(GL_POLYGON); // Topo
				glNormal3f(0,0,1);
				glVertex3f(2*getSize().getX() - 3,-getSize().getY(),5);
				glVertex3f(3,-getSize().getY(),5);
				glVertex3f(3,getSize().getY(),5);
				glVertex3f(2*getSize().getX() - 4,getSize().getY(),5);
			glEnd();
			
			
			
		glPopMatrix();
		return;
		
		//Cubo principal do corpo do carro
		glPushMatrix();
			defineMaterial(	_color.getX(), _color.getY(), _color.getZ(), 1.00,	//Ambient
							_color.getX(), _color.getY(), _color.getZ(), 1.00,	//Diffuse
							1.00, 1.00, 1.00, 1.00,	//Specular
							0.00, 0.00, 0.00, 1.00,	//Emission
							77);					//SHININESS
			glColor3f(_color.getX(), _color.getY(), _color.getZ());

			glScalef(12, 8, 4);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo da frente, onde esta o motor
		glPushMatrix();
			glTranslated(-8.5, 0, 0);
			glScalef(5, 4, 2);
			glutSolidCube(1);
		glPopMatrix();

		//Eixo da roda direita da frente
		glPushMatrix();
			glTranslated(-10, 2.5, 0);
			glScalef(2, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Eixo da roda esquerda da frente
		glPushMatrix();
			glTranslated(-10, -2.5, 0);
			glScalef(2, 1, 0);
			glutSolidCube(1);
		glPopMatrix();
		
		//Spoiler
		defineMaterial(	1.00, 0.10, 0.10, 1.00,	//Ambient
						1.00, 0.10, 0.10, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(1, 0, 0);
		glPushMatrix();
			glTranslated(5.5, 0, 0);
			glScalef(3, 6, 3);
			glutSolidCube(1);
		glPopMatrix();

		//Cockpit		
		defineMaterial(	1.00, 1.00, 1.00, 1.00,	//Ambient
						1.00, 1.00, 1.00, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(1, 1, 1);
		glPushMatrix();
			glTranslated(-2.5, 0, 0);
			glScalef(3, 4, 3);
			glutSolidCube(1);
		glPopMatrix();

	glPopMatrix();
}
