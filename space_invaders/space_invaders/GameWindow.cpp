#include "GameWindow.h"

#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>


namespace graphics {
	GameWindow::GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings) :
		sf::RenderWindow(vid, title, style, settings),
		m_layers(WINDOW_LAYER_TOTAL)
	{
		for (unsigned int i(0); i < m_layers.size(); i++)
			m_layers.at(i).create(this->getSize().x, this->getSize().y);
	}

	std::vector<sf::RenderTexture>& GameWindow::getRealLayers()
	{
		return m_layers;
	}


	Ressources& GameWindow::getRealRessources()
	{
		return m_ressources;
	}


	SpriteManager& GameWindow::getRealSpriteManager()
	{
		return m_spriteManager;
	}


	int GameWindow::print()
	{
		this->clear();

		for (unsigned int i(0); i < m_layers.size() ; i++)
			this->draw(sf::Sprite(m_layers.at(i).getTexture()));
		
		this->display();

		return 0;
	}
}