#include "HitboxManager.h"


namespace physics {
	HitboxManager::HitboxManager()
	{
	}


	HitboxManager::~HitboxManager()
	{
	}

	std::deque<Hitbox> &HitboxManager::getRealHitboxes()
	{
		return m_hitboxes;
	}

	bool HitboxManager::areColliding(const Hitbox &h1, const Hitbox &h2)
	{
		if (h1.getId() == h2.getId())
			return false;

		return h1.getRect().intersects(h2.getRect());
	}
}