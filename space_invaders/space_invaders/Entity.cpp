#include "Entity.h"
#include "GameWindow.h"
#include "Layer.h"


Entity::Entity() :
	m_position(0, 0),
	m_lastUpdate()
{
}


Entity::~Entity()
{
}


sf::Vector2i Entity::getPosition() const
{
	return m_position;
}


sf::Vector2i Entity::setPosition(const sf::Vector2i &pos)
{
	m_position = pos;

	m_hitbox.getRealRect().left = pos.x;
	m_hitbox.getRealRect().top = pos.y;

	m_sprite->setPosition(sf::Vector2f(pos));

	return m_position;
}


sf::Vector2f Entity::getSpeed() const
{
	return m_speed;
}


sf::Vector2f Entity::setSpeed(const sf::Vector2f &speed)
{
	m_speed = speed;

	return m_speed;
}


sf::Vector2i Entity::move(const int &dx, const int &dy, const sf::Vector2i &wall)
{
	if ((wall.x == -1 && wall.y == -1)
		|| (m_hitbox.getRealRect().left + dx >= 0
			&& m_hitbox.getRealRect().left + m_hitbox.getRealRect().width + dx <= wall.x
			&& m_hitbox.getRealRect().top + dy >= 0
			&& m_hitbox.getRealRect().top + m_hitbox.getRealRect().height + dy <= wall.y))
	{
		m_position.x += dx;
		m_position.y += dy;

		m_hitbox.getRealRect().left += dx;
		m_hitbox.getRealRect().top += dy;

		getRealSprite()->setPosition(sf::Vector2f(getPosition()));
	}

	return m_position;
}


physics::Hitbox Entity::getHitbox() const
{
	return m_hitbox;
}


physics::Hitbox &Entity::getRealHitbox()
{
	return m_hitbox;
}


std::shared_ptr<sf::Sprite> &Entity::getRealSprite()
{
	return m_sprite;
}


int Entity::print(graphics::GameWindow &win)
{
	getRealSprite()->setPosition(sf::Vector2f(getPosition()));
	win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->addSprite(m_hitbox.getId());

	return 0;
}


int Entity::erase(graphics::GameWindow &win)
{
	/*win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().erase(
		std::remove(
			win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().begin(),
			win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().end(), 
			m_hitbox.getId()), 
		win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().end()
	);*/
	/*std::deque<int>::iterator it(win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().begin());
	while (it != win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().end())
	*/

	for(unsigned int i(0) ; i < win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().size(); i++)
	{
		if (win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites()[i] == m_hitbox.getId())
		{
			win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().erase(
				win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().begin() + i
			);
		}
	}

	/*win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites()[1] = 3;
	win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->addSprite(0);*/

	return -1;
}


void Entity::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win, const sf::Vector2i &begWall)
{
	if (m_speed.x != 0 || m_speed.y != 0)
		m_lastUpdate += t;
	if (m_lastUpdate.asSeconds()*m_speed.x >= 1 || m_lastUpdate.asSeconds()*m_speed.y >= 1
		|| m_lastUpdate.asSeconds()*m_speed.x <= -1 || m_lastUpdate.asSeconds()*m_speed.y <= -1)
	{
		move((int)(m_lastUpdate.asSeconds()*m_speed.x), (int)(m_lastUpdate.asSeconds()*m_speed.y), wall);
		m_lastUpdate = sf::Time();
	}
}