#include "Entity.h"
#include "GameWindow.h"
#include "Layer.h"
#include "HitboxManager.h"

#include <iostream>

Entity::Entity(physics::HitboxManager &hitboxManager) :
	m_position(0, 0),
	m_lastUpdate(),
	m_hitboxManager(std::make_shared<physics::HitboxManager>(hitboxManager)),
	m_hitbox(std::make_shared<physics::Hitbox>())
{
	std::cout << "New : " << m_hitbox->getId() << "\n";
	hitboxManager.getRealHitboxes().push_back(m_hitbox);
}


Entity::Entity(const Entity &entity)
{
	m_position = entity.getPosition();
	m_hitbox = entity.getHitbox();
	m_speed = entity.getSpeed();
	m_sprite = entity.getSprite();
	m_hitboxManager = entity.getHitboxManager();
}


Entity::~Entity()
{
	std::cout << "Old : " << m_hitbox->getId() << "\n";
	/*for (std::deque<std::shared_ptr<physics::Hitbox>>::iterator it = m_hitboxManager->getRealHitboxes().begin();
		it != m_hitboxManager->getRealHitboxes().end(); ++it)
		if ((*it)->getId() == m_hitbox->getId())
			m_hitboxManager->getRealHitboxes().erase(it);*/
}


sf::Vector2i Entity::getPosition() const
{
	return m_position;
}


sf::Vector2i Entity::setPosition(const sf::Vector2i &pos)
{
	m_position = pos;

	m_hitbox->getRealRect().left = pos.x;
	m_hitbox->getRealRect().top = pos.y;

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


sf::Vector2i Entity::move(const int &dx, const int &dy, const sf::Rect<int> &wall)
{
	if ((wall.left == -1 && wall.top == -1)
		|| (m_hitbox->getRealRect().left + dx >= wall.left
			&& m_hitbox->getRealRect().left + m_hitbox->getRealRect().width + dx <= wall.left + wall.width
			&& m_hitbox->getRealRect().top + dy >= wall.top
			&& m_hitbox->getRealRect().top + m_hitbox->getRealRect().height + dy <= wall.top + wall.height))
	{
		m_position.x += dx;
		m_position.y += dy;

		m_hitbox->getRealRect().left += dx;
		m_hitbox->getRealRect().top += dy;

	}
	else
	{
		int gapX = m_position.x - m_hitbox->getRealRect().left;
		int gapY = m_position.y - m_hitbox->getRealRect().top;
		if (m_hitbox->getRealRect().left + dx < wall.left && dx < 0)
		{
			m_hitbox->getRealRect().left = wall.left;
			m_position.x = m_hitbox->getRealRect().left + gapX;
		}
		if (m_hitbox->getRealRect().left + m_hitbox->getRealRect().width + dx > wall.left + wall.width && dx > 0)
		{
			//m_position.x += (wall.left + wall.width -m_hitbox->getRealRect().width - m_hitbox->getRealRect().left);
			m_hitbox->getRealRect().left = wall.left + wall.width - m_hitbox->getRealRect().width;
			m_position.x = m_hitbox->getRealRect().left + gapX;
		}

		if (m_hitbox->getRealRect().top + dy < wall.top && dy < 0)
		{
			//m_position.y -= (m_hitbox->getRealRect().top - wall.top);
			m_hitbox->getRealRect().top = wall.top;
			m_position.y = m_hitbox->getRealRect().top + gapY;
		}
		if (m_hitbox->getRealRect().top + m_hitbox->getRealRect().height + dy > wall.top + wall.height && dy > 0)
		{
			//m_position.y += (wall.top + wall.height - m_hitbox->getRealRect().height - m_hitbox->getRealRect().top);
			m_hitbox->getRealRect().top = wall.top + wall.height - m_hitbox->getRealRect().height;
			m_position.y = m_hitbox->getRealRect().top + gapY;
		}
	
	}
	getRealSprite()->setPosition(sf::Vector2f(getPosition()));

	return m_position;
}


std::shared_ptr<physics::Hitbox> Entity::getHitbox() const
{
	return m_hitbox;
}


std::shared_ptr<physics::Hitbox> &Entity::getRealHitbox()
{
	return m_hitbox;
}


std::shared_ptr<sf::Sprite> Entity::getSprite() const
{
	return m_sprite;
}


std::shared_ptr<sf::Sprite> &Entity::getRealSprite()
{
	return m_sprite;
}


std::shared_ptr<physics::HitboxManager> Entity::getHitboxManager() const
{
	return m_hitboxManager;
}


int Entity::print(graphics::GameWindow &win)
{
	getRealSprite()->setPosition(sf::Vector2f(getPosition()));
	win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->addSprite(m_hitbox->getId());

	return 0;
}


int Entity::erase(graphics::GameWindow &win)
{
	/*win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().erase(
		std::remove(
			win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().begin(),
			win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().end(), 
			m_hitbox->getId()), 
		win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().end()
	);*/
	/*std::deque<int>::iterator it(win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().begin());
	while (it != win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().end())
	*/

	for(unsigned int i(0) ; i < win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites().size(); i++)
	{
		if (win.getRealLayers()[graphics::WINDOW_LAYER_ITEM]->getRealSprites()[i] == m_hitbox->getId())
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


void Entity::update(const sf::Time &t, const sf::Vector2i &wall, graphics::GameWindow &win, physics::HitboxManager &hitboxManager, const sf::Vector2i &begWall)
{
	if (m_speed.x != 0 || m_speed.y != 0)
		m_lastUpdate += t;
	if (m_lastUpdate.asSeconds()*m_speed.x >= 1 || m_lastUpdate.asSeconds()*m_speed.y >= 1
		|| m_lastUpdate.asSeconds()*m_speed.x <= -1 || m_lastUpdate.asSeconds()*m_speed.y <= -1)
	{
		move((int)(m_lastUpdate.asSeconds()*m_speed.x), (int)(m_lastUpdate.asSeconds()*m_speed.y), 
			sf::Rect<int>(begWall.x, begWall.y, wall.x, wall.y));
		m_lastUpdate = sf::Time();
	}
}


void Entity::clean(std::shared_ptr<graphics::SpriteManager> spManager)
{
	// Clean the sprite
	spManager->getRealSprites().erase(spManager->getRealSprites().find(m_hitbox->getId()));

	// Clean the hitbox
	for (std::deque<std::shared_ptr<physics::Hitbox>>::iterator it(m_hitboxManager->getRealHitboxes().begin());
		it != m_hitboxManager->getRealHitboxes().end(); it++)
	{
		if ((*it)->getId() == m_hitbox->getId())
			it = m_hitboxManager->getRealHitboxes().erase(it);
	}
	std::cout << m_hitbox.use_count() << std::endl;
	m_hitbox.reset();
}