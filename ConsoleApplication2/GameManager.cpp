#include "stdafx.h"
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
	/*_game_objects->push_back(new River());
	_game_objects->push_back(new Riverside());
	_game_objects->push_back(new Road());
	_game_objects->push_back(new Roadside());
	_game_objects->push_back(new TimberLog());
	_cameras->push_back(new OrthogonalCamera());*/
}

GameManager::~GameManager(){
	/*_game_objects->erase(_game_objects->begin(), _game_objects->end());*/
}

/*std::vector<GameObject> GameManager::getgame_objects(void){
	return _game_objects;
}
Camera* GameManager::getcameras(void){

}

LightSource* GameManager::getlight_sources(void){
	return _light_sources;
}
GameObject* GameManager::setgame_objects(GameObject*){
	return GameManager();
}
Camera* GameManager::setcameras(Camera*){

}
LightSource* GameManager::setlight_sources(LightSource*){
	return _light_sources;
}*/
void GameManager::display(){
	glClearColor(1, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (GameObject go : gm->_game_objects){
		go.draw();
	}
	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h){
	float xmin = -100.0;
	float xmax = 100;
	float ymin = -100;
	float ymax = 100;

	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
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

}