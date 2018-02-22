#include "Enemi.h"



Enemi::Enemi(const sf::Rect<int> &walls) :
	m_walls(walls)
{
}


Enemi::~Enemi()
{
}


sf::Rect<int> Enemi::getWalls() const
{
	return m_walls;
}


sf::Rect<int> Enemi::setWalls(const sf::Rect<int> &walls)
{
	m_walls = walls;

	return walls;
}