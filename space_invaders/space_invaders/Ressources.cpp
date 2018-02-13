#include "Ressources.h"


namespace graphics {
	Ressources::Ressources()
	{
	}


	Ressources::~Ressources()
	{
	}

	std::map<int, sf::Texture>& Ressources::getRealTextures()
	{
		return m_textures;
	}
}