#ifndef __PLAYER__
#define __PLAYER__

#include "Frog.h"
#include "LightSource.h"
#include <map>

class Player
{
	int _id = 0;
	int _lifes = 0;
	int _points = 0;
	int _time_points = 1000;
	LightSource *_light;
	std::map<char, Vector3> _keys;

	Frog *_frog;
	public:
		Player();
		Player(char key1, char key2, char key3, char key4);
		~Player();
		std::map<char, Vector3> getKeys();
		void setLight(LightSource *a);
		LightSource* getLight();
		int getID();
		void setID(int id);
		void setLifes(int x);
		int getLifes();
		void setPoints(int points);
		int getPoints();
		Frog* getFrog();
		void setFrog(Frog* a);

		void newRound();

};

#endif
