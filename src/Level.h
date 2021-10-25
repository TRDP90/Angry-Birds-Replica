//
// Created by trdp9 on 03/04/2021.
//

#ifndef ANGRYBIRDSSFML_LEVEL_H
#define ANGRYBIRDSSFML_LEVEL_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Level
{
 public:
  Level();
  ~Level();
  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();

 private:
  sf::Sprite* sprite = nullptr;
};

#endif // ANGRYBIRDSSFML_LEVEL_H
