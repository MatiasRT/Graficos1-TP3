#ifndef OBJECT_H
#define OBJECT_H
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class Object {
protected:
	ALLEGRO_BITMAP * _image;
	float _x;
	float _y;
public:
	Object(float x, float y, const char* imagePath);
	~Object();
	float getX();
	float getY();
	ALLEGRO_BITMAP* getImage();
};
#endif
