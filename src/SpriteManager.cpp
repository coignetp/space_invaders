#include "SpriteManager.h"

namespace graphics {

	SpriteManager::SpriteManager()
	{
	}


	SpriteManager::~SpriteManager()
	{
	}

	std::map<int, std::shared_ptr<sf::Sprite>> &SpriteManager::getRealSprites()
	{
		return m_sprites;
	}
}