#pragma once
#include "SFML\Graphics.hpp"
using sf::CircleShape;
using sf::Color;
using sf::Vector2i;
using sf::Vector2f;
using std::string;

class Grub : public CircleShape
{
public:
	Grub(float radius, float pos_x, float pos_y, Color color);
	~Grub();

	bool isInside(Vector2f pos, float rad);
	
private:
	unsigned int _mass = 5;
};

