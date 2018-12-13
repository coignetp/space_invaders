#include "Ressources.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace graphics {
Ressources::Ressources() { load(); }

Ressources::~Ressources() {}

std::map<int, std::shared_ptr<sf::Texture> >& Ressources::getRealTextures() {
  return m_textures;
}

std::map<int, std::shared_ptr<sf::Font> >& Ressources::getRealFonts() {
  return m_fonts;
}

int Ressources::load() {
  std::vector<std::string> filenames{"data/bg.jpg", "data/me.png",
                                     "data/enemi.png", "data/missile.bmp"};
  std::vector<std::string> fontNames{"data/expresswayrg.ttf"};

  try {
    for (unsigned int i(0); i < filenames.size(); i++) {
      std::shared_ptr<sf::Texture> textu = std::make_shared<sf::Texture>();
      if (!textu->loadFromFile(filenames[i])) return -1;
      m_textures.insert(std::make_pair(i, textu));
    }

    for (unsigned int i(0); i < fontNames.size(); i++) {
      std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
      if (!font->loadFromFile(fontNames[i])) return -1;
      m_fonts.insert(std::make_pair(i, font));
    }
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  return 0;
}
}  // namespace graphics