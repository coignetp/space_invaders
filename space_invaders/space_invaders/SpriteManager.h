#pragma once

#include <map>
#include <SFML\Graphics.hpp>

namespace graphics {
	class SpriteManager
	{
	public:
		SpriteManager();
		~SpriteManager();

	private:
		std::map<int, sf::Sprite> m_sprites;
	};
}
