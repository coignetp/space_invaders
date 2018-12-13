#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
  Game g(sf::VideoMode(1024, 800), "Space Invaders");

  return g.start();
}