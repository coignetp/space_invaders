#include "Layer.h"
#include "GameWindow.h"


namespace graphics {

	Layer::Layer()
	{
	}


	Layer::~Layer()
	{
	}


	std::deque<int> Layer::getRealSprites()
	{
		return m_sprites;
	}


	int Layer::print(GameWindow &win)
	{
		for (int sp : m_sprites)
		{
			win.draw(*win.getRealSpriteManager().getRealSprites()[sp]);
		}

		return 0;
	}

	void Layer::addSprite(const int &id)
	{
		m_sprites.push_back(id);
	}
}