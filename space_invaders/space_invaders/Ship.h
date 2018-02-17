#pragma once

#include <SFML\Graphics.hpp>

class Ship
{
public:
	Ship();
	~Ship();
public:
	/**
	* \brief Gives the ship position. Const method.
	*
	* \return sf::Vector2i position.
	*/
	sf::Vector2i getPosition() const;
	/**
	* \brief Updates the ship position. Can be outside the screen.
	*
	* \param pos : New ship position.
	*
	* \return sf::Vector2i new position.
	*/
	sf::Vector2i setPosition(const sf::Vector2i &pos);

private:
	sf::Vector2i m_position;
};

