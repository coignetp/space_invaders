#include "Game.h"



Game::Game(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings) :
	m_window(vid, title, style, settings)
{
}


Game::~Game()
{
}


graphics::GameWindow& Game::getRealWindow()
{
	return m_window;
}


int Game::start()
{
	while (m_window.isOpen())
	{
		int ret = update();
		ret = (m_window.print() << 1);

		if (ret != 0)
			return ret;

		sf::sleep(sf::milliseconds(30));
	}

	return 0;
}

int Game::update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				m_window.getRealCharacter().move(5, 0, sf::Vector2i(m_window.getSize()));
				break;
			case sf::Keyboard::Left:
				m_window.getRealCharacter().move(-5, 0, sf::Vector2i(m_window.getSize()));
				break;
			default:
				break;
			}
		}
	}

	return 0;
}