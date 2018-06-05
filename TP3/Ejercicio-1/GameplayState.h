#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "State.h"
#include "Player.h"
#include "Airplane.h"
#include "Bullet.h"
#include <iostream>
#include <ctime>
class GameplayState : public State {
	Player* _player;
	Airplane* _airplane[6];
	Bullet* _bullet;
	bool _gameOver;
protected:
	void input();
	void update();
	void draw();
	void enemyCollide(Player* P1, Airplane* E1);
	void bulletCollide(Bullet* B1, Airplane* E1);
	bool collide(Object* O1, Object* O2);
public:
	GameplayState(ALLEGRO_DISPLAY* display);
	~GameplayState();
	void runGame();
};
#endif