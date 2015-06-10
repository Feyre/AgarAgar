#include "Food.h"
#include <stdlib.h>
#include <iostream>
using std::cout;
#define MAX_FOOD 20
#define FOOD_CH 10000

Food::Food(sf::RenderWindow &temp_win) 
	: window(temp_win)
{
	_grubs.reserve(20);
}

Food::~Food() {
}

int Food::getSize() {
	return _grubs.size();
}

bool Food::isEaten(Vector2f pos, float rad) {
	for (int ii = 0; ii < _grubs.size(); ii++) {
		if (_grubs[ii].isInside(pos, rad)) {
			_grubs.erase(_grubs.begin() + ii);
			cout << "Food hit.\n";
			return 1;
		}
	}
	return 0;
}

bool Food::spawnFood() {
	if (_grubs.size() > MAX_FOOD) { return 0; }
	sf::Vector2u size = window.getSize();
	if(rand()%(FOOD_CH)+1) {
		_grubs.push_back(Grub(5.f, rand() % (int)size.x, rand() % (int)size.y, sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255)));
		return true;
	}
}

void Food::drawFood() {
	for(int ii = 0; ii < _grubs.size(); ii++) {
		window.draw(_grubs[ii]);
	}
}

