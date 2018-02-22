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
		(int)(win.getSize().x - getRealSprite()->getLocalBounds().width) / 2,
		(int)(win.getSize().y - getRealSprite()->getLocalBounds().height)
	));

	// Initiate the hitbox
	getRealHitbox().getRealRect() = sf::Rect<int>(
		(int)(getPosition().x + getRealSprite()->getLocalBounds().width/4),
		(int)getPosition().y,
		(int)getRealSprite()->getLocalBounds().width / 2,
		(int)getRealSprite()->getLocalBounds().height
	);
}


Character::~Character()
{
}