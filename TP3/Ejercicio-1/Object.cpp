#include "Object.h"
Object::Object(int x, int y, const char* imagePath) {
	_x = x;
	_y = y;
	_image = al_load_bitmap(imagePath);
}
Object::~Object() {
	al_destroy_bitmap(_image);
}
int Object::getX() {
	return _x;
}
int Object::getY() {
	return _y;
}
ALLEGRO_BITMAP* Object::getImage() {
	return _image;
}