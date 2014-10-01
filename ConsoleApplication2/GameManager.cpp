#include "stdafx.h"
#include "GameManager.h"
#define Y_PRIMEIRA_LINHA_RIO 126
#define SPEED0	0.6
#define SPEED1	-0.7
#define SPEED2	0.5
#define SPEED3	-0.75
#define SPEED4	0.8

#define TL_POS_BEGIN0	-150
#define	TL_POS_BEGIN1	 150
extern GameManager *gm;
GameManager::GameManager(){}
GameManager::~GameManager(){}
std::list<GameObject *> GameManager::getDynamicObjects(void){
	return _dynamic_game_objects;
}
void GameManager::setDynamicObject(GameObject* aux){
	_dynamic_game_objects.push_back(aux);
}

std::list<GameObject *> GameManager::getStaticObjects(void){
	return _static_game_objects;
}
void GameManager::setStaticObject(GameObject* aux){
	_static_game_objects.push_back(aux);
}

std::list<Camera *> GameManager::getcameras(void){ return _cameras; }
std::list<Camera *> GameManager::setcameras(Camera* aux){ _cameras.push_back(aux); return _cameras; }
void GameManager::display(){
	GameObject *aux;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Draw Static Objects
	for (int i = 0; i < _static_game_objects.size(); i++){
		glPushMatrix();
			glTranslated(_static_game_objects.front()->getPosition()->getX(), _static_game_objects.front()->getPosition()->getY(), _static_game_objects.front()->getPosition()->getZ());
			_static_game_objects.front()->draw();
			_static_game_objects.push_back(_static_game_objects.front());
			_static_game_objects.pop_front();
		glPopMatrix();
	}
	//Draw Dynamic Objects
	for (int i = 0; i < _dynamic_game_objects.size(); i++){
		glPushMatrix();
			glTranslated(_dynamic_game_objects.front()->getPosition()->getX(), _dynamic_game_objects.front()->getPosition()->getY(), _dynamic_game_objects.front()->getPosition()->getZ());
			_dynamic_game_objects.front()->draw();
			_dynamic_game_objects.push_back(_dynamic_game_objects.front());
			_dynamic_game_objects.pop_front();
		glPopMatrix();
	}
	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	_cameras.front()->computeProjectionMatrix();
	_cameras.front()->computeVisualizationMatrix();
	_cameras.front()->update(w, h);
}
void GameManager::keyPressed(unsigned char key, int i){
	/*
	int k = _dynamic_game_objects.size();
	Frog* v = dynamic_cast<Frog*>(_dynamic_game_objects.front());
	while (v == 0){
		k--;
		_dynamic_game_objects.push_front(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
		v = dynamic_cast<Frog*>(_dynamic_game_objects.front());
	}
	for (; k > 0; k--){
		_dynamic_game_objects.push_front(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	#define SPEED_FROG 0.5
	//printf("%c %d\n", key);
	if (v != 0){
		if (i == -1){ //Down
			switch (key){
			case 'p': v->setSpeed(SPEED_FROG, v->getSpeed()->getY(), v->getSpeed()->getZ()); break;
			case 'o': v->setSpeed(0-SPEED_FROG, v->getSpeed()->getY(), v->getSpeed()->getZ()); break;
			case 'q': v->setSpeed(v->getSpeed()->getX(), SPEED_FROG, v->getSpeed()->getZ()); break;
			case 'a': v->setSpeed(v->getSpeed()->getX(), 0-SPEED_FROG, v->getSpeed()->getZ()); break;
			}
		}
		else{ //Up
			switch (key){
			case 'p': v->setSpeed(0, v->getSpeed()->getY(), v->getSpeed()->getZ()); break;
			case 'o': v->setSpeed(0, v->getSpeed()->getY(), v->getSpeed()->getZ()); break;
			case 'q': v->setSpeed(v->getSpeed()->getX(), 0, v->getSpeed()->getZ()); break;
			case 'a': v->setSpeed(v->getSpeed()->getX(), 0, v->getSpeed()->getZ()); break;
			}
		}
	}*/
}
void GameManager::onTimer(){}
void GameManager::idle(){}
void GameManager::update(unsigned long delta){
	/*Steps:
		1. Mover Objectos
		2. Verificar se e necessario apanhar objects
		3. Verificar se e necessario gerar novos objects
	*/
	//Move Dynamic Objects
	for(int i = 0; i < _dynamic_game_objects.size(); i++){
		_dynamic_game_objects.front()->update(delta);
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	//Remove outside objects
	/*for (i = 0; i < _dynamic_game_objects.size(); i++){
		//if (_game_objects.front()->OutOfScene){
			//_game_objects.pop();//shared_ptr make_shared
		//}
	}*/
	//Gera novos objectos
	/*if (_create_timberlog > -1){
		switch (_create_timberlog){
			case 0: setgame_objects(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 0, 0, SPEED0));
			case 1: setgame_objects(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 1, 0, SPEED1));
			case 2: setgame_objects(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 2, 0, SPEED2));
			case 3: setgame_objects(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 3, 0, SPEED3));
			case 4: setgame_objects(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 4, 0, SPEED4));
		}
	}*/
}

void GameManager::init(){
	_cameras.push_back(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	
	setStaticObject(new River(0, 150, 0));
	setStaticObject(new Riverside(0, 190, 0));
	setStaticObject(new Riverside(0, 110, 0));
	setStaticObject(new Road(0, 50, 0));
	setStaticObject(new Roadside(0, 90, 0));
	setStaticObject(new Roadside(0, 10, 0));

	setDynamicObject(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 0, 0, SPEED0));
	setDynamicObject(new TimberLog(150, Y_PRIMEIRA_LINHA_RIO + 12 * 1, 0, SPEED1));
	setDynamicObject(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 2, 0, SPEED2));
	setDynamicObject(new TimberLog(150, Y_PRIMEIRA_LINHA_RIO + 12 * 3, 0, SPEED3));
	setDynamicObject(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 4, 0, SPEED4));

	setDynamicObject(new Frog(0, 13, 0));

	setDynamicObject(new Car(0, 50, 0));
}