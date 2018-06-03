#include "Airplane.h"
#define MAXSPEED 250
#define MINSPEED 150
#define MAXTIME 4
#define MINTIME 1
#define MAX_Y 0
#define MAX_X 630
#define MIN_X 20
Airplane::Airplane(int x, int y, const char* imagePath):Object(x,y,imagePath){
	_speed = rand()%(MAXSPEED - MINSPEED + 1) + MINSPEED;
	_timer = rand() % (MAXTIME - MINTIME + 1) + MINTIME;
	_enable = false;
}
Airplane::~Airplane()
{
}
void Airplane::update(float elapsed) {
	if (_enable) {
		if (_y < 645)
			_y += _speed * elapsed;
		else
			_enable = false;
	}
	else {
		_timer -= elapsed;
		if (_timer <= 0)
			respawn();
	}
}
void Airplane::respawn() {
	_enable = true;
	_speed = rand() % (MAXSPEED - MINSPEED + 1) + MINSPEED;
	_timer = rand() % (MAXTIME - MINTIME + 1) + MINTIME;
	_y = MAX_Y;
	_x = rand() % (MAX_X - 32 - MIN_X + 1) + MIN_X;
}
void Airplane::disable() {
	_enable = false;
}
