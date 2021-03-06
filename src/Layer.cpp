#include "Layer.h"
#include "GameWindow.h"

namespace graphics {

Layer::Layer() {}

Layer::~Layer() {}

std::deque<int> &Layer::getRealSprites() { return m_sprites; }

std::deque<int> &Layer::getRealTexts() { return m_texts; }

int Layer::print(GameWindow &win) {
  for (int sp : m_sprites) {
    win.draw(*win.getRealSpriteManager().getRealSprites()[sp]);
  }
  for (int txt : m_texts) {
    win.draw(*win.getRealTextManager().getRealTexts()[txt]);
  }

  return 0;
}

void Layer::addSprite(const int &id) { m_sprites.push_back(id); }

void Layer::addText(const int &id) { m_texts.push_back(id); }
}  // namespace graphics