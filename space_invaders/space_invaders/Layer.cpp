#include "Layer.h"
#include "GameWindow.h"


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


	int Layer::print(GameWindow &win)
	{
		for (std::pair<int, sf::Sprite> sp : m_sprites)
		{
			win.draw(sp.second);
		}

		return 0;
	}
}