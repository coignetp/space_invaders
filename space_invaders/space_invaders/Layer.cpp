#include "Layer.h"


namespace graphics {

	Layer::Layer()
	{
	}


	Layer::~Layer()
	{
	}


	std::map<int, sf::Sprite> Layer::getRealSprites()
	{
		return m_sprites;
	}
}