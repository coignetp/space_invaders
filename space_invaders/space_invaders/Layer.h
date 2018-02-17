#pragma once

#include <deque>
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
		std::deque<int> getRealSprites();

		/**
		* \brief Print the different sprites of the layer
		*
		* \param win : the main window
		*
		* \return an error code.
		*/
		int print(GameWindow &win);

	private:
		std::deque<int> m_sprites;
	};

}