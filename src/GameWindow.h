#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <list>

#include "Character.h"
#include "Enemi.h"
#include "Layer.h"
#include "Ressources.h"
#include "SpriteManager.h"
#include "TextManager.h"

namespace graphics {

enum WINDOW_LAYERS {
  WINDOW_LAYER_BG,
  WINDOW_LAYER_ITEM,
  WINDOW_LAYER_TEXT,
  WINDOW_LAYER_TOTAL
};

class GameWindow : public sf::RenderWindow {
 public:
  GameWindow(sf::VideoMode vid, const sf::String& title, sf::Uint32 style,
             const sf::ContextSettings& settings,
             physics::HitboxManager& hitboxManager);

  /**
   * \brief Real reference of the layers.
   *
   * \return the real std::vector<sf::RenderTexture>.
   */
  std::vector<std::unique_ptr<Layer>>& getRealLayers();
  /**
   * \brief Real reference of the ressources.
   *
   * \return the real Ressources.
   */
  Ressources& getRealRessources();
  /**
   * \brief Real reference of the sprite manager.
   *
   * \return the real SpriteManager.
   */
  SpriteManager& getRealSpriteManager();
  /**
   * \brief Real reference of the text manager.
   *
   * \return the real TextManager.
   */
  TextManager& getRealTextManager();
  /**
   * \brief Real reference of the character.
   *
   * \return the real Character.
   */
  Character& getRealCharacter();
  /**
   * \brief Real reference of the enemis.
   *
   * \return the real std::list<Enemi>.
   */
  std::list<std::shared_ptr<Enemi>>& getRealEnemis();

  /**
   * \brief Print the different layers
   *
   * \return an error code.
   */
  int print();

 private:
  std::vector<std::unique_ptr<Layer>> m_layers;
  Ressources m_ressources;
  SpriteManager m_spriteManager;
  TextManager m_textManager;
  Character m_character;
  std::list<std::shared_ptr<Enemi>> m_enemis;
};

}  // namespace graphics