/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ncurse
*/
#ifndef LIBCACA_HPP_
#define LIBCACA_HPP_
#include <caca.h>
#include <caca++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "../IGraphicLib.hpp"

namespace Arcade {
    class libcaca : public IGraphicLib {
        public:
            libcaca();
            ~libcaca();
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
