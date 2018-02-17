#pragma once

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>

namespace graphics {
	class SpriteManager
	{
	public:
		SpriteManager();
		~SpriteManager();

	public:
		/**
		* \brief Gives the real sprites map
		*
		* \return std::map<int, sf::Sprite> sprites map
		*/
		std::map<int, std::shared_ptr<sf::Sprite>> &getRealSprites();

	private:
		std::map<int, std::shared_ptr<sf::Sprite>> m_sprites;
	};
}
