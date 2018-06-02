#include "GameplayState.h"

GameplayState::GameplayState(ALLEGRO_DISPLAY* display) : State(display) {
	srand(time(0));
	_player = new Player(400, 250, "Assets/Player.png");
	_gameOver = false;
}
GameplayState::~GameplayState(){
	if (_player)
		delete _player;
}
void GameplayState::input() {
	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1.0/120);
	if (al_wait_for_event_until(_queue, &event, &timeout))
		switch (event.type){
			case ALLEGRO_EVENT_TIMER:
				_draw = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				_gameOver = true;
				break;
		}
}
void GameplayState::update() {
	float elapsed = al_get_time() - _timeAtLastFrame;
	_timeAtLastFrame = al_get_time();
	_player->update(elapsed);
}
void GameplayState::draw() {
	if (_draw)
	{
		_draw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));
		al_draw_bitmap(_player->getImage(), _player->getX(), _player->getY(), false);
		al_flip_display();
	}
}
void GameplayState::runGame() {
	while (!_gameOver) {
		input();
		update();
		draw();
	}
}