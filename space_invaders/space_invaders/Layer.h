#pragma once

#include <map>
#include <SFML\Graphics.hpp>

namespace graphics {

	class Layer
	{
	public:
		Layer();
		~Layer();
	public:
		/**
		* \brief Real reference of the sprites map.
		*
		* \return the real sprites.
		*/
		std::map<int, sf::Sprite> getRealSprites();

	private:
		std::map<int, sf::Sprite> m_sprites;
	};

}