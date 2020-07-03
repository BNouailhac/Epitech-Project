/*
** EPITECH PROJECT, 2020
** Snake.hpp
** File description:
** Snake.hpp
*/
#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#include <list>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../IGameLib.hpp"

namespace Arcade {

    class Snake : public IGameLib {
        public:
            Snake();
            ~Snake();
            bool DoAction(Events);
            std::vector<std::string> GetMap();
        protected:
        private:
    };
}

void game(int dir);
#endif