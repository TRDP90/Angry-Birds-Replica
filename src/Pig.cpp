//
// Created by trdp9 on 03/04/2021.
//

#include "Pig.h"

void Pig::setupSprite()
{
  sprite->setPosition(
    sprite->getGlobalBounds().width/2,
    sprite->getGlobalBounds().height/2 + 500);
  sprite -> setScale(0.5,0.5);
}

Pig::Pig()
{

}

Pig::~Pig()
{
}
