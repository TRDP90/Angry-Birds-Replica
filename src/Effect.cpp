//
// Created by trdp9 on 15/04/2021.
//

#include "Effect.h"
#include "iostream"

bool Effect::initialiseSprite(sf::Texture& texture, sf::IntRect& texture_rect, std::string filename)
{
  //init Sprite
  if(!texture.loadFromFile(filename))
  {
    std::cout << "Texture did not load\n";
  }

  sprite->setTexture(texture);
  sprite->setTextureRect(texture_rect);

  sprite->setScale(1,1);
  sprite->setPosition(
    sprite->getGlobalBounds().width/2 + 100,
    sprite->getGlobalBounds().height/2 + 400);

  return true;
}


Effect::Effect()
{
  sprite = new sf::Sprite;
}


Effect::~Effect()
{
}


sf::Sprite* Effect::getSprite()
{
  return sprite;
}


bool Effect::getVisibility()
{
  return visibility;
}


bool Effect::setVisibility(bool value)
{
  visibility = value;
}


int Effect::setRow(int value)
{
  sprite_row = value;
}


int Effect::setColumn(int value)
{
  sprite_column = value;
}

