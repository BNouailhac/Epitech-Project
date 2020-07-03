/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ncurse
*/
#ifndef NCURSE_HPP_
#define NCURSE_HPP_
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
#include <ncurses.h>
#include <curses.h>
#include "../IGraphicLib.hpp"

namespace Arcade {
    class ncurse : public IGraphicLib {
        public:
            ncurse();
            ~ncurse();
            bool openWindow(void);
            bool isOpen(void);
            void drawWindow(std::vector<std::string>);
            Arcade::Events getEvents(void);
            bool closeWindow(void);
            Arcade::Events getKeyPressed(void);
        protected:
            bool open;
        private:
    };
}
#endif /* !NCURSE_HPP_ */
