#include "Player.h"
Player::Player(float x, float y, const char* imagePath) : Object(x, y, imagePath) {
	_speed = 150;
}
Player::~Player(){

}
void Player::update(float elapsed) {
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		movement(Left, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		movement(Right, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		movement(Up, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		movement(Down, elapsed);
}
void Player::movement(Movement direction, float elapsed) {
	switch (direction)
	{
	case Left:
		if (_x > 32)
			_x -= _speed * elapsed;
		break;
	case Right:
		if (_x + 64 < 768)
			_x += _speed * elapsed;
		break;
	case Up:
		if (_y > 64)
			_y -= _speed * elapsed;
		break;
	case Down:
		if (_y + 64 < 568)
			_y += _speed * elapsed;
		break;
	}
}