#ifndef OBJECT_H
#define OBJECT_H
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class Object {
protected:
	ALLEGRO_BITMAP * _image;
	int _x;
	int _y;
public:
	Object(int x, int y, const char* imagePath);
	~Object();
	int getX();
	int getY();
	ALLEGRO_BITMAP* getImage();
};
#endif
