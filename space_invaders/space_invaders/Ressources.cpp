#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ressources.h"


namespace graphics {
	Ressources::Ressources()
	{
		load();
	}


	Ressources::~Ressources()
	{
	}

	std::map<int, std::shared_ptr<sf::Texture> >& Ressources::getRealTextures()
	{
		return m_textures;
	}

	int Ressources::load()
	{
		std::vector<std::shared_ptr<sf::Texture> > textu(RESS_TOTAL, std::make_shared<sf::Texture>());

		try {
			if (!textu.at(RESS_BACKGROUND)->loadFromFile("data/bg.jpg"))
				return -1;
			m_textures.insert(std::make_pair(RESS_BACKGROUND, textu.at(RESS_BACKGROUND)));

			if (!textu.at(1)->loadFromFile("data/me.png"))
				return -1;
			m_textures.insert(std::make_pair(RESS_ME, textu.at(RESS_ME)));

			if (!textu.at(1)->loadFromFile("data/enemi.png"))
				return -1;
			m_textures.insert(std::make_pair(RESS_ENEMI, textu.at(RESS_ENEMI)));
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}

		return 0;
	}
}