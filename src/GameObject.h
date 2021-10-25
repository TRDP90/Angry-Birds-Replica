//
// Created by trdp9 on 25/04/2021.
//

#ifndef ANGRYBIRDSSFML_GAMEOBJECT_H
#define ANGRYBIRDSSFML_GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();

  Vector2 direction = {0,0};
  float speed = 200;
  bool setVisibility(bool value);
  bool getVisibility();

 private:
  bool visibility = true;

 protected:
  sf::Sprite* sprite = nullptr;
};

#endif // ANGRYBIRDSSFML_GAMEOBJECT_H
