#include "Airplane.h"
#define MAXSPEED 300
#define MINSPEED 150
#define MAXTIME 3
#define MINTIME 1
#define MAXY 0
#define MAXX 630
#define MINX 20
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
		if (_y < 650)
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
	_speed = rand() % (300 - 150 + 1) + 150;
	_timer = rand() % (3 - 1 + 1) + 1;
	_y = MAXY;
	_x = rand() % (MAXX - 32 - MINX + 1) + MINX;
}
void Airplane::disable() {
	_enable = false;
}
