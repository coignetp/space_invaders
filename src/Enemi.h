#pragma once
#include "Ship.h"

class Enemi : public Ship {
 public:
  Enemi(physics::HitboxManager &hitboxManager, const sf::Rect<int> &walls,
        graphics::GameWindow &win);
  ~Enemi();

 public:
  /**
   * \brief Gives the walls of this enemi
   *
   * \return sf::Rect<int> walls
   */
  sf::Rect<int> getWalls() const;
  /**
   * \brief Changes the walls
   *
   * \param wall : new walls
   *
   * \return sf::Rect<int> new walls
   */
  sf::Rect<int> setWalls(const sf::Rect<int> &walls);
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

 private:
  sf::Rect<int> m_walls;
};
