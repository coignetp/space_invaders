#include "Ressources.h"


namespace graphics {
	Ressources::Ressources()
	{
		load();
	}


	Ressources::~Ressources()
	{
	}

	std::map<int, sf::Texture>& Ressources::getRealTextures()
	{
		return m_textures;
	}

	int Ressources::load()
	{
		sf::Texture textu;

		if (!textu.loadFromFile("data/bg.png"))
			return -1;
		m_textures.insert(std::make_pair(1, textu));

		if (!textu.loadFromFile("data/me.png"))
			return -1;
		m_textures.insert(std::make_pair(2, textu));

		if (!textu.loadFromFile("data/enemi.jpg"))
			return -1;
		m_textures.insert(std::make_pair(3, textu));

		return 0;
	}
}