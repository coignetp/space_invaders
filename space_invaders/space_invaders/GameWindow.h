#pragma once
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

#include "SpriteManager.h"
#include "Ressources.h"
#include "Character.h"

namespace graphics {

	enum WINDOW_LAYERS { WINDOW_LAYER_BG, WINDOW_LAYER_ITEM, WINDOW_LAYER_TEXT, WINDOW_LAYER_TOTAL};

	class GameWindow :
		public sf::RenderWindow
	{
	public:
		GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
	
		/**
		* \brief Real reference of the layers.
		*
		* \return the real std::vector<sf::RenderTexture>.
		*/
		std::vector<sf::RenderTexture>& getRealLayers();
		/**
		* \brief Real reference of the ressources.
		*
		* \return the real Ressources.
		*/
		Ressources& getRealRessources();
		/**
		* \brief Real reference of the sprite manager.
		*
		* \return the real SpriteManager.
		*/
		SpriteManager& getRealSpriteManager();
		/**
		* \brief Real reference of the character.
		*
		* \return the real Character.
		*/
		Character& getRealCharacter();

		/**
		* \brief Print the different layers
		*
		* \return an error code.
		*/
		int print();
	private:
		std::vector<sf::RenderTexture> m_layers;
		Ressources m_ressources;
		SpriteManager m_spriteManager;
		Character m_character;
	};

}