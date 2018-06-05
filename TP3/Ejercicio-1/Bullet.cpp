#include "Bullet.h"
#define SPEED 800
#define TAM -25

Bullet::Bullet(int x, int y, const char* imagePath) :Object(x, y, imagePath) {
	_speed = SPEED;
	_enable = false;
}
Bullet::~Bullet(){

}
void Bullet::update(float elapsed) {
	if (_enable) {
		if (_y > TAM)
			_y -= _speed * elapsed;
		else
			_enable = false;
	}
}
void Bullet::reset(int x, int y) {
	_x = x;
	_y = y;
}
bool Bullet::isEnable() {
	return _enable;
}
void Bullet::disable() {
	_enable = false;
}
void Bullet::enable() {
	_enable = true;
}