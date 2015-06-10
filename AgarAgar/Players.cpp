#include "Players.h"
using namespace std;

Players::Players(sf::RenderWindow &temp_win) 
	: window(temp_win)
{
	//window = temp_win;
	srand (time(NULL));
	updatePlayers();
	Agario.push_back(Agar(40, 0, 0, sf::Color::Cyan));
	mousePosition = sf::Mouse::getPosition(window);
	for(int ii = 0; ii < n_players-1; ii++) {
		Agario.push_back(	Agar(40, 100*((float)ii+1), 100*((float)ii+1), sf::Color(rand()%255+1, rand()%255+1, rand()%255+1, 255))	);
		controllerPositions.push_back(sf::Vector2f(sf::Joystick::getAxisPosition(ii, sf::Joystick::X), sf::Joystick::getAxisPosition(ii, sf::Joystick::Y)));
	}
}

Players::~Players() {
}


int Players::updatePlayers() {
	n_players = 0;
	while(sf::Joystick::isConnected(n_players)) {
		cout << "Joystick " << n_players << " connected.\n";
		n_players++;
	}
	n_players++;
	return n_players;	
}

int Players::checkPlayers() {
	for(int ii = 0; ii < n_players-1; ii++) {
		if(!sf::Joystick::isConnected(ii)) {
			cout << "Please reconnect Joystick " << ii << endl;
			while(!sf::Joystick::isConnected(ii)) {
				sf::sleep(sf::milliseconds(100));
				sf::Joystick::update();
			}
			cout << "Joystick " << ii << "reconnected.\n";
		}
	}
	return 0;
}

void Players::checkNom(Food &noms) {
	for (int ii = 0; ii < n_players; ii++) {
		if (noms.isEaten(Agario[ii].getPosition(), Agario[ii].getRadius())) {
			Agario[ii].grow();
		}
		if (int num = isEaten(Agario[ii].getPosition(), Agario[ii].getRadius())) {
			Agario[ii].grow(num);
		}
	}
}

int Players::isEaten(Vector2f pos, float rad) {
	for (int ii = 0; ii < Agario.size(); ii++) {
		if (Agario[ii].isInside(pos, rad)) {
			Agario[ii]._alive = false;
			cout << "Player hit.\n";
			return Agario[ii]._mass*0.5f;
		}
	}
	return 0;
}

void Players::updateCursors() {
	mousePosition = sf::Mouse::getPosition(window);
	for(int ii = 0; ii < n_players-1; ii++) {
		controllerPositions[ii] = sf::Vector2f(sf::Joystick::getAxisPosition(ii, sf::Joystick::X), sf::Joystick::getAxisPosition(ii, sf::Joystick::Y));
	}
}

void Players::updateAgar() {
	checkPlayers();
	Agario[0].updatePosition(mousePosition);
	for(int ii = 0; ii < n_players-1; ii++) {
		Agario[ii+1].updatePosition(controllerPositions[ii]);
	}
}

void Players::drawAgar() {
	for(int ii = 0; ii < n_players; ii++) {
		if (Agario[ii]._alive) {
			window.draw(Agario[ii]);
		}
	}
}


