#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

namespace graphics {

	class GameWindow :
		public sf::RenderWindow
	{
	public:
		GameWindow();
		~GameWindow();
	};

}