#include "Hitbox.h"

int NextID(0);

namespace physics {
	Hitbox::Hitbox() :
		m_id(NextID++)
	{
	}


	Hitbox::~Hitbox()
	{
	}

	sf::Rect<int> Hitbox::getRealRect()
	{
		return m_rect;
	}

	int Hitbox::getId() const
	{
		return m_id;
	}
}