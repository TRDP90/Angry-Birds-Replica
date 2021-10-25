//
// Created by trdp9 on 03/04/2021.
//

#include "Bird.h"

void Bird::setupSprite()
{
  sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
  sprite->setScale(0.4,0.4);
  sprite->setPosition(
    sprite->getGlobalBounds().width/2 + 100,
    sprite->getGlobalBounds().height/2 + 550);
}


Bird::Bird()
{

}


Bird::~Bird()
{
}


void Bird::killSprite(sf::RenderWindow& window)
{
  // Left side
  if (sprite->getPosition().x <= 0)
  {
    is_killed = true;
    bird_number++;
  }
  // Right side
  if (sprite->getPosition().x >= (window.getSize().x + sprite->getGlobalBounds().width))
  {
    is_killed = true;
    bird_number++;
  }
  // Bottom side
  if (sprite->getPosition().y >= (window.getSize().y + sprite->getGlobalBounds().height ))
  {
    is_killed = true;
    bird_number++;
  }
}
