#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "Object.h"
class Airplane : public Object{
	int _speed;
	float _timer;
	bool _enable;
public:
	Airplane(int x, int y, const char* imagePath);
	~Airplane();
	void update(float elapsed);
	void respawn();
	void disable();
	bool isEnable();
};
#endif