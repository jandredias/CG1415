#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
#include "Header.h"
class GameManager
{
	int tempo_atual;
	int tempo_anterior;
	int tempo_inicio = 0;
	int velocidade = 1;
	int _w = 0;
	int _h = 0;
	double _speed_car[5];
	double _speed_river[5];
	bool _status = 0;

	std::list<DynamicObject *> _dynamic_game_objects;
	std::list<GameObject *> _static_game_objects;
	Frog *frog;
	Camera *camera_atual;
	std::list<Camera *> _cameras;
	
	LightSource *_light_sources;

	public:
		GameManager();
		~GameManager();

		const double* getSpeedCar();
		const double* getSpeedRiver();

		std::list<DynamicObject *> getDynamicObjects();
		void setDynamicObject(DynamicObject * aux);

		std::list<GameObject *> getStaticObjects();
		void setStaticObject(GameObject* aux);
		
		std::list<Camera *> getcameras(void);
		std::list<Camera *> setcameras(Camera*aux);

		LightSource* getlight_sources(void);
		LightSource* setlight_sources(LightSource*);
		void changeStatus(bool a);
		bool getStatus();
		void TimberLogFactory();
		void resetFrog();
		void resetFrog2();
		void CarFactory();
		void factory();
		void display(void);
		void reshape(GLsizei w, GLsizei h);
		void keyPressed(unsigned char key);
		void keyUp(unsigned char key);
		void onTimer();
		void idle();
		void update(unsigned long delta);
		void init();
};

#endif

