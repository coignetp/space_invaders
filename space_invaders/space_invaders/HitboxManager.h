#pragma once

#include <deque>
#include "Hitbox.h"

namespace physics {
	class HitboxManager
	{
	public:
		HitboxManager();
		~HitboxManager();
	public:
		/**
		* \brief Gives the real deque of hitboxes. T
		*
		* \return std::deque<Hitbox> hitboxes.
		*/
		std::deque<Hitbox> &getRealHitboxes();

	private:
		std::deque<Hitbox> m_hitboxes;
	};

}