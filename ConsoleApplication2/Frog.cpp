
#include <iostream>
#include "Frog.h"
#include "GameManager.h"
#include "gl/glut.h"

extern GameManager *gm;
Frog::Frog(){
	setSpeed(0, 0, 0);
	speed_log.set(0, 0, 0);
}
void Frog::update(double delta_t){
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
					/* The frog might be moving on x and y axis at the same time,
					 * so we have to check if the colision is on X axis or/and Y axis
					 */
					if (aux->getPosition().getX() == 0)
						setPosition(getPosition().getX(), oldPosition.getY(), getPosition().getZ());
					if (aux->getPosition().getY() == 100)
						setPosition(oldPosition.getX(), getPosition().getY(), getPosition().getZ());
				}
				else if (dynamic_cast<River *> (aux)) ColisionRiver = true;
				else if (dynamic_cast<Riverside *> (aux)) ColisionRiverside = true;

			if (ColisionCar || (ColisionRiver && !(ColisionRiverside || ColisionTimberLog))){
				setSpeed(0, 0, 0);
				setPosition(0, 10, -1);
			}
			if (!ColisionTimberLog) speeder = NULL;
}
Frog::Frog(double x, double y, double z) : Frog(){
	setPosition(x, y, z);
	setSize(10, 10, 5);
}
Frog::~Frog(){}
void Frog::draw(){
	glPushMatrix();
		glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ() + getSize().getZ() / 2);
		glTranslatef(0, 2.9, 0);
		
		//Cubo da cabeça
		glPushMatrix();
			glTranslated(0, -1, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
		glPopMatrix();

		//Cubo do corpo
		glPushMatrix();
			glTranslated(0, -5, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 0.8, 1);
			glutSolidCube(5);
		glPopMatrix();

		//Cubo de parte da pata superior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(3, -1, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata superior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(4, 0, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo de parte da pata superior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-3, -1, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata superior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-4, 0, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo de parte da pata inferior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(3, -5, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata inferior direita que está encostada ao corpo
		glPushMatrix();
			glTranslated(4, -6.2, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3.6, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo de parte da pata inferior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-3, -5, 0);
			glColor3f(0, 1, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Cubo do resto da pata inferior esquerda que está encostada ao corpo
		glPushMatrix();
			glTranslated(-4, -6.2, 1);
			glColor3f(0, 1, 0);
			glScalef(1, 3.6, 1);
			glutSolidCube(1);
		glPopMatrix();

		//Olho esquerdo do sapo
		glPushMatrix();
			glTranslated(-2, 1, 0);
			glColor3f(1, 0, 0);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

		//Olho direito do sapo
		glPushMatrix();
			glTranslated(2, 1, 0);
			glColor3f(1, 0, 0);
			glutSolidSphere(1, 8, 8);
		glPopMatrix();

	glPopMatrix();
}
