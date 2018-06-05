#ifndef BULLET_H
#define BULLET_H
#include "Object.h"
class Bullet : public Object {
	int _speed;
	bool _enable;
public:
	Bullet(int x, int y, const char* imagePath);
	~Bullet();
	bool isEnable();
	void enable();
	void disable();
	void reset(int x, int y);
	void update(float elapsed);
};
#endif