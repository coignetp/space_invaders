#pragma once

#include <map>
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
		std::map<int, sf::Sprite> &getRealSprites();

	private:
		std::map<int, sf::Sprite> m_sprites;
	};
}
