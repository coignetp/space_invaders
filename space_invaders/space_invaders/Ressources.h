#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics {

	class Ressources
	{
	public:
		Ressources();
		~Ressources();

	public:
		/**
		* \brief Gives the real textures map
		*
		* \return the textures map.
		*/
		std::map<int, std::shared_ptr<sf::Texture> >& getRealTextures();

		/**
		* \brief Loads all the ressources of the game
		*
		* \return error code
		*/
		int load();
	private:
		std::map<int, std::shared_ptr<sf::Texture> > m_textures;
	};

}