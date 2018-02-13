#pragma once

#include <SFML\Graphics.hpp>

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
		std::map<int, sf::Texture>& getRealTextures();

		/**
		* \brief Loads all the ressources of the game
		*
		* \return error code
		*/
		int load();
	private:
		std::map<int, sf::Texture> m_textures;
	};

}