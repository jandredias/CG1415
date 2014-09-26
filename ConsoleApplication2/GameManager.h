#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include <list>
#include "Header.h"
#include "Camera.h"
#include "LightSource.h"
#include "GameObject.h"
#include "GL/glut.h"

class GameManager
{
	Camera *_cameras;
	LightSource *_light_sources;
	std::list<GameObject> _game_objects;
	public:
		GameManager();
		~GameManager();
		std::list<GameObject> getgame_objects(void);
		Camera* getcameras(void);
		LightSource* getlight_sources(void);
		GameObject* setgame_objects(GameObject*);
		Camera* setcameras(Camera*);
		LightSource* setlight_sources(LightSource*);
		static void display();
		static void reshape(GLsizei w, GLsizei h);
		void keyPressed();
		void onTimer();
		void idle();
		void update();
		void init();
};
#endif

