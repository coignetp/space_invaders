#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace graphics {
class TextManager {
 public:
  TextManager();
  ~TextManager();

 public:
  /**
   * \brief Gives the real sprites map
   *
   * \return std::map<int, sf::Text> texts map
   */
  std::map<int, std::shared_ptr<sf::Text>>& getRealTexts();

 private:
  std::map<int, std::shared_ptr<sf::Text>> m_texts;
};

}  // namespace graphics