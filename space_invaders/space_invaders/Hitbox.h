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
		* \brief Gives the hitbox. The position depends
		* on the screen.
		*
		* \return sf::Rect<int> hitbox.
		*/
		sf::Rect<int> getRect() const;
		/**
		* \brief Gives the real hitbox. The position depends
		* on the screen.
		*
		* \return sf::Rect<int>& hitbox.
		*/
		sf::Rect<int> &getRealRect();
		/**
		* \brief Gives the unique hitbox id.
		*
		* \return int id.
		*/
		int getId() const;

	private:
		int m_id;
		sf::Rect<int> m_rect;
	};

}