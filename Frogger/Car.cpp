#include "GL/glut.h"
#include <iostream>
#include <math.h>
#include "math.h"
#include "Car.h"
#define PI		3.14159265358979323846
						
Car::Car(){
	Vector3 *a = new Vector3();
	switch (rand() % 10){
	case 0: a->set(0.8, 0.8, 0.8); break;
	case 1: 
	case 2: 
	case 3: a->set(1.0, 0.1, 0.1); break;
	case 4: a->set(0.1, 0.1, 1.0); break;
	case 5: a->set(1.0, 0.5, 0.05); break;
	case 6:
	case 7:
	case 8:
	case 9: a->set(0.0, 0.0, 0.0); break;

	}
	setPosition(0, 0, 0); setSpeed(0, 0, 0); _color.set(a);
	delete(a);
}
Car::Car(double x, double y, double z) : Car() {  setPosition(x, y, z); setSize(16, 10, 5); }
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
			glPushMatrix();
			glTranslatef(0, 1, 0);
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			for (int a = 0; a < no_sides; a++)
				glVertex3f(cos(graus * a + graus / 2)*size, 0, sin(graus * a + graus / 2)*size);
			glEnd();

			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, -1, 0);
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			for (int a = 0; a < no_sides; a++)
				glVertex3f(cos(graus * a + graus / 2)*size, 0, sin(graus * a + graus / 2)*size);
			glEnd();

			glPopMatrix();
		}
		static void execute(GLdouble x, GLdouble y, GLdouble z, GLdouble radius, GLdouble t){
			glPushMatrix();
			glColor3f(0, 1, 0);
			// 1 => glNormal3f(0.5,-1/3,sqrt(3)/6);
			// 2 => glNormal3f(0.5,-1/3,-sqrt(3)/6);
			// 3 => glNormal3f(0,-1/3,-sqrt(3)/3);
			// 4 => glNormal3f(-1/3,-1/3,-sqrt(3)/6);
			// 5 => glNormal3f(-1/3,-1/3,sqrt(3)/6);
			// 6 => glNormal3f(0,-1/3,sqrt(3)/3);
			// 7 => glNormal3f(0.5,1/3,sqrt(3)/6);
			// 8 => glNormal3f(0.5,1/3,-sqrt(3)/6);
			// 9 => glNormal3f(0,1/3,-sqrt(3)/3);
			//10 => glNormal3f(-1/3,1/3,-sqrt(3)/6);
			//11 => glNormal3f(-1/3,1/3,sqrt(3)/6);
			//12 => glNormal3f(0,1/3,sqrt(3)/6);
			glTranslatef(x, y, z);
			glScalef(sqrt(3)*radius / 2, t, radius);
			glPushMatrix(); //Poligono da Frente
			glTranslatef(0, -t / 2, 0);
			glBegin(GL_POLYGON);
			//glNormal3f(0, -1, 0);
			glNormal3f(0, -1 / 3, sqrt(3) / 3);			glVertex3f(0, 0, 1);				//6
			glNormal3f(0.5, -1 / 3, sqrt(3) / 6);		glVertex3f(sqrt(3) / 2, 0, 0.5);	//1
			glNormal3f(0.5, -1 / 3, -sqrt(3) / 6);		glVertex3f(sqrt(3) / 2, 0, -0.5);	//2
			glNormal3f(0, -1 / 3, -sqrt(3) / 3);		glVertex3f(0, 0, -1);				//3
			glNormal3f(-1 / 3, -1 / 3, -sqrt(3) / 6);	glVertex3f(-sqrt(3) / 2, 0, -0.5);	//4
			glNormal3f(-1 / 3, -1 / 3, sqrt(3) / 6);	glVertex3f(-sqrt(3) / 2, 0, 0.5);	//5
			glEnd();
			glPopMatrix();
			glPushMatrix(); //Poligono de Tras
			glTranslatef(0, t / 2, 0);
			glBegin(GL_POLYGON);
			//glNormal3f(0, 1, 0);
			glNormal3f(0, 1 / 3, sqrt(3) / 6);			glVertex3f(0, 0, 1);				//12
			glNormal3f(0.5, 1 / 3, sqrt(3) / 6);		glVertex3f(sqrt(3) / 2, 0, 0.5);	//7
			glNormal3f(0.5, 1 / 3, -sqrt(3) / 6);		glVertex3f(sqrt(3) / 2, 0, -0.5);	//8
			glNormal3f(0, 1 / 3, -sqrt(3) / 3);			glVertex3f(0, 0, -1);				//9
			glNormal3f(-1 / 3, 1 / 3, -sqrt(3) / 6);	glVertex3f(-sqrt(3) / 2, 0, -0.5);	//10
			glNormal3f(-1 / 3, 1 / 3, sqrt(3) / 6);		glVertex3f(-sqrt(3) / 2, 0, 0.5);	//11
			glEnd();
			glPopMatrix();

			glColor3f(0, 1, 0);
			glPushMatrix();
			glTranslatef(-sqrt(3) / 2, -t / 2, 0);
			glBegin(GL_POLYGON);//POligono da Esquerda
			//glNormal3f(-1, 0, 0);
			glNormal3f(-1 / 3, -1 / 3, sqrt(3) / 6);	glVertex3f(0, 0, 0.5);		//5
			glNormal3f(-1 / 3, 1 / 3, sqrt(3) / 6);		glVertex3f(0, t, 0.5);		//11
			glNormal3f(-1 / 3, 1 / 3, -sqrt(3) / 6);	glVertex3f(0, t, -0.5);		//10
			glNormal3f(-1 / 3, -1 / 3, -sqrt(3) / 6);	glVertex3f(0, 0, -0.5);		//4
			glEnd();
			glPopMatrix();

			glColor3f(1, 0, 1);
			glPushMatrix();
			glTranslatef(sqrt(3) / 2, -t / 2, 0);
			glBegin(GL_POLYGON);//POligono da Direita
			//	glNormal3f(1, 0, 0);
			glNormal3f(0.5, -1 / 3, sqrt(3) / 6);	glVertex3f(0, 0, 0.5);		//1
			glNormal3f(0.5, 1 / 3, sqrt(3) / 6);	glVertex3f(0, t, 0.5);		//7
			glNormal3f(0.5, 1 / 3, -sqrt(3) / 6);	glVertex3f(0, t, -0.5);		//8
			glNormal3f(0.5, -1 / 3, -sqrt(3) / 6);	glVertex3f(0, 0, -0.5);		//2
			glEnd();
			glPopMatrix();

			glColor3f(1, 1, 1);
			glPushMatrix();
			glTranslatef(-sqrt(3) / 2, -t / 2, 0.5);
			glBegin(GL_POLYGON);//POligono da Esquerda Cima
			//glNormal3f(-0.5, 0, sqrt(3)/2);
			glNormal3f(-1 / 3, -1 / 3, sqrt(3) / 6);	glVertex3f(0, 0, 0);				//5
			glNormal3f(0, -1 / 3, sqrt(3) / 3);			glVertex3f(sqrt(3) / 2, 0, 0.5);		//6
			glNormal3f(0, 1 / 3, sqrt(3) / 6);			glVertex3f(sqrt(3) / 2, t, 0.5);		//12
			glNormal3f(-1 / 3, 1 / 3, sqrt(3) / 6);		glVertex3f(0, t, 0);				//11
			glEnd();
			glPopMatrix();

			glColor3f(1, 1, 0);
			glPushMatrix();
			glTranslatef(sqrt(3) / 2, -t / 2, 0.5);
			glBegin(GL_POLYGON);//POligono da Direita Cima
			//glNormal3f(0.5, 0, sqrt(3)/2);
			glNormal3f(0.5, -1 / 3, sqrt(3) / 6);	glVertex3f(0, 0, 0);				//1
			glNormal3f(0, -1 / 3, sqrt(3) / 3);		glVertex3f(-sqrt(3) / 2, 0, 0.5);		//6
			glNormal3f(0, 1 / 3, sqrt(3) / 6);		glVertex3f(-sqrt(3) / 2, t, 0.5);		//12
			glNormal3f(0.5, 1 / 3, sqrt(3) / 6);	glVertex3f(0, t, 0);				//7
			glEnd();
			glPopMatrix();


			glColor3f(1, 0, 0);
			glPushMatrix();
			glTranslatef(0, -t / 2, -1);
			glBegin(GL_POLYGON);//POligono da Esquerda Baixo
			//glNormal3f(-0.5, 0, -sqrt(3)/2);
			glNormal3f(0, -1 / 3, -sqrt(3) / 3);		glVertex3f(0, 0, 0);				//3
			glNormal3f(-1 / 3, -1 / 3, -sqrt(3) / 6);	glVertex3f(-sqrt(3) / 2, 0, 0.5);		//4
			glNormal3f(-1 / 3, 1 / 3, -sqrt(3) / 6);	glVertex3f(-sqrt(3) / 2, t, 0.5);		//10
			glNormal3f(0, 1 / 3, -sqrt(3) / 3);			glVertex3f(0, t, 0);				//9
			glEnd();
			glPopMatrix();

			glColor3f(0, 1, 1);
			glPushMatrix();
			glTranslatef(0, -t / 2, -1);
			glBegin(GL_POLYGON);//POligono da Direita Baixo
			//glNormal3f(0.5, 0, -sqrt(3)/2);
			glNormal3f(0, -1 / 3, -sqrt(3) / 3);	glVertex3f(0, 0, 0);				//3
			glNormal3f(0.5, -1 / 3, -sqrt(3) / 6);	glVertex3f(sqrt(3) / 2, 0, 0.5);		//2
			glNormal3f(0.5, 1 / 3, -sqrt(3) / 6);	glVertex3f(sqrt(3) / 2, t, 0.5);		//8
			glNormal3f(0, 1 / 3, -sqrt(3) / 3);		glVertex3f(0, t, 0);				//9
			glEnd();
			glPopMatrix();
			glPopMatrix();
		}
	};
	bool malha = false;
	if (malha){
		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		glTranslated(0, 0, 15);
		WHEELS::executeNew(6,10);
		glTranslatef(10, 10, 10);
		glutSolidCube(1);
		glPopMatrix();
		return;
		/*glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);


			glBegin(GL_POLYGON);
				glNormal3f(0, -1.0 /sqrt(2), 1.0/sqrt(2));
				glVertex3f(-4, 4, 4);
				glVertex3f(-5, 4, 3);
				glVertex3f(-5, -4, 3);
				glVertex3f(-4, -4, 4);
				
			glEnd();
			glBegin(GL_QUADS);			
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f(4.0, 4.0, 4.0);
				glVertex3f(-4.0, 4.0, 4.0);
				glVertex3f(-4.0, -4.0, 4.0);
				glVertex3f(4.0, -4.0, 4.0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0 / sqrt(2), 1.0 / sqrt(2));
				glVertex3f(4, 4, 4);
				glVertex3f(5, 4, 3);
				glVertex3f(5, -4, 3);
				glVertex3f(4, -4, 4);
			glEnd();

			glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0 / sqrt(2), 1.0 / sqrt(2));
				glVertex3f(4, 4, 4);
				glVertex3f(5, 4, 3);
				glVertex3f(5, -4, 3);
				glVertex3f(4, -4, 4);
			glEnd();




		glPopMatrix();
		return;

		*/
	}

	glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		//glPushMatrix();
		//glScalef(16, 10, 5);
		//glutWireCube(1);
		//glPopMatrix();
		if (getSpeed().getX() > 0) glRotatef(180, 0, 0, 1);
		glTranslated(2, 0, 0);
		
		glScaled(0.8, 0.8, 0.8);
		/*Cubo principal do corpo do carro*/
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

		/*Cubo da frente, onde esta o motor*/
		glPushMatrix();
			glTranslated(-8.5, 0, 0);
			glScalef(5, 4, 2);
			glutSolidCube(1);
		glPopMatrix();

		/*Eixo da roda direita da frente*/
		glPushMatrix();
			glTranslated(-10, 2.5, 0);
			glScalef(2, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		/*Eixo da roda esquerda da frente*/
		glPushMatrix();
			glTranslated(-10, -2.5, 0);
			glScalef(2, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		defineMaterial(	0.01, 0.01, 1.00, 1.00,	//Ambient
						0.01, 0.01, 1.00, 1.00,	//Diffuse
						1.00, 1.00, 1.00, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0, 0, 1);
		glPushMatrix();
		glTranslatef(-10, 4, 0);
		WHEELS::executeNew(8, 2);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-10, -4, 0);
		WHEELS::executeNew(8, 2);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1, -5, 0);
		WHEELS::executeNew(8, 2);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1, 5, 0);
		WHEELS::executeNew(8, 2);
		glPopMatrix();
		//WHEELS::execute(-10, 4, 0, 3, 1.25);
		//WHEELS::execute(-10, -4, 0, 3, 1.25);
		//WHEELS::execute(1, -5, 0, 5, 1.25);
		//WHEELS::execute(1, 5, 0, 5, 1.25);
		/*
		//Roda direita da frente
		glPushMatrix();
			glTranslated(-10, 4, 0);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 2, 16, 16);
		glPopMatrix();
		//Roda direita de tras
		glPushMatrix();
			glTranslated(1, -5, 0);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 3, 16, 16);
		glPopMatrix();
		//Roda esquerda de tras
		glPushMatrix();
			glTranslated(1, 5, 0);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 3, 16, 16);
		glPopMatrix();
		//Roda esquerda da frente
		glPushMatrix();
			glTranslated(-10, -4, 0);
			glRotated(90, 1, 0, 0);
			glutSolidTorus(1, 2, 16, 16);
		glPopMatrix();
		*/
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
