#pragma once

#include <deque>
#include <memory>
#include "Hitbox.h"

namespace physics {
class HitboxManager {
 public:
  HitboxManager();
  ~HitboxManager();

 public:
  /**
   * \brief Gives the real deque of hitboxes.
   *
   * \return std::deque<Hitbox> hitboxes.
   */
  std::deque<std::shared_ptr<Hitbox>> &getRealHitboxes();
  /**
   * \brief Tells if 2 hitboxes are colliding. If the 2
   * hitboxes have the same id it returns false.
   *
   * \return true if they collide.
   */
  bool areColliding(const Hitbox &h1, const Hitbox &h2) const;
  /**
   * \brief Tells if a hitboxe is colliding with others.
   *
   * \return true if it collides.
   */
  bool isColliding(const Hitbox &h) const;

 private:
  std::deque<std::shared_ptr<Hitbox>> m_hitboxes;
};

}  // namespace physics