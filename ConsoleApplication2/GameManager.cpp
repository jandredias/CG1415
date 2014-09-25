#include "GameManager.h"
#include "GameObject.h"
GameManager::GameManager(){
	/* Ao iniciar o jogo e necessario criar os elementos:
		River
		Riverside
		Road
		Roadside
		TimberLog
		
	Os elementos dinamicos (carros, troncos, etc) sao criados
	no decorrer do jogo
	*/
	_game_objects.push_back(new River());
	_game_objects.push_back(new Riverside());
	_game_objects.push_back(new Road());
	_game_objects.push_back(new Roadside());
	_game_objects.push_back(new TimberLog());
	_cameras.push_back(new OrthogonalCamera());
}

GameManager::~GameManager(){
	_game_objects.erase(_game_objects.begin(), _game_objects.end());
}

void GameManager::display(){
	for each (GameObject var in _game_objects){
		var.draw();
	}
}
void GameManager::reshape(GLsizei w, GLsizei h){

}
void GameManager::keyPressed(){
	int key;
	switch (key){
	case 111: //o
		break;
	case 112: //p
		break;
	case 113: //q
		break;
	case 97: //a
		break;
	}
}
void GameManager::onTimer(){

}
void GameManager::idle(){

}
void GameManager::update(){

}
void GameManager::init(){

}