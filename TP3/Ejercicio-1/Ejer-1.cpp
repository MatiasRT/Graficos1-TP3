#include <iostream>
#include "allegro5\allegro.h"
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include "GameplayState.h"

#define WIDTH 650
#define HEIGHT 750

using namespace std;

int main(int argc, char **argv) {
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_BITMAP* _background1;
	ALLEGRO_BITMAP* _background2;
	ALLEGRO_DISPLAY *display;
	GameplayState* game;
	bool gameStart = false;
	int flicker = 0;

	if (!al_init())
	{
		cerr << "Error initializing Allegro." << endl;
		return 1;
	}

	display = al_create_display(WIDTH, HEIGHT);
	if (!display)
	{
		cerr << "Error creating display." << endl;
		return 1;
	}

	if (!al_install_keyboard())
	{
		cerr << "Error installing keyboard." << endl;
		return 1;
	}

	if (!al_init_image_addon())
	{
		cerr << "Error initializing Allegro Image." << endl;
		return 1;
	}

	if (!al_init_font_addon())
	{
		cerr << "Error initializing Allegro Font." << endl;
		return 1;
	}

	if (!al_init_ttf_addon())
	{
		cerr << "Error initializing Allegro TTF." << endl;
		return 1;
	}	
	
	
	_background1 = al_load_bitmap("Menu1.png");
	_background2 = al_load_bitmap("Menu2.png");


	while (!gameStart) {

		if (flicker < 1500) {
			al_draw_bitmap(_background1, 0, 0, 0);
			flicker++;

		}
		else if (flicker < 3000){
			al_draw_bitmap(_background2, 0, 0, 0);
			flicker++;
		}
		else flicker = 0;


		al_get_keyboard_state(&keyState);
		if (al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			gameStart = true;
		if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
			return 0;

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	if (gameStart) {
		game = new GameplayState(display);
		game->runGame();
	}


	al_destroy_display(display);
	al_uninstall_keyboard();

	return 0;
}