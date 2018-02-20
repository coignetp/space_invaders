#pragma once
#include "Entity.h"


class Missile :
	public Entity
{
public:
	Missile(graphics::GameWindow &win, const sf::Vector2i &pos);
	~Missile();
};

