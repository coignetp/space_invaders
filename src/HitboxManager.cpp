#include "HitboxManager.h"


namespace physics {
	HitboxManager::HitboxManager()
	{
	}


	HitboxManager::~HitboxManager()
	{
	}

	std::deque<std::shared_ptr<Hitbox>> &HitboxManager::getRealHitboxes()
	{
		return m_hitboxes;
	}

	bool HitboxManager::areColliding(const Hitbox &h1, const Hitbox &h2) const
	{
		if (h1.getId() == h2.getId())
			return false;

		return h1.getRect().intersects(h2.getRect());
	}

	bool HitboxManager::isColliding(const Hitbox &h) const
	{
		for (const std::shared_ptr<Hitbox> h2 : m_hitboxes)
		{
			if (areColliding(h, *h2))
				return true;
		}

		return false;
	}
}