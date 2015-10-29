
#include "Player.h"
#include "GameManager.h"
#include "LightSource.h"
extern GameManager *gm;

Player::Player(){
	_lifes = 5;	//PLayer's lifes
	_points = 0; //Player's points
	_time_points = 1000;	//Timing Points 1000 => 0
	gm->setDynamicObject(_frog = new Frog(0, 10, -1));
}
Player::Player(char keydown, char keyup, char keyleft, char keyright) : Player(){
	_keys.insert(std::pair<char, Vector3>(keyup, Vector3(0, 1, 0)));
	_keys.insert(std::pair<char, Vector3>(keydown, Vector3(0, -1, 0)));
	_keys.insert(std::pair<char, Vector3>(keyleft, Vector3(-1, 0, 0)));
	_keys.insert(std::pair<char, Vector3>(keyright, Vector3(1, 0, 0)));
	
	_light = new LightSource(gm->getlights().size());
	_light->setPosition(_frog->getPosition().getX(),
						_frog->getPosition().getY(),
						_frog->getPosition().getZ()+_frog->getSize().getX(), 1); 
	_light->setDirection(0, 4, -1); //Direcao do sapo
	_light->setSpecular(1.0, 1.0, 1.0, 1.0);
	_light->setDiffuse(1.0, 1.0, 1.0, 1.0);
	_light->setAmbient(0.2, 0.2, 0.2, 1.0);
	_light->setCutOff(90);
	_light->setExponent(2);
	_light->setState(_lightState);
	gm->setlights(_light);
	
}

Player::~Player(){}
bool Player::changeLightState(){ 
	_lightState = (!_lightState);
	_light->setState(_lightState);
	return _lightState;
}
void Player::setLight(LightSource *a) { _light = a; }
LightSource* Player::getLight(){ return _light; }


int Player::getID(){ return _id; }
void Player::setID(int id){ _id = id; }

void Player::setLifes(int x){ _lifes = x; }
int Player::getLifes(){ return _lifes; }

void Player::setPoints(int points){ _points = points; }
int Player::getPoints(){ return _points; }

Frog* Player::getFrog(){ return _frog; }
void Player::setFrog(Frog* a){ _frog = a; }

std::map<char, Vector3> Player::getKeys(){ return _keys; }
void Player::newRound(){
	_points += _time_points;
	_time_points = 1000;
	if (rand() % 10 == 0) _lifes++;
	_frog->setPosition(0, 10, -1);
	_frog->setSpeed(0, 0, 0);
	return;
}

void Player::updateLight(){
	Vector3 direction;
	direction.set(0, 4, -1);
	if (_frog->getSpeed().getX() > 0)
		direction.set(4, 0, -1);
	else if (_frog->getSpeed().getX() < 0)
		direction.set(-4, 0, -1);
	else if (_frog->getSpeed().getY() < 0)
		direction.set(0, -4, -1);
	_light->setDirection(direction.getX(), direction.getY(), direction.getZ());
	_light->setPosition(_frog->getPosition().getX(),
						_frog->getPosition().getY(),
						_frog->getPosition().getZ()+_frog->getSize().getX(), 1);
	
}

