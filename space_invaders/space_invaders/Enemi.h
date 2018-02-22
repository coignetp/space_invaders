#pragma once
#include "Ship.h"


class Enemi :
	public Ship
{
public:
	Enemi(const sf::Rect<int> &walls);
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
private:
	sf::Rect<int> m_walls;
};

