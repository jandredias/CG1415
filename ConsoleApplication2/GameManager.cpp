#include "stdafx.h"
#include "GameManager.h"
extern GameManager *gm;
GameManager::GameManager(){}
GameManager::~GameManager(){}
void GameManager::display(){
	int i;
	GameObject *aux;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (i = 0; i < _game_objects.size(); i++)
	{
		glPushMatrix();
			glTranslated(_game_objects.front()->getPosition()->getX(), _game_objects.front()->getPosition()->getY(), _game_objects.front()->getPosition()->getZ());
			_game_objects.front()->draw();
			_game_objects.push(_game_objects.front());
			_game_objects.pop();
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
	int k = _game_objects.size();
	Frog* v = dynamic_cast<Frog*>(_game_objects.front());
	while (v == 0){
		k--;
		_game_objects.push(_game_objects.front());
		_game_objects.pop();
		v = dynamic_cast<Frog*>(_game_objects.front());
	}
	for (; k > 0; k--){
		_game_objects.push(_game_objects.front());
		_game_objects.pop();
	}
#define SPEED_FROG 0.5
	//printf("%c %d\n", key);
	if (v != 0){
		if (i == -1){ //Down
			switch (key){
			case 'p': v->setSpeed(SPEED_FROG, v->getSpeed()->getY(), v->getSpeed()->getZ()); break;
			case 'o': v->setSpeed(-SPEED_FROG, v->getSpeed()->getY(), v->getSpeed()->getZ()); break;
			case 'q': v->setSpeed(v->getSpeed()->getX(), SPEED_FROG, v->getSpeed()->getZ()); break;
			case 'a': v->setSpeed(v->getSpeed()->getX(), -SPEED_FROG, v->getSpeed()->getZ()); break;
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
	}
}
void GameManager::onTimer(){}
void GameManager::idle(){}
void GameManager::update(unsigned long delta){
	int i;
	GameObject *aux;
	for (i = 0; i < _game_objects.size(); i++){
		//std::cout << 0;
		_game_objects.front()->update(delta);
		if (_game_objects.front()->OutOfScene()){
			printf("FORA DO ECRA\n");
			DynamicObject* v = dynamic_cast<DynamicObject*>(_game_objects.front());
			if (v->getSpeed()->getX() > 0)
				_game_objects.push(new TimberLog(-150, v->getPosition()->getY(), 0, v->getSpeed()->getX()));
			_game_objects.pop();
		}else{

			_game_objects.push(_game_objects.front());
			_game_objects.pop();
		}
	}

}
void GameManager::init(){
	_cameras.push(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	
	_game_objects.push(new River(0,150,0));
	_game_objects.push(new Riverside(0, 190, 0));
	_game_objects.push(new Riverside(0,110,0));
	_game_objects.push(new Road(0, 50, 0));
	_game_objects.push(new Roadside(0, 90, 0));
	_game_objects.push(new Roadside(0, 10, 0));

	//TimberLog	/* Speed in [0.5;1] */
	_game_objects.push(new TimberLog(-150, 126, 0, 0.6));
	_game_objects.push(new TimberLog(150, 138, 0, -0.7));
	_game_objects.push(new TimberLog(-150, 150, 0, 1));
	_game_objects.push(new TimberLog(150, 162, 0, -0.8));
	_game_objects.push(new TimberLog(-150, 174, 0, 0.75));

	//Turtle

	_game_objects.push(new Frog(0, 13, 0));
}