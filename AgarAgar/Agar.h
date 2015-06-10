#pragma once
#include "SFML\Graphics.hpp"
#include <string>
using sf::CircleShape;
using sf::Color;
using sf::Vector2i;
using sf::Vector2f;
using std::string;

#define MIN_MOV_MOUSE 10
#define MIN_MOV_CONTR 30
#define SPEED 3.f

class Agar : public CircleShape
{
public:
	Agar(float radius, float pos_x, float pos_y, Color color);
	~Agar();

	void grow(int size = 1);
	bool isInside(Vector2f pos, float rad);
	void updatePosition(Vector2i mousePos);
	void updatePosition(Vector2f contrPos);

	string _name;
	unsigned int _mass;
	bool _alive;
};

