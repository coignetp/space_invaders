#include "Missile.h"
#include "GameWindow.h"


Missile::Missile(graphics::GameWindow &win, const sf::Vector2i &pos)
{
	this->getRealSprite() = std::make_shared<sf::Sprite>(
		sf::Sprite(*win.getRealRessources().getRealTextures()[graphics::RESS_MISSILE])
		);
	win.getRealSpriteManager().getRealSprites().insert(std::make_pair(
		getHitbox().getId(),
		this->getRealSprite()
	));

	setPosition(pos);

	// Initiate the hitbox
	getRealHitbox().getRealRect() = sf::Rect<int>(
		getPosition().x,
		getPosition().y,
		(int)getRealSprite()->getLocalBounds().width,
		(int)getRealSprite()->getLocalBounds().height
	);
}


Missile::~Missile()
{
}
