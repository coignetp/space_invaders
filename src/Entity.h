#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Hitbox.h"
#include "SpriteManager.h"

namespace graphics {
class GameWindow;
}
namespace physics {
class HitboxManager;
}

class Entity {
 public:
  Entity(physics::HitboxManager &hitboxManager);
  Entity(const Entity &entity);
  ~Entity();

 public:
  /**
   * \brief Gives the entity position. Const method.
   *
   * \return sf::Vector2i position.
   */
  sf::Vector2i getPosition() const;
  /**
   * \brief Updates the entity position. Can be outside the screen.
   *
   * \param pos : New entity position.
   *
   * \return sf::Vector2i new position.
   */
  sf::Vector2i setPosition(const sf::Vector2i &pos);
  /**
   * \brief Gives the entity speed. Const method.
   *
   * \return sf::Vector2f speed.
   */
  sf::Vector2f getSpeed() const;
  /**
   * \brief Updates the entity speed. Can be outside the screen.
   *
   * \param speed : New entity speed.
   *
   * \return sf::Vector2f new position.
   */
  sf::Vector2f setSpeed(const sf::Vector2f &speed);
  /**
   * \brief Updates the entity position.
   *
   * \param dx : Number of pixel crossed (horizontal). Can be negative.
   * \param dy : Number of pixel crossed (vertical). Can be negative.
   *
   * \return sf::Vector2i new position.
   */
  sf::Vector2i move(const int &dx, const int &dy, const sf::Rect<int> &wall);

  /**
   * \brief Gives the entity hitbox. Const method.
   *
   * \return physics::Hitbox entity hitbox.
   */
  std::shared_ptr<physics::Hitbox> getHitbox() const;
  /**
   * \brief Gives a real reference to the hitbox.
   *
   * \return std::shared_ptr<physics::Hitbox>& entity hitbox.
   */
  std::shared_ptr<physics::Hitbox> &getRealHitbox();

  /**
   * \brief Gives the sprite. Const method.
   *
   * \return std::shared_ptr<sf::Sprite>.
   */
  std::shared_ptr<sf::Sprite> getSprite() const;

  /**
   * \brief Gives a real reference to the sprite shared pointer.
   *
   * \return std::shared_ptr<sf::Sprite>& entity sprite pointer.
   */
  std::shared_ptr<sf::Sprite> &getRealSprite();
  /**
   * \brief Gives the hitboxmanager. Const method.
   *
   * \return std::shared_ptr<physics::HitboxManager>.
   */
  physics::HitboxManager &getHitboxManager() const;

  /**
   * \brief Prints the entity on the screen
   *
   * \return int error code
   */
  int print(graphics::GameWindow &win);
  /**
   * \brief Erases the entity on the screen
   *
   * \param win : the window
   *
   * \return int error code
   */
  int erase(graphics::GameWindow &win);
  /**
   * \brief Updates the entity position according to the speed.
   *
   * \param t : time since the last update call
   * \param wall : screen border
   *
   * \return nothing
   */
  virtual void update(const sf::Time &t, const sf::Vector2i &wall,
                      graphics::GameWindow &win,
                      physics::HitboxManager &hitboxManager,
                      const sf::Vector2i &begWall = sf::Vector2i(0, 0));
  /**
   * \brief Cleans the entity attributs.
   *
   * \return nothing
   */
  virtual void clean(std::shared_ptr<graphics::SpriteManager> spManager,
                     graphics::GameWindow &win);

 private:
  sf::Vector2i m_position;
  sf::Vector2f m_speed;
  std::shared_ptr<physics::Hitbox> m_hitbox;
  std::shared_ptr<sf::Sprite> m_sprite;
  sf::Time m_lastUpdate;
  physics::HitboxManager &m_hitboxManager;
};
