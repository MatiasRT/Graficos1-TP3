#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
//#include "Button.h"
#include "GameplayState.h"
#define WIDTH 650
#define HEIGHT 750

using namespace std;

int main(int argc, char **argv) {
	ALLEGRO_DISPLAY *display;
	
	GameplayState* game;

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
	
	game = new GameplayState(display);
	game->runGame();

	al_destroy_display(display);
	al_uninstall_keyboard();

	return 0;
}