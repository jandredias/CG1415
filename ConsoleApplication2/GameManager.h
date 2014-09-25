#pragma once
#include "LightSource.h"
#include <vector>
#include "Camera.h"
#include "GameObject.h"
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
class Camera;
class GameManager
{
	std::vector<GameObject> _game_objects;
	Camera *_cameras;
	LightSource *_light_sources;
public:
	GameManager();
	~GameManager();
	GameObject* getgame_objects(void);
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

