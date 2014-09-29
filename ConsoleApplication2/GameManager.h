#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include <queue>
#include "Header.h"
#include "Camera.h"
#include "LightSource.h"
#include "GameObject.h"
#include "GL/glut.h"

class GameManager
{
	std::queue<Camera *> _cameras;
	LightSource *_light_sources;
	std::queue<GameObject *> _game_objects;
	public:
		GameManager();
		~GameManager();

		std::queue<GameObject *> getgame_objects(void);
		GameObject* setgame_objects(GameObject*);

		std::queue<Camera *> getcameras(void);
		std::queue<Camera *> setcameras(Camera*);

		LightSource* getlight_sources(void);
		LightSource* setlight_sources(LightSource*);
		void display(void);
		void reshape(GLsizei w, GLsizei h);
		void keyPressed(unsigned char key, int i);
		void onTimer();
		void idle();
		void update(unsigned long delta);
		void init();
};

#endif

