#include "Hitbox.h"

int NextID(0);

namespace physics {
Hitbox::Hitbox() : m_id(NextID++) {}

Hitbox::Hitbox(const Hitbox& hb) {
  m_id = hb.getId();
  m_rect = hb.getRect();
}

Hitbox::~Hitbox() {}

sf::Rect<int> Hitbox::getRect() const { return m_rect; }

sf::Rect<int>& Hitbox::getRealRect() { return m_rect; }

int Hitbox::getId() const { return m_id; }
}  // namespace physics