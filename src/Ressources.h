#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics {
enum RESS_INDEX {
  RESS_BACKGROUND,
  RESS_ME,
  RESS_ENEMI,
  RESS_MISSILE,
  RESS_TOTAL
};
enum FONT_INDEX { FONT_MAIN, FONT_TOTAL };
class Ressources {
 public:
  Ressources();
  ~Ressources();

 public:
  /**
   * \brief Gives the real textures map
   *
   * \return the textures map.
   */
  std::map<int, std::shared_ptr<sf::Texture> >& getRealTextures();
  /**
   * \brief Gives the real font map
   *
   * \return std::map<int, std::shared_ptr<sf::Font> >& the font.
   */
  std::map<int, std::shared_ptr<sf::Font> >& getRealFonts();

  /**
   * \brief Loads all the ressources of the game
   *
   * \return error code
   */
  int load();

 private:
  std::map<int, std::shared_ptr<sf::Texture> > m_textures;
  std::map<int, std::shared_ptr<sf::Font> > m_fonts;
};

}  // namespace graphics