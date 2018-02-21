#include <memory>
#include "Character.h"
#include "GameWindow.h"


Character::Character(graphics::GameWindow &win)
{
	this->getRealSprite() = std::make_shared<sf::Sprite>(
		sf::Sprite(*win.getRealRessources().getRealTextures()[graphics::RESS_ME])
	);
	win.getRealSpriteManager().getRealSprites().insert(std::make_pair(
		getHitbox().getId(),
		this->getRealSprite()
	));

	setPosition(sf::Vector2i(
		(int)(win.getSize().x - getRealSprite()->getLocalBounds().width) / 2,
		(int)(win.getSize().y - getRealSprite()->getLocalBounds().height)
	));

	// Initiate the hitbox
	getRealHitbox().getRealRect() = sf::Rect<int>(
		(int)(getPosition().x + getRealSprite()->getLocalBounds().width/4),
		(int)getPosition().y,
		(int)getRealSprite()->getLocalBounds().width / 2,
		(int)getRealSprite()->getLocalBounds().height
	);
}


Character::~Character()
{
}


std::map<int, std::shared_ptr<Missile>> &Character::getRealMissiles()
{
	return m_missiles;
}


void Character::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win)
{
	Entity::update(t, wall, win);
	std::map<int, std::shared_ptr<Missile>>::iterator it(m_missiles.begin());

	while (it != m_missiles.end())
	{
		it->second->update(t, wall, win);

		if (it->second->getToDelete())
		{
			it->second->erase(win);
			it = m_missiles.erase(it);
		}
		else
			++it;
	}
}