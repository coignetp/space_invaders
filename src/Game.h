#pragma once

#include "GameWindow.h"
#include "HitboxManager.h"

class Game
{
public:
	Game(sf::VideoMode vid, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
	~Game();

public:
	/**
	* \brief Tells if the game is over or not.
	*
	* \return True if it is over.
	*/
	bool isOver();
	/**
	* \brief Gives the actual window
	*
	* \return a reference to GameWindow.
	*/
	graphics::GameWindow& getRealWindow();
	/**
	* \brief Gives the actual hitbox manager
	*
	* \return a reference to HitboxManager.
	*/
	physics::HitboxManager& getRealHitboxManager();

	/**
	* \brief Starts the game. Contains the main loop
	*
	* \return int error code
	*/
	int start();
	/**
	* \brief End the game.
	*
	* \return nothing
	*/
	void lost();
	/**
	* \brief Update to know if the level is finished
	*
	* \return true if the level is finished
	*/
	bool updateLevel();

	/**
	* \brief Updates the input and all the graphic contents
	* in the game.
	*
	* \return int error code
	*/
	int update();
	/**
	* \brief Updates the physic model
	*
	* \return int error code
	*/
	int updateCollisions();

	/**
	* \brief Makes a new level with new enemis
	* 
	* \return nothing
	*/
	void newLevel(const int &nbW, const int &nbH);

private:
	graphics::GameWindow m_window;
	sf::Clock m_clock;
	physics::HitboxManager m_hitboxManager;
	bool m_over;
	bool m_readyForNext;
};

