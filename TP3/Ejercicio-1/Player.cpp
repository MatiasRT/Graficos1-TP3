#include "Player.h"
#include <iostream>
#define SPEEDX 300
#define SPEEDY 150
#define LIFE 3
using namespace std;
Player::Player(int x, int y, const char* imagePath) : Object(x, y, imagePath) {
	_speedx = SPEEDX;
	_speedy = SPEEDY;
	_life = LIFE;
}
Player::~Player(){

}
void Player::update(float elapsed) {
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		movement(Up, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		movement(Down, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		movement(Left, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		movement(Right, elapsed);
}
void Player::movement(Movement direction, float elapsed) {
	switch (direction){
		case Up:
			if (_y > 12)
				_y -= _speedy * elapsed;
			break;
		case Down:
			if (_y + 64 < 700)
				_y += _speedy * elapsed;
			break;
		case Left:
			if (_x > 2) 
				_x -= _speedx * elapsed;
			break;
		case Right:
			if (_x + 64 < 648)
				_x += _speedx * elapsed;
			break;
	}
}
int Player::getLife() {
	return _life;
}
void Player::death() {
	_life--;
	if (_life > 0) {
		respawn();
	}
}
void Player::respawn() {
	_x = 300;
	_y = 625;
}