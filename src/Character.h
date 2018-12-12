#pragma once

#include "Ship.h"
#include "Missile.h"

class graphics::GameWindow;

class Character :
	public Ship
{
public:
	Character(physics::HitboxManager &hitboxManager, graphics::GameWindow &win);
	~Character();
};

