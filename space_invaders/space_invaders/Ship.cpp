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