#include "Missile.h"
#include "GameWindow.h"

int MISSILE_ID(0);

Missile::Missile(graphics::GameWindow &win, const sf::Vector2i &pos) :
	m_id(MISSILE_ID++),
	m_toDelete(false)
{
	this->getRealSprite() = std::make_shared<sf::Sprite>(
		sf::Sprite(*win.getRealRessources().getRealTextures()[graphics::RESS_MISSILE])
		);
	win.getRealSpriteManager().getRealSprites().insert(std::make_pair(
		getHitbox().getId(),
		this->getRealSprite()
	));

	setPosition(pos);

	// Initiate the hitbox
	getRealHitbox().getRealRect() = sf::Rect<int>(
		getPosition().x,
		getPosition().y,
		(int)getRealSprite()->getLocalBounds().width,
		(int)getRealSprite()->getLocalBounds().height
	);

	print(win);
}


Missile::~Missile()
{
}


bool Missile::getToDelete() const
{
	return m_toDelete;
}


int Missile::getId() const
{
	return m_id;
}


void Missile::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win, const sf::Vector2i &begWall)
{
	Entity::update(t, wall, win, begWall);

	if (getPosition().y <= 32)
		m_toDelete = true;
}