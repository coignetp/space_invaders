#pragma once

#include <deque>
#include <SFML\Graphics.hpp>

namespace graphics {

	class GameWindow;

	class Layer
	{
	public:
		Layer();
		~Layer();
	public:
		/**
		* \brief Real reference of the sprites map.
		*
		* \return the real sprites.
		*/
		std::deque<int> &getRealSprites();
		/**
		* \brief Real reference of the text map.
		* 
		* \return the real texts.
		*/
		std::deque<int> &getRealTexts();

		/**
		* \brief Print the different sprites of the layer
		*
		* \param win : the main window
		*
		* \return an error code.
		*/
		int print(GameWindow &win);

		/**
		* \brief Add an other sprite on the layer
		*
		* \param id : the id of the sprite in the manager
		*
		* \return nothing
		*/
		void addSprite(const int &id);
		/**
		* \brief Add an other text on the layer
		*
		* \param id : the id of the text in the manager
		*
		* \return nothing
		*/
		void addText(const int &id);

	private:
		std::deque<int> m_sprites;
		std::deque<int> m_texts;
	};

}