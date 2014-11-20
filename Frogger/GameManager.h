#pragma once

#include "Camera.h"
#include "Player.h"
#include "Vector3.h"
#include "LightSource.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include <vector>
#include <map>
#include <list>
#include <iostream>

#define PI		3.14159265358979323846
#define CAR_LANE_1					26
#define CAR_LANE_SIZE_Y				12
#define CAR_LANE_NO					5
#define SPEED_FROG					40
#define TL_POS_BEGIN0				-150
#define	TL_POS_BEGIN1				150

class Settings {
	double _nr_polygons = 5;
	int _level_time = 10;
	bool _debug = false;
	int _lamp_exponent = 10;
	int _lamp_cutoff = 60;

	public:
	int getNrPolygons(){ return _nr_polygons; }
	int getLevelTime(){ return _level_time; }
	int getDebug(){ return _debug; }
	void changeDebug(){ _debug = (!_debug); }
	void setNrPolygons(int a){ (a > 0) ? (_nr_polygons *= 1.1) : (_nr_polygons *= 0.9); if(_nr_polygons > 5) _nr_polygons = 5 ; }
	int getLampExponent(){ return _lamp_exponent; }
	int getLampCutOff(){ return _lamp_cutoff; }
};

class GameManager{
	GLuint _TextureRoad;
	GLuint _TextureRiver;
	GLuint _TextureRiverside;
	GLuint _TextureRoadside;
	GLuint _TexturePause;
	GLuint _TextureGameOver;

	Settings _settings;

	bool _debug = false;

	
	Vector3 _size_map;
	Vector3 _center_map;
	int _no_players = 1;
	std::vector<Player *> _players;

	int l_times = 0; //indica o numero de vezes que a tecla 'l' foi primida

	int tempo_atual;
	int tempo_anterior;
	int tempo_inicio = 0;
	int _w = 0;
	int _h = 0;
	double _speed_car[5];
	double _speed_river[5];
	bool _status = 0;
	double _speed = 1;
	bool _dead = false;
	bool paused = false;
	
	std::list<DynamicObject *> _dynamic_game_objects;
	std::list<StaticObject *> _static_game_objects;
	Frog *frog;
	Camera *camera_atual;
	int camera_atual_id = 1;
	std::vector<Camera *> _cameras;
	std::list<Frog *> list_frogs;
	
	std::vector<LightSource *> _lights;

	bool _modo_dia = true;
	bool _lights_on = false;
	bool _lights_active = true;
	bool _frog_light = false;
	
	public:
		GameManager();
		~GameManager();
		const double* getSpeedCar();
		const double* getSpeedRiver();
		GLuint getTextureRoad(){ return _TextureRoad; }
		GLuint getTextureRiver(){ return _TextureRiver; }
		GLuint getTextureRiverside(){ return _TextureRiverside; }
		GLuint getTextureRoadside(){ return _TextureRoadside; }
		GLuint getTexturePause(){ return _TexturePause; }
		GLuint getTextureGameOver(){ return _TextureGameOver; }
		Settings getSettings(){ return _settings; }

		bool getDayMode(){ return _modo_dia; }
		bool getLightsOn(){ return _lights_on; }
		bool getLightsActive(){ return _lights_active; }
		bool getFrogLight(){ return _frog_light; }

		bool setDayMode(bool a){ return _modo_dia = a; }
		bool setLightsOn(bool a){ return _lights_on = a; }
		bool setLightsActive(bool a){ return _lights_active = a; }
		bool setFrogLight(bool a){ return _frog_light = a; }

		bool getDebug(){ return _debug; }
		double getGameSpeed();
		Frog* getFrog();
		void setPlayer(Player *a);
		std::vector<Player *> getPlayers();
		Player * getPlayer(int id);
		void drawLifes();
		void drawInfo();
		void setNewFrog(Vector3 a);
		std::list<Frog*> getFrogs();

		std::list<DynamicObject *> getDynamicObjects();
		void setDynamicObject(DynamicObject * aux);

		std::list<StaticObject *> getStaticObjects();
		void setStaticObject(StaticObject* aux);
		
		std::vector<Camera *> getcameras(void);
		std::vector<Camera *> setcameras(Camera*aux);

		std::vector<LightSource *> getlights(void);
		LightSource* getLight(int i);
		std::vector<LightSource *> setlights(LightSource*aux);
		void SetStreetLamps(bool state);
		void changeStatus(bool a);
		bool getStatus();
		void display(void);
		void reshape(GLsizei w, GLsizei h);
		void keyPressed(unsigned char key);
		void keyUp(unsigned char key);
		void onTimer();
		void idle();
		void update(unsigned long delta);
		void init();
};
