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
	/**
	* \brief Updates the ship position.
	*
	* \param dx : Number of pixel crossed (horizontal). Can be negative.
	* \param dy : Number of pixel crossed (vertical). Can be negative.
	*
	* \return sf::Vector2i new position.
	*/
	sf::Vector2i move(const int &dx, const int &dy);

private:
	sf::Vector2i m_position;
};

