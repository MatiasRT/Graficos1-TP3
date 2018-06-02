#include "Player.h"
#include <iostream>
using namespace std;
Player::Player(int x, int y, const char* imagePath) : Object(x, y, imagePath) {
	_speed = 300;
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
				_y -= _speed * elapsed;
			break;
		case Down:
			if (_y + 64 < 536)
				_y += _speed * elapsed;
			break;
		case Left:
			if (_x > 2) 
				_x -= _speed * elapsed;
			break;
		case Right:
			if (_x + 64 < 798)
				_x += _speed * elapsed;
			break;
	}
}