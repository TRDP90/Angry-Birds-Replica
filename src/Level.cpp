//
// Created by trdp9 on 03/04/2021.
//

#include "Level.h"
#include "iostream"

bool Level::initialiseSprite(sf::Texture& texture, std::string filename)
{
  //init Sprite
  if(!texture.loadFromFile(filename))
  {
    std::cout << "Texture did not load\n";
  }

  sprite->setTexture(texture);

  sprite -> setScale(0.67,0.67);

  return true;
}

Level::Level()
{
  sprite = new sf::Sprite;
}

Level::~Level()
{
}

sf::Sprite* Level::getSprite()
{
  return sprite;
}