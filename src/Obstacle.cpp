//
// Created by trdp9 on 28/04/2021.
//

#include "Obstacle.h"

void Obstacle::setupSprite()
{
  sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
  sprite->setScale(0.7,0.7);
  sprite->setPosition(
    sprite->getGlobalBounds().width/2 + 100,
    sprite->getGlobalBounds().height/2 + 550);
}

Obstacle::Obstacle()
{

}

Obstacle::~Obstacle()
{
}