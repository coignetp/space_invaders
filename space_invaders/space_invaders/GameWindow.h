#pragma once
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

namespace graphics {

	enum WINDOW_LAYERS { WINDOW_LAYER_BG, WINDOW_LAYER_ITEM, WINDOW_LAYER_TEXT, WINDOW_LAYER_TOTAL};

	class GameWindow :
		public sf::RenderWindow
	{
	public:
		GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
	

		/**
		* \brief Update the render texture if necessary	.
		*
		* \return the real std::vector<sf::RenderTexture>.
		*/
		std::vector<sf::RenderTexture>& getRealLayers();
	private:
		std::vector<sf::RenderTexture> m_layers;
	};

}