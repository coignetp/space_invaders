#include <memory>
#include "Character.h"
#include "GameWindow.h"


extern int MISSILE_ID;

Character::Character(graphics::GameWindow &win) :
	m_rateOfFire(0)
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


float Character::getRateOfFire() const
{
	return m_rateOfFire;
}


float Character::setRateOfFire(const float &rate)
{
	if (rate < 0)
		return m_rateOfFire;
	m_rateOfFire = rate;

	return m_rateOfFire;
}


void Character::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win)
{
	Entity::update(t, wall, win);
	if (m_rateOfFire != 0)
		m_lastUpdateMissile += t;

	if (m_lastUpdateMissile.asSeconds()*m_rateOfFire >= 1)
	{
		getRealMissiles().insert(std::make_pair(
			MISSILE_ID, std::make_shared<Missile>(Missile(win, sf::Vector2i(
				getPosition().x + (int)(getRealSprite()->getLocalBounds().width / 2),
				getPosition().y + 3
			))))
		);
		getRealMissiles().at(MISSILE_ID)->setSpeed(sf::Vector2f(0.0, -800.0));
		m_lastUpdateMissile = sf::Time();
	}

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