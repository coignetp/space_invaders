#include <memory>
#include "Character.h"
#include "GameWindow.h"


Character::Character(graphics::GameWindow &win)
{
	this->getRealSprite() = std::make_shared<sf::Sprite>(
		sf::Sprite(*win.getRealRessources().getRealTextures()[graphics::RESS_ME])
	);
	win.getRealSpriteManager().getRealSprites().insert(std::make_pair(
		getHitbox().getId(),
		this->getRealSprite()
	));

	setPosition(sf::Vector2i(
		(win.getSize().x - getRealSprite()->getLocalBounds().width) / 2,
		win.getSize().y - getRealSprite()->getLocalBounds().height
	));
}


Character::~Character()
{
}
