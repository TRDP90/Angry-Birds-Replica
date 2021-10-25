//
// Created by trdp9 on 28/04/2021.
//

#include "Audio.h"
#include "iostream"
Audio::Audio()
{
  sound = new sf::Sound;
}

Audio::~Audio()
{
}

sf::Sound* Audio::getAudio()
{
  return sound;
}

bool Audio::initialiseSound(sf::SoundBuffer& sound_buffer, std::string filename)
{
  //init Sound
  if(!sound_buffer.loadFromFile(filename))
  {
    std::cout << "Sound did not load\n";
  }
  sound->setBuffer(sound_buffer);
  return true;
}
