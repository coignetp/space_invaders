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
		std::vector<std::string> filenames{ "data/bg.jpg", "data/me.png", "data/enemi.png" };

		try {
			for (unsigned int i(0); i < filenames.size(); i++)
			{
				std::shared_ptr<sf::Texture> textu = std::make_shared<sf::Texture>();
				if (!textu->loadFromFile(filenames[i]))
					return -1;
				m_textures.insert(std::make_pair(i, textu));
			}
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}

		return 0;
	}
}