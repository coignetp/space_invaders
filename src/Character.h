#pragma once

#include "Missile.h"
#include "Ship.h"

class graphics::GameWindow;

class Character : public Ship {
 public:
  Character(physics::HitboxManager &hitboxManager, graphics::GameWindow &win);
  ~Character();
};
