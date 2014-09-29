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
		//std::cout << 0;
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
void GameManager::keyPressed(){
	/*int key;
	switch (key){
	case 111: //o
		break;
	case 112: //p
		break;
	case 113: //q
		break;
	case 97: //a
		break;
	}*/
}
void GameManager::onTimer(){}
void GameManager::idle(){}
void GameManager::update(){}
void GameManager::init(){
	_cameras.push(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	_game_objects.push(new River(0,150,0));
	_game_objects.push(new Riverside(0, 190, 0));
	_game_objects.push(new Riverside(0,110,0));
	_game_objects.push(new Road(0, 50, 0));
	_game_objects.push(new Roadside(0, 90, 0));
	_game_objects.push(new Roadside(0, 10, 0));


	_game_objects.push(new Frog(0, 13, 0));
	

	//TimberLog
	_game_objects.push(new TimberLog(-100, 126, 0));
	_game_objects.push(new TimberLog(-100, 138, 0));
	_game_objects.push(new TimberLog(-100, 150, 0));
	_game_objects.push(new TimberLog(-100, 162, 0));
	_game_objects.push(new TimberLog(-100, 174, 0));

	//Turtle
	_game_objects.push(new Turtle(-50, 126, 0));
	_game_objects.push(new Turtle(-50, 138, 0));
	_game_objects.push(new Turtle(-50, 150, 0));
	_game_objects.push(new Turtle(-50, 162, 0));
	_game_objects.push(new Turtle(-50, 174, 0));
}