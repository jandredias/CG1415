#include "GameManager.h"
#include "LimitMap.h"
#include "Frog.h"
#include "FrogTarget.h"
#include "Background.h"
#include "Road.h"
#include "Roadside.h"
#include "River.h"
#include "Riverside.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "TimberLog.h"
#include "Car.h"
#include "Tunnel.h"
#include "StreetLamp.h"
#include "Bus.h"
#include <iostream>
#include <cmath>

//blah blah blah wiskas saketas

extern GameManager *gm;
extern int y;
extern int z;


GameManager::GameManager(){}
GameManager::~GameManager(){
	for (GameObject *aux : getDynamicObjects()) delete(aux);
	for (GameObject *aux : getStaticObjects()) delete(aux);
	for (GameObject *aux : getFrogs()) delete(aux);
	for (Camera *aux : getcameras()) delete(aux);
	for (Player *aux : getPlayers()) delete(aux);
}

double GameManager::getGameSpeed(){ return _speed; }
std::list<DynamicObject *> GameManager::getDynamicObjects(void){ return _dynamic_game_objects; }
void GameManager::setDynamicObject(DynamicObject* aux){ _dynamic_game_objects.push_back(aux); }
std::list<StaticObject *> GameManager::getStaticObjects(void){ return _static_game_objects; }
void GameManager::setStaticObject(StaticObject* aux){ _static_game_objects.push_back(aux); }
std::vector<Camera *> GameManager::getcameras(void){ return _cameras; }
std::vector<Camera *> GameManager::setcameras(Camera* aux){ _cameras.push_back(aux); return _cameras; }
const double* GameManager::getSpeedCar(){ return _speed_car; }
const double* GameManager::getSpeedRiver(){ return _speed_river; }
void GameManager::changeStatus(bool a){ _status = a; }
bool GameManager::getStatus(){ return _status; }
Frog* GameManager::getFrog(){ return _players[0]->getFrog(); }
void GameManager::setNewFrog(Vector3 a){ list_frogs.push_back(new Frog(a.getX(), a.getY(), a.getZ())); }
std::list<Frog*> GameManager::getFrogs(){ return list_frogs; }


std::vector<LightSource *> GameManager::getlights(void){ return _lights; }
LightSource* GameManager::getLight(int i){	return _lights[i]; }
std::vector<LightSource *> GameManager::setlights(LightSource* aux){ _lights.push_back(aux); return _lights; }
void GameManager::SetStreetLamps(bool state){ for (int i = 1; i < getlights().size(); i++) getlights()[i]->setState(state); }

void GameManager::setPlayer(Player *a){ _players.push_back(a); }
std::vector<Player *> GameManager::getPlayers(){ return _players; }

class NewCar{
	public: static void execute(int i) {
		DynamicObject *a = NULL;

		bool test_car = true;
		do{
			delete(a);
			int i = rand() % 5;
			a = new Car(0, i * CAR_LANE_SIZE_Y + CAR_LANE_1, 0, gm->getSpeedCar()[i]);
			a->setPosition((200 + a->getSize().getX() / 2)* pow(-1, i + 1), i * CAR_LANE_SIZE_Y + CAR_LANE_1, 0);
			for (DynamicObject *aux : gm->getDynamicObjects())
				if (dynamic_cast<Car*> (aux) && a->HasColision(aux)) test_car = false;

		} while (!test_car);
		gm->setDynamicObject(a);
		glutTimerFunc(rand() % 5000 + 500, NewCar::execute, 1);
	}
};
class NewTimberLog{
	public: static void execute(int i) {
		DynamicObject *a = NULL;
		bool test = true;
		do{
			delete(a);
			int i = rand() % 5;
			a = new TimberLog(0, i * CAR_LANE_SIZE_Y + 100 + CAR_LANE_1, 0, gm->getSpeedRiver()[i]);
			a->setPosition((200 + a->getSize().getX()/2)* pow(-1, i + 1), i * CAR_LANE_SIZE_Y + 100 + CAR_LANE_1, 0);
			for (DynamicObject *aux : gm->getDynamicObjects())
				if (dynamic_cast<Car*> (aux) && a->HasColision(aux)) test = false;

		} while (!test);
		gm->setDynamicObject(a);
		glutTimerFunc(rand() % 1000 + 200, NewTimberLog::execute, 1);
	}
};
void GameManager::init(){
	std::string text;
	text = "########### FROGGER###########\n";
	text += "1 Jogador\n";
	text += "\n\n\n CONTROLOS: \n";
	text += "Cima: Q\n";
	text += "Baixo: A\n";
	text += "Esquerda: O\n";
	text += "Direita: P\n";
	text += "Cima: Q\n";

	text += "Alterar Modo Dia e Noite: N\n";
	text += "Ligar e Desligar Candeeiros de Rua: C\n";
	text += "Ativar/Desativar Luzes: L\n";
	std::cout << text.c_str() << std::endl;

	_size_map.set(200, 200, 0);
	_center_map.set(0, 100, 0);

	tempo_inicio = tempo_anterior = tempo_atual = glutGet(GLUT_ELAPSED_TIME);

	_speed_car[0] = _size_map.getX() / (rand() % 5 + 3);
	_speed_car[1] = -_size_map.getX() / (rand() % 5 + 3);
	_speed_car[2] = _size_map.getX() / (rand() % 5 + 3);
	_speed_car[3] = -_size_map.getX() / (rand() % 5 + 3);
	_speed_car[4] = _size_map.getX() / (rand() % 5 + 3);

	_speed_river[0] = _size_map.getX() / (rand() % 5 + 3);
	_speed_river[1] = -_size_map.getX() / (rand() % 5 + 3);
	_speed_river[2] = _size_map.getX() / (rand() % 5 + 3);
	_speed_river[3] = -_size_map.getX() / (rand() % 5 + 3);
	_speed_river[4] = _size_map.getX() / (rand() % 5 + 3);

	setStaticObject(new Background(0, 0, 0));

	setStaticObject(new FrogTarget(-80, 190, 0));
	setStaticObject(new FrogTarget(-40, 190, 0));
	setStaticObject(new FrogTarget(0, 190, 0));
	setStaticObject(new FrogTarget(40, 190, 0));
	setStaticObject(new FrogTarget(80, 190, 0));
	
	setStaticObject(new LimitMap(Vector3(100, 400, 100), Vector3(-150, 100, 0))); //LimiteEsquerdo
	setStaticObject(new LimitMap(Vector3(100, 400, 100), Vector3(150, 100, 0))); //LimiteDireito
	setStaticObject(new LimitMap(Vector3(400, 100, 100), Vector3(0, 250, 0))); //Limite Top
	setStaticObject(new LimitMap(Vector3(400, 100, 100), Vector3(0, -50, 0))); //Limite Bottom
	
	setStaticObject(new River(0, 150, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Road(0, 50, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Riverside(0, 110, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Riverside(0, 190, 0)); //Centro da face que esta em Z = 0
	
	setStaticObject(new Roadside(0, 90, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Roadside(0, 10, 0)); //Centro da face que esta em Z = 0
	
	setStaticObject(new Tunnel(_size_map.getX() / 2, 50, 0)); //(largura da estrada, ponto medio Y da estrada, z = 0)
	setStaticObject(new Tunnel(_size_map.getX() / 2, 150, 0)); //(largura da estrada, ponto medio Y da estrada, z = 0)
	switch (_no_players){
	case 1:
		setPlayer(new Player('a', 'q', 'o', 'p'));
		break;
	case 2:
		setPlayer(new Player('s', 'w', 'a', 'd'));
		setPlayer(new Player('g', 't', 'f', 'h'));
	}
	
	LightSource *aux = new LightSource(getlights().size());
		aux->setPosition(-1,1,1, 0); //O SOL esta' a esquerda
		aux->setDirection(0, 0, 0);
		aux->setSpecular(1.0, 1.0, 1.0, 1.0);
		aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
		aux->setAmbient(0.2, 0.2, 0.2, 1.0);
		aux->setExponent(2);
		aux->setState(true);
		//aux->draw();
		setlights(aux);

	for(int y = 0; y <= 200; y+=100)
		for(int x = -100; x <= 100; x += 200){//Vector3(1, (y == 0) ? 1 : -1 , 1)
			setStaticObject(new StreetLamp(Vector3(x, y, 0), Vector3((x > 0) ? 1 : -1,1,1)));

			aux = new LightSource(getlights().size());
			aux->setPosition(x, y, 20, 1);
			aux->setDirection((x < 0) ? 0.5 : -0.5, 0, -1);
			aux->setSpecular(0.2, 0.2, 0.2, 1.0);
			aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
			aux->setAmbient(0.2, 0.2, 0.2, 1.0);
			aux->setExponent(2);
			aux->setState(_lights_on);
			setlights(aux);
		}

	if (_lights_active)	glEnable(GL_LIGHTING);
	else glDisable(GL_LIGHTING);
	
	setcameras(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	setcameras(camera_atual = new PerspectiveCamera(90, 1, 1, 400));
	setcameras(new PerspectiveCamera(90, 1, 1, 400));

	class Nivel{
	public:
		static void improve_level(int i){
			gm->_speed *= 1.1;
			glutTimerFunc(LEVEL_TIME_IN_SECONDS * 1000, improve_level, 1);
		}
	};
	//class Night{
	//public:
	//	static void execute(int i){
	//		gm->getLight(0)->setState(gm->_modo_dia = !gm->_modo_dia);
	//		glutTimerFunc(50000, Night::execute, 1);
	//	}
	//};
	//Night::execute(1);
	Nivel::improve_level(1);
	NewCar::execute(1);
	NewTimberLog::execute(1);	
}

void GameManager::display(){
	glClearColor(0, 45/255, 128/255, 1);
//	glClearColor(0,0,0,1);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera_atual->computeProjectionMatrix();
	camera_atual->update(_w, _h);
	camera_atual->computeVisualizationMatrix();
	for (LightSource *aux : getlights()) aux->draw();
	
	for (GameObject *aux : getStaticObjects()) aux->draw();
	for (GameObject *aux : getDynamicObjects()) aux->draw();
	for (GameObject *aux : getFrogs()) aux->draw();

	glutSwapBuffers();
	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	_w = w;
	_h = h;
}

void GameManager::keyUp(unsigned char key){
	switch (key){
	case '1':
	case '2':
	case '3':
		camera_atual_id = key - '1';
		camera_atual = getcameras()[camera_atual_id];
		return;
	case 27:
		exit(0);
		break;
	case 'n':
		getLight(0)->setState(_modo_dia = !_modo_dia);
		break;
	case 'l':
		if ((_lights_active =! _lights_active)) glEnable(GL_LIGHTING);
		else glDisable(GL_LIGHTING);
		break;
	case 'c':
		SetStreetLamps(_lights_on = !_lights_on);
		break;
	default:
		for (Player *aux : getPlayers())
			if (aux->getKeys().count(key))
				aux->getFrog()->setSpeed((aux->getKeys()[key].getX()) ? 0 : aux->getFrog()->getSpeed().getX(),
				(aux->getKeys()[key].getY()) ? 0 : aux->getFrog()->getSpeed().getY(),
				(aux->getKeys()[key].getZ()) ? 0 : aux->getFrog()->getSpeed().getZ());
	}
}
void GameManager::keyPressed(unsigned char key){
	for (Player *aux : getPlayers())
		if (aux->getKeys().count(key)) 
			aux->getFrog()->setSpeed(	(aux->getKeys()[key].getX()) ? aux->getKeys()[key].getX() * SPEED_FROG : aux->getFrog()->getSpeed().getX(),
										(aux->getKeys()[key].getY()) ? aux->getKeys()[key].getY() * SPEED_FROG : aux->getFrog()->getSpeed().getY(),
										(aux->getKeys()[key].getZ()) ? aux->getKeys()[key].getZ() * SPEED_FROG : aux->getFrog()->getSpeed().getZ());
}
void GameManager::onTimer(){
	tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gm->update(tempo_atual - tempo_anterior);
	std::cout << tempo_atual - tempo_anterior << std::endl;
	tempo_anterior = tempo_atual;
}
void GameManager::idle(){}



void GameManager::update(unsigned long delta){
	double initial = 0;
	for (DynamicObject *aux : getDynamicObjects()){
		aux->update(delta);
		(aux > 0) ? 1 : -1;
		if (((aux->getSpeed().getX() > 0) ? 1 : -1) * (aux->getPosition().getX()) > 400){
			delete(aux);
			_dynamic_game_objects.remove(aux);
			continue;
		}
	}
	if (camera_atual_id == 2){
		camera_atual->setAt(getFrog()->getPosition().getX(), getFrog()->getPosition().getY() - 20, getFrog()->getPosition().getZ() + 20);
		camera_atual->setUp(0, 2, 5);
	}
	glutPostRedisplay();

}
