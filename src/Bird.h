//
// Created by trdp9 on 03/04/2021.
//

#ifndef ANGRYBIRDSSFML_BIRD_H
#define ANGRYBIRDSSFML_BIRD_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"

class Bird : public GameObject
{
 public:
  Bird();
  ~Bird();
  void setupSprite();
  void killSprite(sf::RenderWindow& window);

  float speed = 750;
  bool is_released = false;
  int bird_number = 0;
  bool is_killed = false;

};

#endif // ANGRYBIRDSSFML_BIRD_H
