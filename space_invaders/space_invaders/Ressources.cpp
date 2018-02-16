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
		std::vector<std::shared_ptr<sf::Texture> > textu(3, std::make_shared<sf::Texture>());

		try {
			if (!textu.at(0)->loadFromFile("data/bg.jpg"))
				return -1;
			m_textures.insert(std::make_pair(1, textu.at(0)));

			if (!textu.at(1)->loadFromFile("data/me.png"))
				return -1;
			m_textures.insert(std::make_pair(2, textu.at(1)));

			if (!textu.at(1)->loadFromFile("data/enemi.png"))
				return -1;
			m_textures.insert(std::make_pair(3, textu.at(2)));
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}

		return 0;
	}
}