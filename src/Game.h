
#ifndef ANGRYBIRDS_GAME_H
#define ANGRYBIRDS_GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Level.h"
#include "Bird.h"
#include "Pig.h"
#include "Effect.h"
#include "Obstacle.h"
#include "Audio.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();

  void releaseBird(float dt);
  void replaceBird();
  void resetLevel();
  void collision(float dt);
  void playEffect();
  void dragBird();
  void updateScore();

  void mouseClicked(sf::Event event);
  void mouseReleased(sf::Event event);
  void mouseHover(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Clock clock;
  sf::Clock animation_clock;
  sf::Clock power_clock;

  sf::Text score_text;
  int score = 0;

  bool player_win = false;
  bool player_lose = false;

  sf::Text win_text;
  sf::Text lose_text;

  sf::Sprite slingshot;
  sf::Texture slingshot_texture;

  Menu menu;
  sf::Texture menu_texture;

  Level* level = nullptr;
  int level_number = 0;
  sf::Texture level_1_texture;
  sf::Texture level_2_texture;
  sf::Texture level_3_texture;

  Obstacle* obstacle = nullptr;
  sf::Texture obstacle_1_texture;
  sf::Texture obstacle_2_texture;
  sf::Texture obstacle_3_texture;
  sf::RectangleShape collider;
  bool bounce = false;

  Bird* bird = nullptr;
  int bird_type = 0;
  int bird_max = 3;
  int bird_left = 3;
  sf::Texture bird_1_texture;
  sf::Texture bird_2_texture;
  sf::Texture bird_3_texture;
  bool bird_2_power = false;
  bool bird_3_power = false;
  int bird_3_x_pos = 0;
  int bird_3_y_pos = 0;
  sf::CircleShape bird_blast_radius;

  Pig* pig = nullptr;
  int pig_max = 3;
  sf::Texture pig_texture;

  Effect* effect = nullptr;
  sf::Texture pig_blast_texture;
  sf::IntRect pig_blast_rect[3];

  Audio* sound = nullptr;
  sf::SoundBuffer pig_blast_sound;
  sf::SoundBuffer bird_blast_sound;
  sf::SoundBuffer bird_release_sound;
  sf::SoundBuffer glass_break_sound;
  sf::SoundBuffer spring_sound;
  sf::SoundBuffer zoom_sound;
  sf::SoundBuffer stretch_sound;
  sf::Music music;

  sf::Texture bird_blast_texture;
  sf::IntRect bird_blast_rect;

  Menu* text = nullptr;
  sf::Font font;
  bool show_instructions = false;

  bool sprite_drag = false;
  sf::CircleShape bird_boundary;
  bool out_of_boundary = false;
  int max_distance = 200;
  int release_pos_x = 0;
  int release_pos_y = 0;

};

#endif // ANGRYBIRDS_GAME_H
