
#include "Frog.h"
#include "GameManager.h"
#include "River.h"
#include "TimberLog.h"
#include "Car.h"
#include "FrogTarget.h"
#include "LimitMap.h"
#include "Riverside.h"
#include "Roadside.h"
#include "StreetLamp.h"

#include "GL/glut.h"
#include <iostream>

extern GameManager *gm;
Frog::Frog(){
	setSize(4,5,5);
	setSpeed(0, 0, 0);
	speed_log.set(0, 0, 0);
	speeder = NULL;
}
Frog::Frog(double x, double y, double z) : Frog(){
	setPosition(x, y, z);
}
Frog::~Frog(){}
void Frog::draw(){

	
	glPushMatrix();
		//glRotated(90, 0, 0, 1);
		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);

		if (gm->getSettings().getDebug()){
			glPushMatrix();
			glScalef(getSize().getX() * 2, getSize().getY() * 2, getSize().getZ() * 2);
			glutWireCube(1);
			glPopMatrix();
		}
		glRotatef((getSpeed().getX() > 0) ? -90 : (getSpeed().getX() < 0) ? 90 : (getSpeed().getY() < 0) ? 180 : 0, 0, 0, 1);
		glTranslatef(0, 2.9, 0);
		
		defineMaterial(	0.00, 0.00, 0.00, 1.00,	//Ambient
						0.00, 0.30, 0.00, 1.00,	//Diffuse
						0.60, 0.70, 0.60, 1.00,	//Specular
						0.00, 0.00, 0.00, 1.00,	//Emission
						77);					//SHININESS
		glColor3f(0.00, 0.1725, 0.00);
		//Cubo da cabeça
		glPushMatrix();
			glTranslated(0, -1, 1);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
		glPopMatrix();

		//Cubo do corpo
		glPushMatrix();
			glTranslated(0, -5, 1);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
		glPopMatrix();

		//Cubo de parte da pata superior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(3, -1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata superior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(4, 0, 1);
			glScalef(1, 3, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo de parte da pata superior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-3, -1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata superior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-4, 0, 1);
			glScalef(1, 3, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo de parte da pata inferior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(3, -5, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata inferior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(4, -6.2, 1);
			glScalef(1, 3.6, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo de parte da pata inferior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-3, -5, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata inferior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-4, -6.2, 1);
			glScalef(1, 3.6, 1);
			glutSolidCube(1);
		glPopMatrix();
		
		defineMaterial(	0.90, 0.00, 0.00, 1.00,
						0.90, 0.00, 0.00, 1.00,
						1.00, 1.00, 1.00, 1.00,
						0.00, 0.00, 0.00, 0.00,
						13);
		glColor3f(0.90, 0.00, 0.00);
		//Olho esquerdo do sapo
		glPushMatrix();
			glTranslated(-2, 1, 3);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

		//Olho direito do sapo
		glPushMatrix();
			glTranslated(2, 1, 3);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();
	glPopMatrix();

/*	material_Ka[] = { 0.00, 0.00, 0.00, 1.00 };
	material_Kd[] = { 1.00, 1.00, 1.00, 1.00 };
	material_Ks[] = { 0.00, 0.00, 0.00, 1.00 };
	material_Ke[] = { 0.00, 0.00, 0.00, 0.00 };
	material_Se = 13;
	defineMaterial(material_Ka, material_Kd, material_Ks, material_Ke, material_Se);*/
}


void Frog::update(double delta_t){
	if (gm->getPlayers()[0]->getLifes() == 0)
		return;
	Vector3 oldPosition(getPosition().getX(), getPosition().getY(), getPosition().getZ());
	if (speeder == NULL)
		setPosition(getPosition().getX() + getSpeed().getX() * delta_t / 1000,
					getPosition().getY() + getSpeed().getY() * delta_t / 1000,
					getPosition().getZ());
	
	else
		setPosition(getPosition().getX() + (getSpeed().getX() + speeder->getSpeed().getX() * gm->getGameSpeed()) * delta_t / 1000,
					getPosition().getY() + (getSpeed().getY() + speeder->getSpeed().getY() * gm->getGameSpeed()) * delta_t / 1000,
					getPosition().getZ() + (getSpeed().getZ() + speeder->getSpeed().getZ() * gm->getGameSpeed()) * delta_t / 1000);
	
	bool ColisionLimit = false;
	bool ColisionRiver = false;
	bool ColisionRiverside = false;
	bool ColisionTimberLog = false;
	bool ColisionCar = false;
	Vector3 speedLog;
	//Verify Map Limit
	for (DynamicObject *aux : gm->getDynamicObjects())
		if (HasColision(aux))
			if (dynamic_cast<TimberLog *> (aux)){
				ColisionTimberLog = true;
				speeder = aux;
			}
			else if (dynamic_cast<Car*> (aux)) ColisionCar = true;
		

		for (StaticObject *aux : gm->getStaticObjects())
			if (HasColision(aux))
				if (dynamic_cast<FrogTarget*> (aux)){
					gm->setNewFrog(Vector3(aux->getPosition().getX(), aux->getPosition().getY() - 2.5, aux->getPosition().getZ()));
					gm->getPlayers()[0]->newRound();
					return;
				}

				else if (dynamic_cast<LimitMap *> (aux)){ //Limit Map Case

					if (aux->getPosition().getX() == 0)
						setPosition(getPosition().getX(), oldPosition.getY(), getPosition().getZ());
					if (aux->getPosition().getY() == 100)
						setPosition(oldPosition.getX(), getPosition().getY(), getPosition().getZ());
				}
				else if (dynamic_cast<StreetLamp *> (aux)) setPosition(oldPosition.getX(), oldPosition.getY(), oldPosition.getZ());
				else if (dynamic_cast<River *> (aux)) ColisionRiver = true;
				else if (dynamic_cast<Riverside *> (aux)) ColisionRiverside = true;

			if (ColisionCar || (ColisionRiver && !(ColisionRiverside || ColisionTimberLog))){
				setSpeed(0, 0, 0);
				setPosition(0, 10, -1);
				gm->getPlayers()[0]->setLifes(gm->getPlayers()[0]->getLifes() - 1);
				std::cout << "Lifes: " << std::endl;
				std::cout << gm->getPlayers()[0]->getLifes() << std::endl;
				
			}
			if (!ColisionTimberLog) speeder = NULL;
}
