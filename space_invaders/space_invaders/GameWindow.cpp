#include "GameWindow.h"

#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>


namespace graphics {
	GameWindow::GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings) :
		sf::RenderWindow(vid, title, style, settings)
	{

	}
}