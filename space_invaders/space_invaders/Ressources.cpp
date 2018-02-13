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
		return 0;
	}
}