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
		m_window.print();
		sf::sleep(sf::milliseconds(30));
	}
}