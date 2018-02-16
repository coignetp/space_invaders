#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game g(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	g.getRealWindow().getRealLayers().at(0).draw(shape);

	while (g.getRealWindow().isOpen())
	{
		sf::Event event;
		while (g.getRealWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				g.getRealWindow().close();
		}

		g.getRealWindow().print();
	}

	return 0;
}