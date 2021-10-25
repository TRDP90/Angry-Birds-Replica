//
// Created by trdp9 on 04/04/2021.
//

#ifndef ANGRYBIRDSSFML_MENU_H
#define ANGRYBIRDSSFML_MENU_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"

class Menu : public GameObject
{
 public:
  Menu();
  ~Menu();
  bool initialiseText(sf::Font& font,std::string filename);
  void setupSprite();
  sf::Text* getText();

  bool is_menu = true;

 private:
  sf::Text* text = nullptr;

};

#endif // ANGRYBIRDSSFML_MENU_H
