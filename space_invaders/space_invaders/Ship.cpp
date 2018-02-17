#include "Ship.h"
#include "GameWindow.h"


Ship::Ship() :
	m_position(0, 0)
{
}


Ship::~Ship()
{
}


sf::Vector2i Ship::getPosition() const
{
	return m_position;
}


sf::Vector2i Ship::setPosition(const sf::Vector2i &pos)
{
	m_position = pos;

	return m_position;
}


sf::Vector2i Ship::move(const int &dx, const int &dy)
{
	m_position.x += dx;
	m_position.y += dy;

	getRealSprite()->setPosition(sf::Vector2f(getPosition()));

	return m_position;
}


physics::Hitbox Ship::getHitbox() const
{
	return m_hitbox;
}


physics::Hitbox &Ship::getRealHitbox()
{
	return m_hitbox;
}


std::shared_ptr<sf::Sprite> &Ship::getRealSprite()
{
	return m_sprite;
}


int Ship::print(graphics::GameWindow &win)
{
	getRealSprite()->setPosition(sf::Vector2f(getPosition()));
	win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->addSprite(m_hitbox.getId());

	return 0;
}