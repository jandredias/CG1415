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
#include "Texture.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdio.h>

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
void GameManager::SetStreetLamps(bool state){ for (size_t i = 2; i < getlights().size(); i++) getlights()[i]->setState(state); }

void GameManager::setPlayer(Player *a){ _players.push_back(a); }
std::vector<Player *> GameManager::getPlayers(){ return _players; }
Player* GameManager::getPlayer(int a){return _players[0]; }


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
	_TexturePause = Texture::loadBMP_custom("Pause.bmp");
	_TextureGameOver = Texture::loadBMP_custom("GameOver.bmp");

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
	text += "\n";
	text += "Aumentar Resolução: +\n";
	text += "Diminuir Resolução: -\n";
	text += "Ativar Modo de Teste: d\n";
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

	setStaticObject(new Background(0, 100, 0));
	setStaticObject(new River(0, 150, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new FrogTarget(-80, 190, 0));
	setStaticObject(new FrogTarget(-40, 190, 0));
	setStaticObject(new FrogTarget(0, 190, 0));
	setStaticObject(new FrogTarget(40, 190, 0));
	setStaticObject(new FrogTarget(80, 190, 0));
	
	setStaticObject(new LimitMap(Vector3(100, 400, 100), Vector3(-150, 100, 0))); //LimiteEsquerdo
	setStaticObject(new LimitMap(Vector3(100, 400, 100), Vector3(150, 100, 0))); //LimiteDireito
	setStaticObject(new LimitMap(Vector3(400, 100, 100), Vector3(0, 250, 0))); //Limite Top
	setStaticObject(new LimitMap(Vector3(400, 100, 100), Vector3(0, -50, 0))); //Limite Bottom
	
	
	setStaticObject(new Road(0, 50, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Riverside(0, 110, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Riverside(0, 190, 0)); //Centro da face que esta em Z = 0
	
	setStaticObject(new Roadside(0, 90, 0)); //Centro da face que esta em Z = 0
	setStaticObject(new Roadside(0, 10, 0)); //Centro da face que esta em Z = 0
	
	setStaticObject(new Tunnel(_size_map.getX() / 2, 50, 0)); //(largura da estrada, ponto medio Y da estrada, z = 0)
	setStaticObject(new Tunnel(_size_map.getX() / 2, 150, 0)); //(largura da estrada, ponto medio Y da estrada, z = 0)
	
	/*
	Cada fonte de luz tem de ser criada em separado, isto e cada candeeiro tem de ser uma fonte de luz
	*/
	setPlayer(new Player('a', 'q', 'o', 'p'));

	LightSource *aux = new LightSource(getlights().size());
		aux->setPosition(-1,-1,1, 0); //O SOL esta' a esquerda
		aux->setDirection(0, 0, 0);
		aux->setSpecular(1.0, 1.0, 1.0, 1.0);
		aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
		aux->setAmbient(0.2, 0.2, 0.2, 1.0);
		aux->setState(true);
		setlights(aux);
	
	//Luz que acompanha o sapo
	aux = new LightSource(getlights().size());
	aux->setPosition(	getFrog()->getPosition().getX(),
						getFrog()->getPosition().getY(),
						getFrog()->getPosition().getZ()+getFrog()->getSize().getX(), 1); 
	aux->setDirection(0, 4, -1); //Direcao do sapo
	aux->setSpecular(1.0, 1.0, 1.0, 1.0);
	aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
	aux->setAmbient(0.2, 0.2, 0.2, 1.0);
	aux->setCutOff(getSettings().getLampCutOff());
	aux->setExponent(getSettings().getLampExponent());
	aux->setState(getFrogLight());
	setlights(aux);
	
	getPlayer(0)->setLight(aux);
	
	
	for(int y = 0; y <= 200; y+=100)
		for(int x = -100; x <= 100; x += 200){
			setStaticObject(new StreetLamp(	Vector3(x, y, 0),
											Vector3((x > 0) ? 1 : -1,
													(y > 100) ? -1 : (y < 100) ? 1 : 0,
													1)));
			aux = new LightSource(getlights().size());
			aux->setPosition(x, y, 20, 1);
			aux->setDirection(	(x < 0) ? 1 : -1,
								(y < 100) ? 0.8 : (y > 100) ? -0.8 : 0,
								-1);
			aux->setSpecular(1.0, 1.0, 1.0, 1.0);
			aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
			aux->setAmbient(0.2, 0.2, 0.2, 1.0);
			aux->setCutOff(getSettings().getLampCutOff());
			aux->setExponent(getSettings().getLampExponent());
			aux->setState(_lights_on);
			setlights(aux);
		}



	if (_lights_active)	glEnable(GL_LIGHTING);
	else glDisable(GL_LIGHTING);


	setcameras(new OrthogonalCamera(-120, 120, 0, 200, -100, 100));
	setcameras(camera_atual = new PerspectiveCamera(90, 1, 1, 400));
	setcameras(new PerspectiveCamera(90, 1, 1, 400));

	class Nivel{
	public:
		static void improve_level(int i){
			gm->_speed *= 1.1;
			glutTimerFunc(gm->getSettings().getLevelTime() * 1000, improve_level, 1);
		}
	};
	class Night{
	public:
		static void execute(int i){
			gm->getLight(0)->setState(gm->_modo_dia = !gm->_modo_dia);
			glutTimerFunc(50000, Night::execute, 1);
		}
	};
	Nivel::improve_level(1);
	NewCar::execute(1);
	NewTimberLog::execute(1);	
}
void GameManager::display(){
	if (_modo_dia)	glClearColor(0.00, 0.64, 1.00, 1);
	else			glClearColor(0,0,0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glViewport(0, 0, _w, _h);
	
	getcameras()[0]->computeProjectionMatrix();
	getcameras()[0]->update(_w, _h);
	getcameras()[0]->computeVisualizationMatrix();
	drawLifes();
	drawInfo();
	
	glViewport(0, 0, _w, _h);
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
	case '+': _settings.setNrPolygons(-1); break; //Mais Poligonos
	case '-': _settings.setNrPolygons(1); break; // Menos poligonos
	case 'd': _settings.changeDebug(); break;
	case '1':
	case '2':
	case '3':
		camera_atual_id = key - '1';
		camera_atual = getcameras()[camera_atual_id];
		return;
	case 27: exit(0); break;// Escape key
	case 'r': 
		if(!_dead) return;
		_players[0]->setLifes(5);
		_players[0]->getFrog()->setPosition(0, 10, -1);
		_players[0]->getFrog()->setSpeed(0, 0, 0);
		_dead = false;
		break;
	case 's': if(!_dead) paused = !paused; break;
	case 'n': getLight(0)->setState((_modo_dia = (!_modo_dia))); break;
	case 'h': getLight(1)->setState((_frog_light = (!_frog_light))); break;
	case 'l':
		if ((_lights_active = (!_lights_active))) glEnable(GL_LIGHTING);
		else glDisable(GL_LIGHTING);
		break;
	case 'c': SetStreetLamps(_lights_on = !_lights_on); break;
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
void GameManager::drawLifes(){
	Frog *aux = new Frog();
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	for(int i = 0; i < getPlayer(0)->getLifes(); i++){
		aux->setPosition(240, 20 + i * 15,100);
		aux->draw();
	}
	glPopMatrix();
	delete(aux);
}
void GameManager::drawInfo(){
	if (!paused && !_dead) return;
	glTranslatef(-50, 50, 20);
	glScalef(100, 100, 1);
	glColor4f(1, 1, 1, 0);

	glEnable(GL_TEXTURE_2D);

	if (paused)	glBindTexture(GL_TEXTURE_2D, gm->getTexturePause());
	if (_dead)	glBindTexture(GL_TEXTURE_2D, gm->getTextureGameOver());
		glBegin(GL_POLYGON);
		
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0, 0, 0);

		glTexCoord2f(0.0f, 1.0);
		glVertex3f(0, 1, 0);

		glTexCoord2f(1.0, 1.0);
		glVertex3f(1, 1, 0);

		glTexCoord2f(1.0, 0.0f);
		glVertex3f(1, 0, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
}
void GameManager::onTimer(){
	tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gm->update((paused) ? 0 : tempo_atual - tempo_anterior);
	if (gm->getSettings().getDebug())
		std::cout << tempo_atual - tempo_anterior << std::endl;
	tempo_anterior = tempo_atual;
}
void GameManager::idle(){}

void GameManager::update(unsigned long delta){
	if (getPlayer(0)->getLifes() == 0)
		_dead = true;
	double initial = 0;
	for (DynamicObject *aux : getDynamicObjects()){
		aux->update(delta);
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
	getLight(1)->setPosition(	getFrog()->getPosition().getX(),
								getFrog()->getPosition().getY(),
								getFrog()->getPosition().getZ()+getFrog()->getSize().getX(), 1);  
	glutPostRedisplay();
}
