#pragma once

#include <memory>
#include <SFML\Graphics.hpp>
#include "Hitbox.h"

namespace graphics { class GameWindow;  }

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
	* \brief Gives the ship speed. Const method.
	*
	* \return sf::Vector2f speed.
	*/
	sf::Vector2f getSpeed() const;
	/**
	* \brief Updates the ship speed. Can be outside the screen.
	*
	* \param speed : New ship speed.
	*
	* \return sf::Vector2f new position.
	*/
	sf::Vector2f setSpeed(const sf::Vector2f &speed);
	/**
	* \brief Updates the ship position.
	*
	* \param dx : Number of pixel crossed (horizontal). Can be negative.
	* \param dy : Number of pixel crossed (vertical). Can be negative.
	*
	* \return sf::Vector2i new position.
	*/
	sf::Vector2i move(const int &dx, const int &dy, const sf::Vector2i &wall);

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

	/**
	* \brief Prints the ship on the screen
	*
	* \return int error code
	*/
	int print(graphics::GameWindow &win);
	/**
	* \brief Updates the ship position according to the speed.
	* 
	* \param t : time since the last update call
	* \param wall : screen border
	*
	* \return nothing
	*/
	void update(const sf::Time &t, const sf::Vector2i &wall);

private:
	sf::Vector2i m_position;
	sf::Vector2f m_speed;
	physics::Hitbox m_hitbox;
	std::shared_ptr<sf::Sprite> m_sprite;
	sf::Time m_lastUpdate;
};

