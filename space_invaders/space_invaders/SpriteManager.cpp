#include "SpriteManager.h"

namespace graphics {

	SpriteManager::SpriteManager()
	{
	}


	SpriteManager::~SpriteManager()
	{
	}

	std::map<int, sf::Sprite> &SpriteManager::getRealSprites()
	{
		return m_sprites;
	}
}