//
// Created by trdp9 on 03/04/2021.
//

#ifndef ANGRYBIRDSSFML_PIG_H
#define ANGRYBIRDSSFML_PIG_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"

class Pig : public GameObject
{
 public:
  Pig();
  ~Pig();

  void setupSprite();
};

#endif // ANGRYBIRDSSFML_PIG_H
