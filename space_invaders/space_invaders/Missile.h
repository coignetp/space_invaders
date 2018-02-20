#pragma once
#include "Entity.h"


class Missile :
	public Entity
{
public:
	Missile(graphics::GameWindow &win, const sf::Vector2i &pos);
	~Missile();

public:
	/**
	* \brief Tells if the missile need to be deleted
	*
	* \return True if it needs to be deleted
	*/
	bool getToDelete() const;
	/**
	* \brief Gives the unique missile id.
	*
	* \return int id.
	*/
	int getId() const;
	/**
	* \brief Updates the entity position according to the speed.
	*
	* \param t : time since the last update call
	* \param wall : screen border
	*
	* \return nothing
	*/
	virtual void update(const sf::Time &t, const sf::Vector2i &wall);

private:
	bool m_toDelete;
	int m_id;
};

