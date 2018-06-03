#include "State.h"
#define FRAME 1.0/60
State::State(ALLEGRO_DISPLAY* display){
	_display = display;
	_background = NULL;
	_timer = al_create_timer(FRAME);
	_queue = al_create_event_queue();
	_draw = true;
	_timeAtLastFrame = 0;
	al_register_event_source(_queue, al_get_keyboard_event_source());
	al_register_event_source(_queue, al_get_display_event_source(display));
	al_register_event_source(_queue, al_get_timer_event_source(_timer));
	al_start_timer(_timer);
}
State::~State(){
	al_destroy_event_queue(_queue);
	al_destroy_timer(_timer);
	al_destroy_bitmap(_background);
}
