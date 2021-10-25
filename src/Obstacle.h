//
// Created by trdp9 on 28/04/2021.
//

#ifndef ANGRYBIRDSSFML_OBSTACLE_H
#define ANGRYBIRDSSFML_OBSTACLE_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"

class Obstacle : public GameObject
{
 public:
  Obstacle();
  ~Obstacle();
  void setupSprite();
};

#endif // ANGRYBIRDSSFML_OBSTACLE_H
