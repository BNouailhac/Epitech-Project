/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ncurse
*/
#ifndef SDL_HPP_
#define SDL_HPP_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "../IGraphicLib.hpp"

namespace Arcade {
    class sdl : public IGraphicLib {
        public:
            sdl();
            ~sdl();
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
