#pragma once

#include "Ship.h"
#include "Missile.h"

class graphics::GameWindow;

class Character :
	public Ship
{
public:
	Character(graphics::GameWindow &win);
	~Character();

public:
	/**
	* \brief Gives the real missiles
	*
	* \return std::map<int, Missile> missiles
	*/
	std::map<int, std::shared_ptr<Missile>> &getRealMissiles();
	/**
	* \brief Updates the entity position according to the speed.
	*
	* \param t : time since the last update call
	* \param wall : screen border
	*
	* \return nothing
	*/
	virtual void update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win);

private:
	std::map<int, std::shared_ptr<Missile>> m_missiles;
};

