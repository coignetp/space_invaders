#include "Hitbox.h"


namespace physics {
	Hitbox::Hitbox()
	{
	}


	Hitbox::~Hitbox()
	{
	}

	sf::Rect<int> Hitbox::getRealRect()
	{
		return m_rect;
	}
}