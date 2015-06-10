#pragma once

#include "Agar.h"
#include "Food.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>      //srand, rand 
#include <time.h>
using std::vector;

class Players
{
public:
	Players(sf::RenderWindow &temp_win);
	~Players();

	int updatePlayers();
	int checkPlayers();
	int isEaten(Vector2f pos, float rad);
	void checkNom(Food &noms);
	void updateCursors();
	void updateAgar();
	void drawAgar();

private:
	int n_players;
	vector<Agar> Agario;
	sf::Vector2i mousePosition;
	vector<sf::Vector2f> controllerPositions;

	sf::RenderWindow &window;
};

