#pragma once

#include <SFML\Graphics.hpp>

namespace physics {
	class Hitbox
	{
	public:
		Hitbox();
		~Hitbox();

	public:
		/**
		* \brief Gives the real hitbox. The position depends
		* on the screen.
		*
		* \return sf::Rect<int> hitbox.
		*/
		sf::Rect<int> getRealRect();

	private:
		sf::Rect<int> m_rect;
	};

}