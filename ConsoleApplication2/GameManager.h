#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include <stack>
#include "Header.h"
#include "Camera.h"
#include "LightSource.h"
#include "GameObject.h"
#include "GL/glut.h"

class GameManager
{
	Camera *_cameras;
	LightSource *_light_sources;
	std::stack<GameObject *> _game_objects;
	public:
		GameManager();
		~GameManager();
		std::stack<GameObject *> getgame_objects(void);
		Camera* getcameras(void);
		LightSource* getlight_sources(void);
		GameObject* setgame_objects(GameObject*);
		Camera* setcameras(Camera*);
		LightSource* setlight_sources(LightSource*);
		void display(void);
		void reshape(GLsizei w, GLsizei h);
		void keyPressed();
		void onTimer();
		void idle();
		void update();
		void init();
};

#endif

