#include "stdafx.h"
#include "GameManager.h"
#define Y_PRIMEIRA_LINHA_RIO 126
#define SPEED0	0.6
#define SPEED1	-0.7
#define SPEED2	0.5
#define SPEED3	-0.75
#define SPEED4	0.8


#define SPEED_FROG 0.1
#define SPEED_CAR -1
#define TL_POS_BEGIN0	-150
#define	TL_POS_BEGIN1	 150
extern GameManager *gm;
extern int y;
extern int z;

GameManager::GameManager(){	tempo_inicio = tempo_anterior = tempo_atual = glutGet(GLUT_ELAPSED_TIME);}
GameManager::~GameManager(){}
std::list<GameObject *> GameManager::getDynamicObjects(void){ return _dynamic_game_objects; }
void GameManager::setDynamicObject(GameObject* aux){ _dynamic_game_objects.push_back(aux); }
std::list<GameObject *> GameManager::getStaticObjects(void){ return _static_game_objects; }
void GameManager::setStaticObject(GameObject* aux){ _static_game_objects.push_back(aux); }
std::list<Camera *> GameManager::getcameras(void){ return _cameras; }
std::list<Camera *> GameManager::setcameras(Camera* aux){ _cameras.push_back(aux); return _cameras; }
void GameManager::display(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	for (GameObject *aux : getStaticObjects()) aux->draw();
	for (GameObject *aux : getDynamicObjects()) aux->draw();
	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	camera_atual->computeProjectionMatrix();
	camera_atual->computeVisualizationMatrix();
	camera_atual->update(w, h);
}
void GameManager::keyUp(unsigned char key){
	switch (key){
	case '6':
	case 'f':
	case 'p': frog->setSpeed(0, frog->getSpeed()->getY(), frog->getSpeed()->getZ()); break;

	case '4':
	case 's':
	case 'o': frog->setSpeed(0, frog->getSpeed()->getY(), frog->getSpeed()->getZ()); break;

	case '8':
	case 'e':
	case 'q': frog->setSpeed(frog->getSpeed()->getX(), 0, frog->getSpeed()->getZ()); break;

	case '2':
	case 'd':
	case 'a': frog->setSpeed(frog->getSpeed()->getX(), 0, frog->getSpeed()->getZ()); break;
	}
}
void GameManager::keyPressed(unsigned char key){
	switch (key){
	case '6':
	case 'f':
	case 'p': frog->setSpeed(SPEED_FROG, frog->getSpeed()->getY(), frog->getSpeed()->getZ()); break;

	case '4':
	case 's':
	case 'o': frog->setSpeed(0 - SPEED_FROG, frog->getSpeed()->getY(), frog->getSpeed()->getZ()); break;

	case '8':
	case 'e':
	case 'q': frog->setSpeed(frog->getSpeed()->getX(), SPEED_FROG, frog->getSpeed()->getZ()); break;

	case '2':
	case 'd':
	case 'a': frog->setSpeed(frog->getSpeed()->getX(), 0 - SPEED_FROG, frog->getSpeed()->getZ()); break;
	}
}
void GameManager::onTimer(){
	tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gm->update(tempo_atual - tempo_anterior);
	std::cout << tempo_atual - tempo_anterior << "\n";
	tempo_anterior = tempo_atual;
}
void GameManager::idle(){}
void GameManager::update(unsigned long delta){
	/*Steps:
	1. Mover Objectos
	2. Verificar se e necessario apanhar objects
	3. Verificar se e necessario gerar novos objects
	*/
	//Move Dynamic Objects
	for (int i = 0; i < _dynamic_game_objects.size(); i++){
		_dynamic_game_objects.front()->update(delta);
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	glutPostRedisplay();
}
void GameManager::init(){
	setcameras(camera_atual = new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	setcameras(new PerspectiveCamera(90, 5, 0, 200));
	setStaticObject(new River(0, 150, 0));
	setStaticObject(new Riverside(0, 190, 0));
	setStaticObject(new Riverside(0, 110, 0));
	setStaticObject(new Road(0, 50, 0));
	setStaticObject(new Roadside(0, 90, 0));
	setStaticObject(new Roadside(0, 10, 0));

	setDynamicObject(new TimberLog(0, Y_PRIMEIRA_LINHA_RIO + 12 * 0, 0, 0));
	setDynamicObject(new TimberLog(0, Y_PRIMEIRA_LINHA_RIO + 12 * 4, 0));

	setDynamicObject(new Car(0, 50, 0, 0));


	setDynamicObject(frog = new Frog(0, 13, 3));

	/*setDynamicObject(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 0, 0, SPEED0));
	setDynamicObject(new TimberLog(150, Y_PRIMEIRA_LINHA_RIO + 12 * 1, 0, SPEED1));
	setDynamicObject(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 2, 0, SPEED2));
	setDynamicObject(new TimberLog(0, Y_PRIMEIRA_LINHA_RIO + 12 * 2, 0, SPEED2));
	setDynamicObject(new TimberLog(150, Y_PRIMEIRA_LINHA_RIO + 12 * 3, 0, SPEED3));
	setDynamicObject(new TimberLog(-150, Y_PRIMEIRA_LINHA_RIO + 12 * 4, 0, SPEED4));
	setDynamicObject(new Car(200, 50, 0, SPEED_CAR));*/


}