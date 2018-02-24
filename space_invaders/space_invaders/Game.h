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

	/**
	* \brief Starts the game. Contains the main loop
	*
	* \return int error code
	*/
	int start();

	/**
	* \brief Updates the input and all the graphic contents
	* in the game.
	*
	* \return int error code
	*/
	int update();

	/**
	* \brief Makes a new level with new enemis
	* 
	* \return nothing
	*/
	void newLevel(const int &nbW, const int &nbH);

private:
	graphics::GameWindow m_window;
	sf::Clock m_clock;
};

