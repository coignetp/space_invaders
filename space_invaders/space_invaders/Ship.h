#pragma once

#include <memory>
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Missile.h"

class Ship :
	public Entity
{
public:
	Ship(physics::HitboxManager &hitboxManager);
	~Ship();
public:
	/**
	* \brief Gives the real missiles
	*
	* \return std::map<int, Missile> missiles
	*/
	std::map<int, std::shared_ptr<Missile>> &getRealMissiles();
	/**
	* \brief Gives the rate of fire of the character (missile per second)
	*
	* \return float rateOfFire
	*/
	float getRateOfFire() const;
	/**
	* \brief Changes the rate of fire of the character (missile per second)
	*
	* \param rate : new rate of fire
	*
	* \return float new rateOfFire
	*/
	float setRateOfFire(const float &rate);
	/**
	* \brief Updates the entity position according to the speed.
	*
	* \param t : time since the last update call
	* \param wall : screen border
	*
	* \return nothing
	*/
	virtual void update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win, physics::HitboxManager &hitboxManager, const sf::Vector2i &begWall = sf::Vector2i(0, 0));

protected:
	float m_missileSpeed;

private:
	std::map<int, std::shared_ptr<Missile>> m_missiles;
	float m_rateOfFire;
	sf::Time m_lastUpdateMissile;
};

