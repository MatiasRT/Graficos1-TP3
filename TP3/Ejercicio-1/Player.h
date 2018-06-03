#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
enum Movement {
	Up, Down, Left, Right
};
class Player : public Object {
	float _speedx;
	float _speedy;
	void movement(Movement direction, float elapsed);
public:
	Player(int x, int y, const char* imagePath);
	~Player();
	void update(float elapsed);
};
#endif