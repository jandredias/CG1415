#include "GameManager.h"
#include "Header.h"
#define LEVEL_TIME_IN_SECONDS		10
#define CAR_LANE_1					26
#define CAR_LANE_SIZE_Y				12
#define CAR_LANE_NO					5
#define SPEED_FROG					40
#define TL_POS_BEGIN0				-150
#define	TL_POS_BEGIN1				150

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

void GameManager::setPlayer(Player *a){ _players.push_back(a); }
std::vector<Player *> GameManager::getPlayers(){ return _players; }

void GameManager::init(){
	_size_map.set(200,200,0);
	_center_map.set(0, 100, 0);
	
	delete(frog);
	//blah blah blah
	tempo_inicio = tempo_anterior = tempo_atual = glutGet(GLUT_ELAPSED_TIME);

	_speed_car[0] =    _size_map.getX() / (rand() % 5 + 3);
	_speed_car[1] = -  _size_map.getX() / (rand() % 5 + 3);
	_speed_car[2] =    _size_map.getX() / (rand() % 5 + 3);
	_speed_car[3] = -  _size_map.getX() / (rand() % 5 + 3);
	_speed_car[4] =    _size_map.getX() / (rand() % 5 + 3);

	_speed_river[0] =  _size_map.getX() / (rand() % 5 + 3);
	_speed_river[1] =- _size_map.getX() / (rand() % 5 + 3);
	_speed_river[2] =  _size_map.getX() / (rand() % 5 + 3);
	_speed_river[3] =- _size_map.getX() / (rand() % 5 + 3);
	_speed_river[4] =  _size_map.getX() / (rand() % 5 + 3);
	
	setStaticObject(new Background(0, 100, 0));

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
	
	switch (_no_players){
		case 1:
			setPlayer(new Player('a', 'q', 'o', 'p'));
			break;
		case 2:
			setPlayer(new Player('s', 'w', 'a', 'd'));
			setPlayer(new Player('k', 'i', 'j', 'l'));
	}
	

	setcameras(new OrthogonalCamera(-100, 100, 0, 200, -100, 100));
	setcameras(camera_atual = new PerspectiveCamera(90, 1, 1, 400));
	setcameras(new PerspectiveCamera(90, 1, 1, 400));

	//Improve level every LEVEL_TIME seconds;
	class Nivel{
	public:
		static void improve_level(int i){
			gm->_speed *= 1.1;
			glutTimerFunc(LEVEL_TIME_IN_SECONDS * 1000, improve_level, 1);
		}
	};
	glutTimerFunc(LEVEL_TIME_IN_SECONDS * 1000, Nivel::improve_level, 1);
}

void GameManager::display(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//write_info();
	camera_atual->computeProjectionMatrix();
	camera_atual->update(_w, _h);
	camera_atual->computeVisualizationMatrix();
	
	for (GameObject *aux : getStaticObjects()) aux->draw();
	for (GameObject *aux : getDynamicObjects()) aux->draw();
	for (GameObject *aux : getFrogs()) aux->draw();
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
void GameManager::write_info(){
	glPushMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera_atual->update(_w,_h);

	glTranslatef(1 - 0.255 / 2, 1 - 0.255 / 2, -1);
	glColor3f(0, 0, 0.8);
	glutSolidCube(0.25);
	output(-0.25, -0.25, 1, 0, 0, 1, "FROGGER INFO");
	glPopMatrix();

}
void GameManager::output(int x, int y, float r, float g, float b, int font, char *string)
{
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
	}
}
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
	factory();
	glutPostRedisplay();
}