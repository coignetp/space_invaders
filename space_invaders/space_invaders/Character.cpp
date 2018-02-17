#include <memory>
#include "Character.h"
#include "GameWindow.h"


Character::Character(graphics::GameWindow &win)
{
	win.getRealSpriteManager().getRealSprites().insert(std::make_pair(
		42,
		sf::Sprite(*win.getRealRessources().getRealTextures()[graphics::RESS_ME])
	));

	this->getRealSprite() = std::make_shared<sf::Sprite>(win.getRealSpriteManager().getRealSprites()[42]);
}


Character::~Character()
{
}
