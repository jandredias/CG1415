#include "stdafx.h"
#include "GameManager.h"
/* ERA INTERESSANTE SE OS MEUS COLEGAS COMECASSEM A TRABALHAR NO PROJETO TAMBEM!!!!!!!!!!!!!!!!!!!!!! */
#define Y_PRIMEIRA_LINHA_RIO 126
#define Y_PRIMEIRA_LINHA_CARRO 26

#define SPEED0	0.06
#define SPEED1	-0.07
#define SPEED2	0.05
#define SPEED3	-0.075
#define SPEED4	0.08

#define CAR_LANE_1		26
#define CAR_LANE_SIZE_Y	12
#define CAR_LANE_NO		5
#define SPEED_FROG 0.1
#define SPEED_CAR -0.036
#define TL_POS_BEGIN0	-150
#define	TL_POS_BEGIN1	 150
extern GameManager *gm;
extern int y;
extern int z;

GameManager::GameManager(){
	tempo_inicio = tempo_anterior = tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	_speed_car[0] = 0.06;
	_speed_car[1] = -0.07;
	_speed_car[2] = 0.05;
	_speed_car[3] = -0.075;
	_speed_car[4] = 0.08;

	_speed_river[0] = 0.06;
	_speed_river[1] = -0.07;
	_speed_river[2] = 0.05;
	_speed_river[3] = -0.075;
	_speed_river[4] = 0.08;
}

GameManager::~GameManager(){}
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
void GameManager::display(){
	glClearColor(1, 1, 1, 1);
	//glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera_atual->computeProjectionMatrix();
	camera_atual->update(_w, _h);
	camera_atual->computeVisualizationMatrix();
	for (GameObject *aux : getStaticObjects()) aux->draw();
	for (GameObject *aux : getDynamicObjects()) aux->draw();
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
			std::cout << camera_atual_id << std::endl;
			camera_atual = getcameras()[camera_atual_id];
			reshape(_w, _h);
			break;
		case 'f':
		case 'p': frog->setSpeed(0, frog->getSpeed().getY(), frog->getSpeed().getZ()); break;

		case 's':
		case 'o': frog->setSpeed(0, frog->getSpeed().getY(), frog->getSpeed().getZ()); break;

		case 'e':
		case 'q': frog->setSpeed(frog->getSpeed().getX(), 0, frog->getSpeed().getZ()); break;

		case 'd':
		case 'a': frog->setSpeed(frog->getSpeed().getX(), 0, frog->getSpeed().getZ()); break;
	}
}
void GameManager::keyPressed(unsigned char key){
	if (getStatus()){ frog->setSpeed(0, 0, 0); return; }
	switch (key){
	case 'f':
	case 'p': frog->setSpeed(SPEED_FROG, frog->getSpeed().getY(), frog->getSpeed().getZ()); break;

	case 's':
	case 'o': frog->setSpeed(0 - SPEED_FROG, frog->getSpeed().getY(), frog->getSpeed().getZ()); break;

	case 'e':
	case 'q': frog->setSpeed(frog->getSpeed().getX(), SPEED_FROG, frog->getSpeed().getZ()); break;

	case 'd':
	case 'a': frog->setSpeed(frog->getSpeed().getX(), 0 - SPEED_FROG, frog->getSpeed().getZ()); break;
	}
}
void GameManager::onTimer(){
	tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gm->update(tempo_atual - tempo_anterior);
	tempo_anterior = tempo_atual;
}
void GameManager::idle(){}
void GameManager::TimberLogFactory(){}
void GameManager::factory(){
	bool test_timberlog = true;
	bool test_car = true;
	int y = CAR_LANE_1;
	Car *a;
	TimberLog *b;
	for (int i = 0; i < CAR_LANE_NO; i++, y += CAR_LANE_SIZE_Y, test_timberlog = true, test_car = true){
		a = new Car(169 * pow(-1, i + 1), y, 0, getSpeedCar()[i]);
		b = new TimberLog(250 * pow(-1, i + 1), y + 100, 0, getSpeedRiver()[i]);

		for (DynamicObject *aux : getDynamicObjects()){
			if (dynamic_cast<TimberLog*> (aux) && b->HasColision(aux)) test_timberlog = false;
			if (dynamic_cast<Car*> (aux) && a->HasColision(aux)) test_car = false;
		}

		if (test_car && !(rand() % 500))
			setDynamicObject(a);
		else delete(a);

		if (test_timberlog && !(rand() % 100))
			setDynamicObject(b);
		else delete(b);
	}
}
void GameManager::update(unsigned long delta){
	//Move Dynamic Objects
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
		camera_atual->setAt(frog->getPosition().getX(), frog->getPosition().getY() - 20, frog->getPosition().getY() + 20);
	}
	factory();
	glutPostRedisplay();
}
void GameManager::init(){
	setStaticObject(new LimitMap(Vector3(100, 400, 100), Vector3(-150, 100, 0))); //LimiteEsquerdo
	setStaticObject(new LimitMap(Vector3(100, 400, 100), Vector3(150, 100, 0))); //LimiteDireito
	setStaticObject(new LimitMap(Vector3(400, 100, 100), Vector3(0, 250, 0))); //Limite Top
	setStaticObject(new LimitMap(Vector3(400, 100, 100), Vector3(0, -50, 0))); //Limite Botoom
	setStaticObject(new River(0, 150, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Road(0, 50, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Riverside(0, 110, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Riverside(0, 190, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Roadside(0, 90, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Roadside(0, 10, 0)); //Centro da face que esta em Z = 0
	setDynamicObject(frog = new Frog(0, 10, -1));
	setcameras(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	setcameras(camera_atual = new PerspectiveCamera(90, 1, 1, 400));
	setcameras(new PerspectiveCamera(90, 1, 1, 400));
}