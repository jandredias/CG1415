#pragma once
#include "Header.h"
class GameManager
{
	std::vector<GameObject> _game_objects;
	std::vector<Camera> *_cameras;
	LightSource *_light_sources;
public:
	GameManager();
	~GameManager();
	void display();
	void reshape(GLsizei w, GLsizei h);
	void keyPressed();
	void onTimer();
	void idle();
	void update();
	void init();
};

