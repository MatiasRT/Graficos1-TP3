#include "GameplayState.h"
#define MAX_Y 0
#define MAX_X 630
#define MIN_X 20
#define PLANES 6
ALLEGRO_FONT* font;


GameplayState::GameplayState(ALLEGRO_DISPLAY* display) : State(display) {

	srand(time(0));
	_background = al_load_bitmap("Background.png");

	al_init_ttf_addon();
	font = al_load_font("StarWarsFont.ttf", 27, NULL);

	_player = new Player(300, 625, "Xwing.png");
	_bullet = new Bullet(-100,-100, "Bullet.png");

	for (int i = 0; i < PLANES; i++) {
		_airplane[i] = new Airplane(rand() % (MAX_X - 64 - MIN_X + 1) + MIN_X, MAX_Y, "Enemy.png");
	}
	_gameOver = false;
	
}
GameplayState::~GameplayState(){
	if (_player)
		delete _player;
	for (int i = 0; i < PLANES;i++) {
		if (_airplane[i])
			delete _airplane[i];
	}
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
			case ALLEGRO_EVENT_KEY_UP:
				if (event.keyboard.keycode == ALLEGRO_KEY_SPACE && !_bullet->isEnable()) {
					_bullet->enable();
					_bullet->reset(_player->getX() + 27, _player->getY());
				}

		}
}
void GameplayState::update() {
	float elapsed = al_get_time() - _timeAtLastFrame;
	_timeAtLastFrame = al_get_time();
	_player->update(elapsed);
	_bullet->update(elapsed);
	for (int i = 0; i < PLANES; i++) {
		_airplane[i]->update(elapsed);
		if (_airplane[i]->isEnable() && collide(_player, _airplane[i])) {
			enemyCollide(_player, _airplane[i]);
		}
		if (_airplane[i]->isEnable() && collide(_bullet, _airplane[i])) {
			bulletCollide(_bullet, _airplane[i]);
		}
	}
}
void GameplayState::draw() {
	if (_draw)
	{
		al_draw_bitmap(_background, 0, 0, 0);
		_draw = false;
		al_draw_bitmap(_player->getImage(), _player->getX(), _player->getY(), false);
		al_draw_bitmap(_bullet->getImage(), _bullet->getX(), _bullet->getY(), false);

		for (int i = 0; i < PLANES; i++) {
			if (_airplane[i]->isEnable()) {
				al_draw_bitmap(_airplane[i]->getImage(), _airplane[i]->getX(), _airplane[i]->getY(), false);
			}
		}
		al_draw_textf(font, al_map_rgb(255, 255, 255), 310, 700, ALLEGRO_ALIGN_CENTRE, "Lives: %d", _player->getLife());
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
}
void GameplayState::runGame() {
	while (!_gameOver) {
		input();
		update();
		draw();
	}
}
bool GameplayState::collide(Object* O1, Object* O2) {
	if (O1->getX() < O2->getX() + 64 && O1->getX() + 64 > O2->getX()  &&
		O1->getY() < O2->getY() + 64 && O1->getY() + 64 > O2->getY() ) {
		return true;
	}
	else
		return false;
}
void GameplayState::enemyCollide(Player* P1, Airplane* E1) {
	P1->death();
	E1->disable();
	if (P1->getLife() == 0)
		_gameOver = true;
}
void GameplayState::bulletCollide(Bullet* B1, Airplane* E1) {
	B1->reset(-100, -100);
	E1->disable();
}