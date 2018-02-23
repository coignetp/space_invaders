#include "Enemi.h"
#include "GameWindow.h"
#include <random>


Enemi::Enemi(const sf::Rect<int> &walls, graphics::GameWindow &win) :
	m_walls(walls)
{
	this->getRealSprite() = std::make_shared<sf::Sprite>(
		sf::Sprite(*win.getRealRessources().getRealTextures()[graphics::RESS_ENEMI])
	);
	win.getRealSpriteManager().getRealSprites().insert(std::make_pair(
		getHitbox().getId(),
		this->getRealSprite()
	));

	setPosition(sf::Vector2i(
		walls.left,
		walls.top
	));

	setRateOfFire(10.0);

	// Initiate the hitbox
	getRealHitbox().getRealRect() = sf::Rect<int>(
		(int)walls.left,
		(int)walls.top,
		(int)walls.width,
		(int)walls.height
	);
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


void Enemi::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win, const sf::Vector2i &begWall)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 1000);

	Ship::update(t+sf::microseconds(distribution(generator)), wall, win, begWall);
}