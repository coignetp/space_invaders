#pragma once
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

namespace graphics {

	class GameWindow :
		public sf::RenderWindow
	{
	public:
		GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
	};

}