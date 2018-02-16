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
}