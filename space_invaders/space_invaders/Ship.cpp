#include "Ship.h"



Ship::Ship()
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

	return m_position;
}