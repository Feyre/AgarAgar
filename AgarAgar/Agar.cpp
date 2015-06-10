#include "Agar.h"
#include <cmath>

Agar::Agar(float radius, float pos_x, float pos_y, Color color) {
	setRadius(radius);
	setOrigin(radius, radius);
	setPosition(pos_x, pos_y);
	setFillColor(color);
	_name = "Player";
	_mass = (unsigned int)radius;
	_alive = true;
}

Agar::~Agar()
{
}

void Agar::grow(int size) {
	if (!_alive) { return;}
	setRadius(getRadius() + (float)size);
	setOrigin(getRadius(), getRadius());
	_mass = (unsigned int)getRadius();
}

bool Agar::isInside(Vector2f pos, float rad) {
	if (!_alive) { return 0;}
	Vector2f _pos = getPosition();
	float _rad = getRadius();
	if (_rad >= rad) { return 0; }
	else if (_pos.x + _rad < pos.x + rad  &&  _pos.x - _rad > pos.x - rad) {
		if (_pos.y + _rad < pos.y + rad  &&  _pos.y - _rad > pos.y - rad) {
			return 1;
		}
	}
	return 0;
}

void Agar::updatePosition(Vector2i mousePos) {
	if (!_alive) { return;}
	Vector2f agarPos = getPosition();
	float diff_x = (float)mousePos.x - agarPos.x; 
	float diff_y = (float)mousePos.y - agarPos.y; 
	float mag = sqrt(diff_x*diff_x + diff_y*diff_y);
	if (mag <= MIN_MOV_MOUSE) {
		return;
	}
	else {
		move(diff_x/mag*SPEED, diff_y/mag*SPEED);
	}
}

void Agar::updatePosition(Vector2f contrPos) {
	if (!_alive) { return;}
	Vector2f agarPos = getPosition();
	float diff_x = contrPos.x; 
	float diff_y = contrPos.y; 
	float mag = sqrt(diff_x*diff_x + diff_y*diff_y);
	if (mag <= MIN_MOV_CONTR) {
		return;
	}
	else {
		move(diff_x/mag*SPEED, diff_y/mag*SPEED);
	}
}
