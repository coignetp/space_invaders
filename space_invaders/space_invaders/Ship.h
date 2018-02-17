#pragma once

#include <memory>
#include <SFML\Graphics.hpp>
#include "Hitbox.h"

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

	/**
	* \brief Gives the ship hitbox. Const method.
	*
	* \return physics::Hitbox ship hitbox.
	*/
	physics::Hitbox getHitbox() const;
	/**
	* \brief Gives a real reference to the hitbox.
	*
	* \return physics::Hitbox&  ship hitbox.
	*/
	physics::Hitbox &getRealHitbox();

	/**
	* \brief Gives a real reference to the sprite shared pointer.
	*
	* \return std::shared_ptr<sf::Sprite>& ship sprite pointer.
	*/
	std::shared_ptr<sf::Sprite> &getRealSprite();

private:
	sf::Vector2i m_position;
	physics::Hitbox m_hitbox;
	std::shared_ptr<sf::Sprite> m_sprite;
};

