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
		_game_objects.front()->draw();
		_game_objects.push(_game_objects.front());
		_game_objects.pop();
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
	//INIT CAMERA
	//Camera *camera = new OrthogonalCamera(-100,100,-100,100,-100,100);
	//_cameras.push(camera);
	_cameras.push(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));


	GameObject *aux = new River();
	aux->setPosition(0,150,0);
	_game_objects.push(aux);

	aux = new Riverside();
	aux->setPosition(0, 190, 0);
	_game_objects.push(aux);

	aux = new Riverside();
	aux->setPosition(0, 110, 0);
	_game_objects.push(aux);

	aux = new Road();
	aux->setPosition(0, 50, 0);
	_game_objects.push(aux);
	aux = new Roadside();
	aux->setPosition(0, 90, 0);
	_game_objects.push(aux);
	aux = new Roadside();
	aux->setPosition(0, 10, 0);
	_game_objects.push(aux);

	aux = new Frog();
	aux->setPosition(0, 13, 0);
	_game_objects.push(aux);
}