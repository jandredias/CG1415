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
	float xmin = -100;
	float xmax = 100;
	float ymin = -100;
	float ymax = 100;

	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;

	glViewport(0, 0, w, h); glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect){
		float aux = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		glOrtho(xmin - aux, xmax + aux, ymin, ymax, -4, 4);
	}
	else
	{
		float aux = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		glOrtho(xmin, xmax, ymin - aux, ymax + aux, -4, 4);
	}
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
void GameManager::onTimer(){

}
void GameManager::idle(){

}
void GameManager::update(){

}
void GameManager::init(){

	GameObject *aux = new River();
	aux->setPosition(0,50,0);
	_game_objects.push(aux);

	aux = new Riverside();
	aux->setPosition(0, 90, 0);
	_game_objects.push(aux);

	aux = new Riverside();
	aux->setPosition(0, 10, 0);
	_game_objects.push(aux);

	aux = new Road();
	aux->setPosition(0, -50, 0);
	_game_objects.push(aux);
	aux = new Roadside();
	aux->setPosition(0, -10, 0);
	_game_objects.push(aux);
	aux = new Roadside();
	aux->setPosition(0, -90, 0);
	_game_objects.push(aux);
}