#include "GameWindow.h"
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>


namespace graphics {
	GameWindow::GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings) :
		sf::RenderWindow(vid, title, style, settings),
		m_layers(WINDOW_LAYER_TOTAL),
		m_character(*this)
	{
		for (unsigned int i(0); i < m_layers.size(); i++)
			m_layers.at(i).create(this->getSize().x, this->getSize().y);

		/// Draw the background on layer 0
		m_spriteManager.getRealSprites().insert(std::make_pair<int, sf::Sprite>(
			0, 
			sf::Sprite(*m_ressources.getRealTextures()[RESS_BACKGROUND])
		));

		m_spriteManager.getRealSprites()[0].setScale(
			(float)this->getSize().x / m_spriteManager.getRealSprites()[0].getLocalBounds().width,
			(float)this->getSize().y / m_spriteManager.getRealSprites()[0].getLocalBounds().height
		);

		m_layers.at(0).draw(m_spriteManager.getRealSprites()[0]);
		///
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

		m_character.print(*this);

		for (unsigned int i(0); i < m_layers.size() ; i++)
			this->draw(sf::Sprite(m_layers.at(i).getTexture()));
		
		this->display();

		return 0;
	}
}