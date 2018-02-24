#include "Ship.h"
#include "GameWindow.h"


extern int MISSILE_ID;

Ship::Ship() :
	Entity(),
	m_rateOfFire(0),
	m_missileSpeed(0)
{
}


Ship::~Ship()
{
}


std::map<int, std::shared_ptr<Missile>> &Ship::getRealMissiles()
{
	return m_missiles;
}


float Ship::getRateOfFire() const
{
	return m_rateOfFire;
}


float Ship::setRateOfFire(const float &rate)
{
	if (rate < 0)
		return m_rateOfFire;
	m_rateOfFire = rate;

	return m_rateOfFire;
}


void Ship::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win, const sf::Vector2i &begWall)
{
	Entity::update(t, wall, win, begWall);
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
		getRealMissiles().at(MISSILE_ID)->setSpeed(sf::Vector2f(0.0, m_missileSpeed));
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