#include "TextManager.h"


namespace graphics {
	TextManager::TextManager()
	{
	}


	TextManager::~TextManager()
	{
	}


	std::map<int, std::shared_ptr<sf::Text>>& TextManager::getRealTexts()
	{
		return m_texts;
	}
}