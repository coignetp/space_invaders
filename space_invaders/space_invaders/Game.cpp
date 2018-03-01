#include "Game.h"


extern int MISSILE_ID;


Game::Game(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings) :
	m_window(vid, title, style, settings, m_hitboxManager)
{
}


Game::~Game()
{
}


graphics::GameWindow& Game::getRealWindow()
{
	return m_window;
}


physics::HitboxManager& Game::getRealHitboxManager()
{
	return m_hitboxManager;
}


int Game::start()
{
	m_clock.restart();

	newLevel(6, 5);

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
				m_window.getRealCharacter().setRateOfFire(10);
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
			case sf::Keyboard::Space:
				m_window.getRealCharacter().setRateOfFire(0);
				break;
			default:
				break;
			}
		}
	}
	m_window.getRealCharacter().update(m_clock.getElapsedTime(), sf::Vector2i(m_window.getSize()), m_window, m_hitboxManager);

	for (std::list<Enemi>::iterator it(m_window.getRealEnemis().begin()); it != m_window.getRealEnemis().end(); it++)
		it->update(m_clock.getElapsedTime(), sf::Vector2i(m_window.getSize()),m_window, m_hitboxManager);

	updateCollisions();

	m_clock.restart();

	return 0;
}


int Game::updateCollisions()
{
	return 0;
}


void Game::newLevel(const int &nbW, const int &nbH)
{
	m_window.getRealEnemis().clear();

	int wgap = ((1024) / (2*nbW));

	for (int i(0); i < nbH; i++)
	{
		for (int j(0); j < nbW; j++)
		{
			m_window.getRealEnemis().push_back(Enemi(m_hitboxManager, sf::Rect<int>(wgap*j, i*80, (1024/2)+64, 600), m_window));
			m_window.getRealEnemis().back().print(m_window);
			m_window.getRealEnemis().back().setSpeed(sf::Vector2f(50, 0));
		}
	}
}