
#include "Game.h"
#include <iostream>
#include "cmath"

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
  if (level != nullptr)
  {
    delete [] level;
    level = nullptr;
  }
  if (bird != nullptr)
  {
    delete [] bird;
    bird = nullptr;
  }
  if (pig != nullptr)
  {
    delete [] pig;
    pig = nullptr;
  }
  if (text != nullptr)
  {
    delete [] text;
    text = nullptr;
  }
  if (effect != nullptr)
  {
    delete [] effect;
    effect = nullptr;
  }
  if (obstacle != nullptr)
  {
    delete [] obstacle;
    obstacle = nullptr;
  }
  if (sound != nullptr)
  {
    delete [] sound;
    sound = nullptr;
  }

}


bool Game::init()
{
  // init menu
  menu.initialiseSprite(menu_texture,"Data/Images/menu.jpg");

  menu.setupSprite();

  // init menu text

  // PLAY
  text = new Menu[4];
  text[0].initialiseText(font, "Data/Fonts/open-sans/OpenSans-Regular.ttf");
  text[0].getText()->setString("PLAY");

  // INSTRUCTIONS
  text[1].initialiseText(font, "Data/Fonts/open-sans/OpenSans-Semibold.ttf");
  text[1].getText()->setString("INSTRUCTIONS");
  text[1].getText()->setPosition(text[1].getText()->getGlobalBounds().width/2 + 250,
                                 text[1].getText()->getGlobalBounds().height/2 + 550);

  // EXIT
  text[2].initialiseText(font, "Data/Fonts/open-sans/OpenSans-Semibold.ttf");
  text[2].getText()->setString("EXIT");
  text[2].getText()->setPosition(text[2].getText()->getGlobalBounds().width/2 + 800,
                                 text[2].getText()->getGlobalBounds().height/2 + 550);

  // instructions text
  text[3].initialiseText(font, "Data/Fonts/open-sans/OpenSans-Semibold.ttf");
  text[3].getText()->setString("Hold left mouse click to pull the bird \nand let go to fire.\n"
                               "Some birds have special abilities!\n"
                               "Left click after firing to activate their \nspecial abilities!");
  text[3].getText()->setPosition(text[3].getText()->getGlobalBounds().width/2 + 350,
                                 text[3].getText()->getGlobalBounds().height/2 - 60);
  text[3].getText()->setCharacterSize(27);


  // init bird boundary
  bird_boundary.setRadius(200);
  bird_boundary.setPointCount(100);
  bird_boundary.setPosition(slingshot.getGlobalBounds().width/2 + 250,
                            slingshot.getGlobalBounds().height/2 + 500);
  bird_boundary.setFillColor(sf::Color(0,255,0,100));
  bird_boundary.setOrigin(bird_boundary.getLocalBounds().width/2,bird_boundary.getLocalBounds().height/2);

  // init collider
  collider.setPosition(825,455);
  collider.setSize(sf::Vector2f(10, 195));
  collider.setFillColor(sf::Color(255,0,0,100));


  // init level array
  level = new Level[3];

  if (level_number == 0)
  {
    level[level_number].initialiseSprite(level_1_texture,"Data/Images/lvl1.png");
  }
  if (level_number == 1)
  {
    level[level_number].initialiseSprite(level_2_texture,"Data/Images/lvl2.png");
  }
  if (level_number == 2)
  {
    level[level_number].initialiseSprite(level_3_texture,"Data/Images/lvl3.png");
  }

  // init slingshot
  if (!slingshot_texture.loadFromFile(("Data/Images/slingshot.png")))
  {
    std::cout << "slingshot texture did not load \n";
  }

  slingshot.setTexture(slingshot_texture);
  slingshot.setPosition(
    slingshot.getGlobalBounds().width/2 + 50,
    slingshot.getGlobalBounds().height/2 - 50);
  slingshot.setScale(0.2,0.2);

  // init obstacle array
  obstacle = new Obstacle[4];
  obstacle[0].initialiseSprite(obstacle_1_texture,"Data/Images/kenney_physicspack/PNG/Glass elements/elementGlass049.png");
  obstacle[1].initialiseSprite(obstacle_2_texture,"Data/Images/kenney_physicspack/PNG/Metal elements/elementMetal003.png");
  obstacle[2].initialiseSprite(obstacle_3_texture,"Data/Images/kenney_physicspack/PNG/Metal elements/elementMetal018.png");
  obstacle[3].initialiseSprite(obstacle_3_texture,"Data/Images/kenney_physicspack/PNG/Metal elements/elementMetal018.png");

  for (int i = 0; i < 4; ++i)
  {
    obstacle[i].setupSprite();
  }

  obstacle[0].getSprite()->setPosition(
    obstacle[0].getSprite()->getGlobalBounds().width/2 + 620,
    obstacle[0].getSprite()->getGlobalBounds().height/2 + 300);

  obstacle[1].getSprite()->setPosition(
    obstacle[1].getSprite()->getGlobalBounds().width/2 + 650,
    obstacle[1].getSprite()->getGlobalBounds().height/2 + 252);

  obstacle[2].getSprite()->setPosition(
    obstacle[2].getSprite()->getGlobalBounds().width/2 + 825,
    obstacle[2].getSprite()->getGlobalBounds().height/2 + 550);

  obstacle[3].getSprite()->setPosition(
    obstacle[3].getSprite()->getGlobalBounds().width/2 + 825,
    obstacle[3].getSprite()->getGlobalBounds().height/2 + 455);

  // init bird array
  bird = new Bird[bird_max];
  bird[0].initialiseSprite(bird_1_texture,"Data/Images/kenney_animalpackredux/PNG/Round (outline)/parrot.png");
  bird[1].initialiseSprite(bird_2_texture,"Data/Images/kenney_animalpackredux/PNG/Round (outline)/penguin.png");
  bird[2].initialiseSprite(bird_3_texture,"Data/Images/kenney_animalpackredux/PNG/Round (outline)/duck.png");

  for (int i = 0; i < bird_max; ++i)
  {
    bird[i].setupSprite();
  }

  bird[0].getSprite()->setPosition(
    slingshot.getGlobalBounds().width/2 + 260,
    slingshot.getGlobalBounds().height/2 + 380);

  bird[2].getSprite()->setPosition(
    bird[2].getSprite()->getGlobalBounds().width/2 + 20,
    bird[2].getSprite()->getGlobalBounds().height/2 + 550);

  // init pig array
  pig = new Pig[pig_max];
  for (int i = 0; i < pig_max; i++)
  {
    pig[i].initialiseSprite(pig_texture,"Data/Images/kenney_animalpackredux/PNG/Round (outline)/pig.png");
    pig[i].setupSprite();
  }

  pig[0].getSprite()->setPosition(
    window.getSize().x/2 - pig[0].getSprite()->getGlobalBounds().width/2 + 70,
    window.getSize().y/2 - pig[0].getSprite()->getGlobalBounds().height/2 + 220);
  pig[1].getSprite()->setPosition(
    window.getSize().x/2 - pig[1].getSprite()->getGlobalBounds().width/2 + 234,
    window.getSize().y/2 - pig[1].getSprite()->getGlobalBounds().height/2 + 63);
  pig[2].getSprite()->setPosition(
    window.getSize().x/2 - pig[2].getSprite()->getGlobalBounds().width/2 + 390,
    window.getSize().y/2 - pig[2].getSprite()->getGlobalBounds().height/2 + 220);

  // init effect array
  effect = new Effect[4];

  for (int i = 0; i < 3; i++)
  {
    effect[i].initialiseSprite(pig_blast_texture, pig_blast_rect[i],"Data/Images/Pig_Blast_Effect.png");
    effect[i].setRow(3);
    effect[i].setColumn(3);
    effect[i].getSprite()->setPosition(pig[i].getSprite()->getPosition().x - 110 ,pig[i].getSprite()->getPosition().y - 150);

    pig_blast_rect[i].top = 0;
    pig_blast_rect[i].left = 0;
    pig_blast_rect[i].width = pig_blast_texture.getSize().x/3;
    pig_blast_rect[i].height = pig_blast_texture.getSize().y/3;
  }

  // init bird explosion
  effect[3].initialiseSprite(bird_blast_texture, bird_blast_rect,"Data/Images/Bird_Blast_Effect.png");
  effect[3].setRow(8);
  effect[3].setColumn(8);

  bird_blast_rect.top = 0;
  bird_blast_rect.left = 0;
  bird_blast_rect.width = bird_blast_texture.getSize().x/8;
  bird_blast_rect.height = bird_blast_texture.getSize().y/8;

  // init audio array
  sound = new Audio[7];
  sound[0].initialiseSound(pig_blast_sound,"Data/Audio/Pig_Blast.wav");
  sound[1].initialiseSound(bird_blast_sound,"Data/Audio/Bird_Blast.wav");
  sound[2].initialiseSound(bird_release_sound,"Data/Audio/Release_Swoosh.wav");
  sound[3].initialiseSound(glass_break_sound,"Data/Audio/Glass_Break.wav");
  sound[4].initialiseSound(spring_sound,"Data/Audio/Spring.wav");
  sound[5].initialiseSound(zoom_sound,"Data/Audio/Zoom.wav");
  sound[6].initialiseSound(stretch_sound,"Data/Audio/Stretch.wav");

  // init BGM
  if (!music.openFromFile("Data/Audio/BGM.wav"))
  {
    std::cout << "ERROR: Music did not load\n";
  }
  music.setLoop(true);
  music.setVolume(7.0f);
  music.play();

  // init score
  std::string new_score = std::to_string(score);
  score_text.setString("Score: "+ new_score);
  score_text.setFont(font);
  score_text.setCharacterSize(50);
  score_text.setFillColor(sf::Color(255,255,255,255));
  score_text.setPosition(
    window.getSize().x/2 - score_text.getGlobalBounds().width/2 + 350,
    window.getSize().y/2 - score_text.getGlobalBounds().height/2 + 300);

  // init win text
  win_text.setString("               You Win!\nPress escape to return to menu.\nPress enter to replay.");
  win_text.setFont(font);
  win_text.setCharacterSize(50);
  win_text.setFillColor(sf::Color(255,255,255,255));
  win_text.setPosition(
    window.getSize().x/2 - win_text.getGlobalBounds().width/2,
    window.getSize().y/2 - win_text.getGlobalBounds().height/2 );

  // init lose text
  lose_text.setString("             You Lost!\nPress escape to return to menu.\nPress enter to replay.");
  lose_text.setFont(font);
  lose_text.setCharacterSize(50);
  lose_text.setFillColor(sf::Color(255,255,255,255));
  lose_text.setPosition(
    window.getSize().x/2 - lose_text.getGlobalBounds().width/2 ,
    window.getSize().y/2 - lose_text.getGlobalBounds().height/2 );

  return true;
}


void Game::update(float dt)
{
  // in game
  if (!menu.is_menu)
  {
    replaceBird();
    playEffect();

    // control post-game
    if (player_win || player_lose)
    {
      sprite_drag = false;
      bird[bird_type].is_released = false;
    }

    // mouse dragging the bird
    if (sprite_drag)
    {
      dragBird();
    }
    else
    {
      releaseBird(dt);
    }
  }
  collision(dt);
  updateScore();
}


void Game::render()
{
  // draw gameplay
  if (!menu.is_menu)
  {
    window.draw(*level[level_number].getSprite());

    if (out_of_boundary && sprite_drag)
    {
      window.draw(bird_boundary);
    }

    window.draw(slingshot);

    window.draw(bird_blast_radius);

    for (int i = 0; i < 4; i++)
    {
      if (obstacle[i].getVisibility())
      {
        window.draw(*obstacle[i].getSprite());
      }
    }

    for (int i = 0; i < bird_max; i++)
    {
      if (bird[i].getVisibility())
      {
        window.draw(*bird[i].getSprite());
      }
    }

    for (int i = 0; i < pig_max; i++)
    {
      if (pig[i].getVisibility())
      {
        window.draw(*pig[i].getSprite());
      }
    }

    for (int i = 0; i < pig_max ; i++)
    {
      if (!pig[i].getVisibility())
      {
        window.draw(*effect[i].getSprite());
      }
    }

    if (effect[3].getVisibility())
    {
      window.draw(*effect[3].getSprite());
    }

    window.draw(score_text);

    if (player_win)
    {
      window.draw(win_text);
    }
    if (player_lose)
    {
      window.draw(lose_text);
    }

    window.draw(collider);

  }

  // draw menu
  else
  {
    window.draw(*menu.getSprite());

    for (int i = 0; i < 3; ++i)
    {
      window.draw(*text[i].getText());
    }
    if (show_instructions)
    {
      window.draw(*text[3].getText());
    }
  }
}


void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  // GAMEPLAY
  if (!menu.is_menu)
  {
    if (event.mouseButton.button == sf::Mouse::Left)
    {
      if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        if (!bird[bird_type].is_released)
        {
          sprite_drag = true;

          if (!player_win && !player_lose)
          {
            // play swoosh
            sound[6].getAudio()->play();
          }
        }
      }

      if (bird[1].is_released)
      {
        bird_2_power = true;

        if (!bird[1].is_killed)
        {
          // play bird zoom
          sound[5].getAudio()->play();
        }
      }

      if (bird[2].is_released)
      {
        bird_3_power = true;
        bird_3_x_pos = bird[2].getSprite()->getPosition().x;
        bird_3_y_pos = bird[2].getSprite()->getPosition().y;

        if (bird_blast_rect.top == 0)
        {
          // play bird explosion
          sound[1].getAudio()->play();
        }
      }
    }
  }
}


void Game::keyPressed(sf::Event event)
{
  // replay level
  if (event.key.code == sf::Keyboard::Enter)
  {
    if (player_win || player_lose)
    {
      resetLevel();
    }
  }
  // return to menu
  if (event.key.code == sf::Keyboard::Escape)
  {
    if (player_win || player_lose)
    {
      menu.is_menu = true;
      resetLevel();
    }
  }
}


void Game::mouseReleased(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  // GAMEPLAY
  if (!menu.is_menu)
  {
    if (!bird[bird_type].is_released)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
      {
        sprite_drag = false;
        bird[bird_type].is_released = true;
        release_pos_x = click.x;
        release_pos_y = click.y;

        if(!player_lose && !player_win)
        {
          // play whoosh
          sound[2].getAudio()->play();
        }

        if (out_of_boundary == true)
        {
          release_pos_x = bird[bird_type].getSprite()->getPosition().x;
          release_pos_y = bird[bird_type].getSprite()->getPosition().y;
        }
        clock.restart();
      }
    }
  }

  else
  {
    // MENU SELECTION
    if (text[0].getText()->getGlobalBounds().contains(click.x,click.y))
    {
      menu.is_menu = false;
    }
    if (text[2].getText()->getGlobalBounds().contains(click.x,click.y))
    {
      window.close();
    }
  }
}


void Game::mouseHover(sf::Event event)
{
  // change colour of menu text
  for (int i = 0; i < 3; ++i)
  {
    if (text[i].getText()->getGlobalBounds().contains(event.mouseMove.x,event.mouseMove.y))
    {
      text[i].getText()->setFillColor(sf::Color(255,0,0));
    }
    else
    {
      text[i].getText()->setFillColor(sf::Color(255,255,255));
    }
  }

  // show instructions
  if (text[1].getText()->getGlobalBounds().contains(event.mouseMove.x,event.mouseMove.y))
  {
    show_instructions = true;
  }
  else
  {
    show_instructions = false;
  }
}


void Game::releaseBird(float dt)
{
  // init clock
  sf::Time counter = clock.getElapsedTime();

  // distance of vector when shot is released
  int drag_x = slingshot.getGlobalBounds().width/2 + 260 - release_pos_x;
  int drag_y = slingshot.getGlobalBounds().height/2 + 380 - release_pos_y;
  int max_drag_distance = 250;

  Vector2 drag(drag_x, drag_y);
  drag.normalise();

  // total length of the vector
  int released_distance = sqrt(pow(drag_x , 2) + pow(drag_y , 2));

  // release bird
  if (bird[bird_type].is_released)
  {
    bird->speed = 300;

    // kill bird if it exits the window
    if (bird[bird_type].getVisibility())
    {
      bird[bird_type].killSprite(window);
      if (bird[bird_type].is_killed)
      {
        bird[bird_type].setVisibility(false);
      }
    }

    // control speed of bird in air
    if (released_distance >= max_drag_distance)
    {
      bird->speed = 1000;
    }
    else
    {
      bird->speed = bird->speed + released_distance * 4;
    }

    // movement of bird when shot
    bird[bird_type].direction.x = drag.x ;
    bird[bird_type].direction.y  = drag.y + (counter.asSeconds() * 1.1);

    // bird bounce
    if (!bounce)
    {
      bird[bird_type].getSprite()->move(bird[bird_type].direction.x * bird->speed * dt, bird[bird_type].direction.y * bird->speed * dt);
    }
    else
    {
      bird[bird_type].getSprite()->move(-bird[bird_type].direction.x * bird->speed * dt,bird[bird_type].direction.y * bird->speed * dt);
    }

    // bird abilities

    // ZOOM
    if (bird_2_power)
    {
      if (bounce)
      {
        bird[1].getSprite()->move(0, bird[bird_type].direction.y  * bird->speed  * dt);
      }
      else
      {
        bird[1].getSprite()->move(bird[bird_type].direction.x * bird->speed * dt, bird[bird_type].direction.y + 1 * (bird->speed + 10) * dt);
      }
    }

    // EXPLODE
    if (bird_3_power)
    {
      effect[3].setVisibility(true);
      bird[2].getSprite()->move( 0, 0);
      bird[2].getSprite()->setPosition(bird_3_x_pos , bird_3_y_pos);
      bird[2].setVisibility(false);
    }
  }
}


void Game::replaceBird()
{
  if (bird[bird_type].is_killed)
  {
    if (bird_left > 0)
    {
      bird_left--;
    }
    if (bird_type < bird_max -1)
    {
      bird_type++;

      bird[bird_type].getSprite()->setPosition(
        slingshot.getGlobalBounds().width/2 + 260,
        slingshot.getGlobalBounds().height/2 + 380);

      bird[bird_type].is_released = false;
    }
    bird_2_power = false;
    bird_3_power = false;
    bounce = false;
  }
}


void Game::resetLevel()
{
  player_lose = false;
  player_win = false;
  bird_type = 0;
  bird_2_power = false;
  bird_3_power = false;
  score = 0;
  bird_left = 3;

  for (int i = 0; i < pig_max; ++i)
  {
    pig[i].setVisibility(true);
  }

  for (int i = 0; i < bird_max; ++i)
  {
    bird[i].is_killed = false;
    bird[i].setVisibility(true);
    bird[i].is_released = false;
  }

  bird[0].getSprite()->setPosition(
    slingshot.getGlobalBounds().width/2 + 260,
    slingshot.getGlobalBounds().height/2 + 380);

  bird[1].getSprite()->setPosition(
    bird[2].getSprite()->getGlobalBounds().width/2 + 100,
    bird[2].getSprite()->getGlobalBounds().height/2 + 550);

  bird[2].getSprite()->setPosition(
    bird[2].getSprite()->getGlobalBounds().width/2 + 20,
    bird[2].getSprite()->getGlobalBounds().height/2 + 550);

  bird_blast_radius.setPosition(-500,-500);
  bird_blast_rect.top = 0;
  bird_blast_rect.left = 0;
  effect[3].setVisibility(false);

  obstacle[0].setVisibility(true);
  obstacle[1].getSprite()->setPosition(
    obstacle[1].getSprite()->getGlobalBounds().width/2 + 650,
    obstacle[1].getSprite()->getGlobalBounds().height/2 + 252);

}


void Game::collision(float dt)
{
  for (int j = 0; j < pig_max; j++)
  {
    if (pig[j].getVisibility())
    {
      // blast collision with pig
      if (bird_blast_radius.getGlobalBounds().intersects(pig[j].getSprite()->getGlobalBounds()))
      {
        sound[0].getAudio()->play();
        pig[j].setVisibility(false);
        score += 100;

        pig_blast_rect[j].left = 0;
        pig_blast_rect[j].top  = 0;
        animation_clock.restart();
      }

      // bird collision with pig
      if (bird[bird_type].getSprite()->getGlobalBounds().intersects(pig[j].getSprite()->getGlobalBounds()))
      {
        if (bird[bird_type].getVisibility())
        {
          sound[0].getAudio()->play();
          pig[j].setVisibility(false);
          score += 100;

          pig_blast_rect[j].left = 0;
          pig_blast_rect[j].top  = 0;
          animation_clock.restart();
        }
      }

      // bird collision with glass
      if (bird[bird_type].getSprite()->getGlobalBounds().intersects(obstacle[0].getSprite()->getGlobalBounds()))
      {
        if (bird[bird_type].getVisibility())
        {
          if (obstacle[0].getVisibility())
          {
            sound[3].getAudio()->play();
            obstacle[0].setVisibility(false);
            score += 20;
          }
        }
      }

      // rock collision with pig
      if (obstacle[1].getSprite()->getGlobalBounds().intersects(pig[j].getSprite()->getGlobalBounds()))
      {
        if (pig[j].getVisibility())
        {
          sound[0].getAudio()->play();
          pig[j].setVisibility(false);
          score += 100;

          pig_blast_rect[j].left = 0;
          pig_blast_rect[j].top  = 0;
          animation_clock.restart();
        }
      }

      // rock movement
      if (!obstacle[0].getVisibility())
      {
        obstacle-> speed = 50;
        obstacle[1].getSprite()->move(0,1 * (obstacle -> speed + clock.getElapsedTime().asSeconds() * 100) * dt );
      }

      // bird collision with red bounce collider
      if (bird[bird_type].getSprite()->getGlobalBounds().intersects(collider.getGlobalBounds()))
      {
        if (bird[bird_type].getVisibility())
        {
          if (bird[bird_type].direction.x >= 0)
          {
            bounce = true;
            sound[4].getAudio()->play();
          }
        }
      }
    }
  }
}


void Game::playEffect()
{
  // init clocks
  sf::Time explosion_clock = animation_clock.getElapsedTime();
  sf::Time bird_blast_clock = power_clock.getElapsedTime();

  // pig explosion texture sprite
  if (explosion_clock.asSeconds() > 0.1)
  {
    for (int i = 0; i < pig_max ; i++)
    {
      if (!pig[i].getVisibility())
      {
        effect[i].getSprite()->setTextureRect(pig_blast_rect[i]);
      }
      pig_blast_rect[i].left += pig_blast_texture.getSize().x/3;
      if (pig_blast_rect[i].left > pig_blast_texture.getSize().x/3*2)
      {
        pig_blast_rect[i].left = 0;
        pig_blast_rect[i].top = pig_blast_rect[i].top + pig_blast_texture.getSize().y/3;
      }
    }
    animation_clock.restart();
  }

  // bird explosion texture sprite
  if (bird_3_power)
  {
    effect[3].getSprite()->setPosition(bird[2].getSprite()->getPosition().x - 250 ,bird[2].getSprite()->getPosition().y - 250);

    // init bird blast radius
    bird_blast_radius.setRadius(150);
    bird_blast_radius.setPointCount(100);
    bird_blast_radius.setFillColor(sf::Color(255,0,0,60));

    bird_blast_radius.setPosition(bird_3_x_pos - bird_blast_radius.getRadius(),
                                  bird_3_y_pos - bird_blast_radius.getRadius());

    if (bird_blast_clock.asSeconds() > 0.01)
    {
      effect[3].getSprite()->setTextureRect(bird_blast_rect);

      bird_blast_rect.left += bird_blast_texture.getSize().x/8;
      if (bird_blast_rect.left > bird_blast_texture.getSize().x/8*7)
      {
        bird_blast_rect.left = 0;
        bird_blast_rect.top = bird_blast_rect.top + bird_blast_texture.getSize().y/8;
      }
      power_clock.restart();
    }

    // kill bird after explosion and remove blast radius
    if (bird_blast_rect.top > bird_blast_texture.getSize().y/8*9)
    {
      bird[2].is_killed = true;
      bird_blast_radius.setFillColor(sf::Color(255,0,0,0));
    }
  }

}


void Game::dragBird()
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  // distance of middle of bird boundary to mouse click position
  int distance_x = bird_boundary.getPosition().x - click.x;
  int distance_y = bird_boundary.getPosition().y - click.y;

  // total length of the vector
  int total_distance = sqrt(pow(distance_x , 2) + pow(distance_y , 2));

  Vector2 distance(distance_x,distance_y);
  distance.normalise();

  // set bird as mouse click position
  bird[bird_type].getSprite()->setPosition(click.x, click.y);

  // bird out of right slingshot boundary
  if (bird[bird_type].getSprite()->getPosition().x >= (slingshot.getGlobalBounds().width/2 + 260))
  {
    // limit right slingshot boundary movement
    bird[bird_type].getSprite()->setPosition(slingshot.getGlobalBounds().width/2 + 260, click.y);
  }

  // bird out of boundary check
  if (total_distance >= max_distance)
  {
    out_of_boundary = true;
  }
  else
  {
    out_of_boundary = false;
  }

  // limit circle boundary movement
  if (out_of_boundary == true)
  {
    // limit bird to circle
    bird[bird_type].getSprite()->setPosition(bird_boundary.getPosition().x - (distance.x * max_distance) , bird_boundary.getPosition().y - (distance.y * max_distance));

    // limit right side slingshot boundary movement
    if (bird[bird_type].getSprite()->getPosition().x >= (slingshot.getGlobalBounds().width/2 + 260))
    {
      bird[bird_type].getSprite()->setPosition(slingshot.getGlobalBounds().width/2 + 260, bird_boundary.getPosition().y - (distance.y * max_distance));
    }
  }
}


void Game::updateScore()
{
  // updating score
  std::string new_score = std::to_string(score);
  score_text.setString("Score: "+ new_score);

  // win condition
  if (score >= 300)
  {
    player_win = true;
    player_lose = false;
  }

  // lose condition
  if (score < 300 && bird_left == 0)
  {
    player_win = false;
    player_lose = true;
  }
}
