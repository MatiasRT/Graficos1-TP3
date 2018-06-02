#ifndef BUTTON_H
#define BUTTON_H
class Button {
	int _x;
	int _y;
	int _w;
	int _h;
public:
	Button(int xpos, int ypos, int width, int height) : _x(xpos), _y(ypos), _w(width), _h(height) {
	
	}
	bool Clicked(int mousex, int mousey) {
		if ((mousex > _x + _w - 1) ||
			(mousex < _x) ||
			(mousey > _y + _h - 1) ||
			(mousey < _y)) {
			return false;
		}
		return true;
	}
};
#endif
