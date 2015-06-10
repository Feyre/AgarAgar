#pragma once
#include "Grub.h"
#include <vector>
using std::vector;

class Food
{
public:
	Food(sf::RenderWindow &temp_win);
	~Food();

	int getSize();
	bool isEaten(Vector2f pos, float rad);
	bool spawnFood();
	void drawFood();

private:
	vector<Grub> _grubs;
	sf::RenderWindow &window;
};

