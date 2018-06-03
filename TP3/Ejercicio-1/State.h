#ifndef STATE_H
#define STATE_H
#include <allegro5\allegro.h>
class State {
protected:
	ALLEGRO_DISPLAY* _display;
	ALLEGRO_BITMAP* _background;
	ALLEGRO_TIMER* _timer;
	ALLEGRO_EVENT_QUEUE* _queue;
	bool _draw;
	float _timeAtLastFrame;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
public:
	State(ALLEGRO_DISPLAY* display);
	~State();
};
#endif