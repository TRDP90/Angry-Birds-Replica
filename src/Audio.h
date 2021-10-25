//
// Created by trdp9 on 28/04/2021.
//

#ifndef ANGRYBIRDSSFML_AUDIO_H
#define ANGRYBIRDSSFML_AUDIO_H
#include <SFML/Audio.hpp>

class Audio
{
 public:
  Audio();
  ~Audio();
  bool initialiseSound(sf::SoundBuffer &sound_buffer, std::string filename);
  sf::Sound* getAudio();

 private:
  sf::Sound* sound = nullptr;
};

#endif // ANGRYBIRDSSFML_AUDIO_H
