#include "GameManager.h"
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
	this->_game_objects.push_back(new River());
	this->_game_objects.push_back(new Riverside());
	this->_game_objects.push_back(new Road());
	this->_game_objects.push_back(new Roadside());
	this->_game_objects.push_back(new TimberLog());
	this->_cameras.push_back(new OrthogonalCamera());
}

GameManager::~GameManager(){
	this->_game_objects.erase(this->_game_objects.begin(), this->_game_objects.end());
}

void GameManager::display(){

}
void GameManager::reshape(GLsizei w, GLsizei h){

}
void GameManager::keyPressed(){

}
void GameManager::onTimer(){

}
void GameManager::idle(){

}
void GameManager::update(){

}
void GameManager::init(){

}