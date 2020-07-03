/*
** EPITECH PROJECT, 2020
** my_music.hpp
** File description:
** my_music
*/

#ifndef _MY_MUSIC_HPP_
#define _MY_MUSIC_HPP_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <SFML/Audio.hpp>

class My_music
{
    public:
        My_music();
        ~My_music();

        void play_menu();
        void play_game();
        void play_explosion();
        void play_death();
        void stop_menu();
        void stop_game();

        sf::SoundBuffer menuBuff;
        sf::SoundBuffer gameBuff;
        sf::SoundBuffer explosionBuff;
        sf::SoundBuffer deathBuff;
        sf::Sound menuSound;
        sf::Sound gameSound;
        sf::Sound explosionSound;
        sf::Sound deathSound;
};

#endif
