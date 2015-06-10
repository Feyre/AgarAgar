#include "Grub.h"


Grub::Grub(float radius, float pos_x, float pos_y, Color color) {
	setRadius(radius);
	setOrigin(radius, radius);
	setPosition(pos_x, pos_y);
	setFillColor(color);
	_mass = (unsigned int)radius;
}


Grub::~Grub()
{
}

bool Grub::isInside(Vector2f pos, float rad) {
	Vector2f _pos = getPosition();
	float _rad = getRadius();
	if(_rad >= rad) {return 0;}
	else if(_pos.x+_rad < pos.x+rad  &&  _pos.x-_rad > pos.x-rad) {
		if(_pos.y+_rad < pos.y+rad  &&  _pos.y-_rad > pos.y-rad) {
			return 1;
		}
	} 
	return 0;
}

