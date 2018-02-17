#pragma once

#include <map>
#include <SFML\Graphics.hpp>

namespace graphics {

	class GameWindow;

	class Layer
	{
	public:
		Layer();
		~Layer();
	public:
		/**
		* \brief Real reference of the sprites map.
		*
		* \return the real sprites.
		*/
		std::map<int, sf::Sprite> getRealSprites();

		/**
		* \brief Print the different sprites of the layer
		*
		* \param win : the main window
		*
		* \return an error code.
		*/
		int print(GameWindow &win);

	private:
		std::map<int, sf::Sprite> m_sprites;
	};

}