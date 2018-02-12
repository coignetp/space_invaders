#pragma once

#include "GameWindow.h"

class Game
{
public:
	Game(sf::VideoMode vid, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
	~Game();

public:
	/**
	* \brief Gives the actual window
	*
	* \return a reference to GameWindow.
	*/
	graphics::GameWindow& getRealWindow();

private:
	graphics::GameWindow m_window;
};

