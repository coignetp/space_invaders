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
	std::map<int, Missile> &getRealMissiles();

private:
	std::map<int, Missile> m_missiles;
};

