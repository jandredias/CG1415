#pragma once
class GameManager
{
	GameObject *_game_objects;
	LightSource *_light_sources;
	Camera *_cameras;
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

