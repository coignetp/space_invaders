#include "Game.h"


extern int MISSILE_ID;


Game::Game(sf::VideoMode vid, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings) :
	m_window(vid, title, style, settings, m_hitboxManager),
	m_over(false)
{
}


Game::~Game()
{
}


bool Game::isOver()
{
	return m_over;
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
			case sf::Keyboard::Return:
				if (m_over)
				{
					newLevel(6, 5);
					m_window.getRealCharacter().setPosition(sf::Vector2i(
						(int)(m_window.getSize().x / 2 - m_window.getRealCharacter().getSprite()->getGlobalBounds().width / 2),
						(int)m_window.getRealCharacter().getPosition().y
					));
					m_over = false;
				}
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
	if (!m_over)
	{
		m_window.getRealCharacter().update(m_clock.getElapsedTime(), sf::Vector2i(m_window.getSize()), m_window, m_hitboxManager);

		for (std::list<std::shared_ptr<Enemi>>::iterator it(m_window.getRealEnemis().begin()); it != m_window.getRealEnemis().end(); it++)
			(*it)->update(m_clock.getElapsedTime(), sf::Vector2i(m_window.getSize()), m_window, m_hitboxManager);

		updateCollisions();
	}

	m_clock.restart();

	return 0;
}


int Game::updateCollisions()
{
	if (m_hitboxManager.isColliding(*m_window.getRealCharacter().getHitbox()))
	{
		std::shared_ptr<sf::Text> text;
		m_window.getRealTextManager().getRealTexts().insert(std::make_pair(0, std::make_shared<sf::Text>()));
		text = m_window.getRealTextManager().getRealTexts()[0];

		text->setString("You loose !\n\nPress enter to continue");
		text->setFont(*m_window.getRealRessources().getRealFonts()[graphics::FONT_MAIN]);

		text->setPosition(300, 300);
		m_window.getRealLayers()[graphics::WINDOW_LAYER_TEXT]->addText(0);

		m_over = true;
	}

	return 0;
}


void Game::newLevel(const int &nbW, const int &nbH)
{
	for (std::list < std::shared_ptr<Enemi> >::iterator it(m_window.getRealEnemis().begin());
		it != m_window.getRealEnemis().end(); it++)
	{
		(*it)->clean(std::make_shared<graphics::SpriteManager>(m_window.getRealSpriteManager()), m_window);
	}

	m_window.getRealEnemis().clear();

	m_window.getRealLayers()[graphics::WINDOW_LAYER_TEXT]->getRealTexts().clear();

	m_window.getRealTextManager().getRealTexts().clear();

	int wgap = ((1024) / (2*nbW));

	for (int i(0); i < nbH; i++)
	{
		for (int j(0); j < nbW; j++)
		{
			m_window.getRealEnemis().push_back(std::make_shared<Enemi>(m_hitboxManager, sf::Rect<int>(wgap*j, i*80, (1024/2)+64, 600), m_window));
			m_window.getRealEnemis().back()->print(m_window);
			m_window.getRealEnemis().back()->setSpeed(sf::Vector2f(50, 0));
		}
	}
}