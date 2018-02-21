#include "Game.h"


extern int MISSILE_ID;


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
	m_clock.restart();
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
				m_window.getRealCharacter().setSpeed(sf::Vector2f(1000.0, 0.0));
				break;
			case sf::Keyboard::Left:
				m_window.getRealCharacter().setSpeed(sf::Vector2f(-1000.0, 0.0));
				break;
			case sf::Keyboard::Space:
				m_window.getRealCharacter().getRealMissiles().insert(std::make_pair(
					MISSILE_ID, std::make_shared<Missile>(Missile(m_window, sf::Vector2i(
						m_window.getRealCharacter().getPosition().x + (int)(m_window.getRealCharacter().getRealSprite()->getLocalBounds().width / 2),
						m_window.getRealCharacter().getPosition().y + 3
					))))
				);
				m_window.getRealCharacter().getRealMissiles().at(MISSILE_ID)->setSpeed(sf::Vector2f(0.0, -800.0));
				break;
			default:
				break;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
			case sf::Keyboard::Left:
				m_window.getRealCharacter().setSpeed(sf::Vector2f(0.0, 0.0));
				break;
			default:
				break;
			}
		}
	}
	m_window.getRealCharacter().update(m_clock.getElapsedTime(), sf::Vector2i(m_window.getSize()), m_window);
	m_clock.restart();

	return 0;
}