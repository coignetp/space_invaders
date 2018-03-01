#include "GameWindow.h"
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>


namespace graphics {
	GameWindow::GameWindow(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings, physics::HitboxManager &hitboxManager) :
		sf::RenderWindow(vid, title, style, settings),
		m_character(hitboxManager, *this)
	{
		for (unsigned int i(0); i < WINDOW_LAYER_TOTAL; i++)
			m_layers.push_back(std::make_unique<Layer>());
		/// Draw the background on layer 0
		m_spriteManager.getRealSprites().insert(std::make_pair<int, std::shared_ptr<sf::Sprite>>(
			-1, 
			std::make_shared<sf::Sprite>(sf::Sprite(*m_ressources.getRealTextures()[RESS_BACKGROUND]))
		));

		m_spriteManager.getRealSprites()[-1]->setScale(
			(float)this->getSize().x / m_spriteManager.getRealSprites()[-1]->getLocalBounds().width,
			(float)this->getSize().y / m_spriteManager.getRealSprites()[-1]->getLocalBounds().height
		);

		m_layers.at(RESS_BACKGROUND)->addSprite(-1);
		///
		m_character.print(*this);
	}

	std::vector<std::unique_ptr<Layer>>& GameWindow::getRealLayers()
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

	Character& GameWindow::getRealCharacter()
	{
		return m_character;
	}

	std::list<Enemi>& GameWindow::getRealEnemis()
	{
		return m_enemis;
	}

	int GameWindow::print()
	{
		this->clear();

		for (unsigned int i(0); i < m_layers.size(); i++)
			m_layers[i]->print(*this);
		
		this->display();

		return 0;
	}
}