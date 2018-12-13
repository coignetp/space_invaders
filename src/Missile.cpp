#include "Missile.h"
#include "GameWindow.h"

int MISSILE_ID(0);

Missile::Missile(physics::HitboxManager &hitboxManager,
                 graphics::GameWindow &win, const sf::Vector2i &pos)
    : Entity(hitboxManager), m_id(MISSILE_ID++), m_toDelete(false) {
  this->getRealSprite() = std::make_shared<sf::Sprite>(sf::Sprite(
      *win.getRealRessources().getRealTextures()[graphics::RESS_MISSILE]));
  win.getRealSpriteManager().getRealSprites().insert(
      std::make_pair(getHitbox()->getId(), this->getRealSprite()));

  setPosition(pos);

  // Initiate the hitbox
  getRealHitbox()->getRealRect() =
      sf::Rect<int>(getPosition().x, getPosition().y,
                    (int)getRealSprite()->getLocalBounds().width,
                    (int)getRealSprite()->getLocalBounds().height);

  print(win);
}

Missile::Missile(const Missile &miss) : Entity(miss) { m_id = miss.getId(); }

Missile::~Missile() {}

bool Missile::getToDelete() const { return m_toDelete; }

int Missile::getId() const { return m_id; }

void Missile::update(const sf::Time &t, const sf::Vector2i &wall,
                     graphics::GameWindow &win,
                     physics::HitboxManager &hitboxManager,
                     const sf::Vector2i &begWall) {
  Entity::update(t, wall, win, hitboxManager, begWall);

  if (getPosition().y <= 0 ||
      getPosition().y + getHitbox()->getRect().height >= 800)
    m_toDelete = true;
}