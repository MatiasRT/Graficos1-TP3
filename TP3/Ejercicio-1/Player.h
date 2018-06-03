#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"

class Player : public Object {
	enum Movement { Up, Down, Left, Right };
	float _speedx;
	float _speedy;
	int _life;
	void movement(Movement direction, float elapsed);
public:
	Player(int x, int y, const char* imagePath);
	~Player();
	void update(float elapsed);
	int getLife();
	void death();
	void respawn();
};
#endif