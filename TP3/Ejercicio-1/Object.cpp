#include "Object.h"
Object::Object(float x, float y, const char* imagePath) {
	_x = x;
	_y = y;
	_image = al_load_bitmap(imagePath);
}
Object::~Object() {
	al_destroy_bitmap(_image);
}
float Object::getX() {
	return _x;
}
float Object::getY() {
	return _y;
}
ALLEGRO_BITMAP* Object::getImage() {
	return _image;
}