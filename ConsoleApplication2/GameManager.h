#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Header.h"
class GameManager
{
	int tempo_atual;
	int tempo_anterior;
	std::list<GameObject *> _dynamic_game_objects;
	std::list<GameObject *> _static_game_objects;
	Frog *frog;
	std::list<Camera *> _cameras;
	
	LightSource *_light_sources;

	public:
		GameManager();
		~GameManager();
		
		std::list<GameObject *> getDynamicObjects();
		void setDynamicObject(GameObject * aux);

		std::list<GameObject *> getStaticObjects();
		void setStaticObject(GameObject* aux);
		
		std::list<Camera *> getcameras(void);
		std::list<Camera *> setcameras(Camera*aux);

		LightSource* getlight_sources(void);
		LightSource* setlight_sources(LightSource*);
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

