#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include "State.h"
#include "Player.h"
#include <iostream>
#include <ctime>
class GameplayState : public State {
	Player* _player;
	bool _gameOver;
protected:
	void input();
	void update();
	void draw();
public:
	GameplayState(ALLEGRO_DISPLAY* display);
	~GameplayState();
	void runGame();
};
#endif