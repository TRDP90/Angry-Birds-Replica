//
// Created by trdp9 on 15/04/2021.
//

#ifndef ANGRYBIRDSSFML_EFFECT_H
#define ANGRYBIRDSSFML_EFFECT_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Effect
{
 public:
  Effect();
  ~Effect();
  bool initialiseSprite(sf::Texture& texture, sf::IntRect& texture_rect, std::string filename);
  sf::Sprite* getSprite();

  bool setVisibility(bool value);
  bool getVisibility();
  int setRow(int value);
  int setColumn(int value);


 private:
  sf::Sprite* sprite = nullptr;
  bool visibility = true;
  int sprite_row = 0;
  int sprite_column = 0;
};

#endif // ANGRYBIRDSSFML_EFFECT_H
