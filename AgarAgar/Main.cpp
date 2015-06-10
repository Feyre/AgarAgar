
#include <SFML/Graphics.hpp>
#include "Players.h"
#include "Food.h"
#include <iostream>
using namespace std;

int main(){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(640, 480), "AgarAgar", sf::Style::Default);
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AgarAgar", sf::Style::None);

	Players _players(window);
	Food _noms(window);

	while (window.isOpen()){
		sf::Event event;

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			else if (event.type == sf::Event::MouseMoved) {
			}
			else if (event.type == sf::Event::JoystickMoved) {
			}
		}

		sf::sleep(sf::milliseconds(10));

		_players.updateCursors();
		_players.updateAgar();
		_noms.spawnFood();
		_players.checkNom(_noms);

		window.clear();
		_noms.drawFood();
		_players.drawAgar();
		window.display();
	}
	return 0;
}

// s = ut+0.5at^2
// v = u+at
// a = a