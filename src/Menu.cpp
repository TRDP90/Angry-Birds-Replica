//
// Created by trdp9 on 04/04/2021.
//

#include "Menu.h"
#include "iostream"

void Menu::setupSprite()
{
  sprite->setScale(0.67,0.67);
  sprite->setPosition(0,0);
}

bool Menu::initialiseText(sf::Font& font, std::string filename)
{
  //init Font
  if(!font.loadFromFile(filename))
  {
    std::cout << "Font did not load\n";
  }
  text->setString("PLAY");
  text->setFont(font);
  text->setCharacterSize(50);
  text->setFillColor(sf::Color(255,255,255));

  text->setPosition(
    text->getGlobalBounds().width/2 + 150,
    text->getGlobalBounds().height/2 + 550);

  return true;
}


Menu::Menu()
{
  text = new sf::Text;
}


Menu::~Menu()
{
}


sf::Text* Menu::getText()
{
  return text;
}


