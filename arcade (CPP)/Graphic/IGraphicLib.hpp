/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** IGraphicLib
*/

#ifndef IGRAPHICLIB_HPP_
#define IGRAPHICLIB_HPP_
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <fstream>

namespace Arcade {
    enum Events
    {
        CLOSE,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        NEXTLIB,
        NEXTGAME,
        PREVGAME,
        PAUSE,
        MENU,
        NONE
    };

    class IGraphicLib {
        public:
            virtual ~IGraphicLib() = default;
            virtual bool openWindow(void) = 0;
            virtual bool isOpen(void) = 0;
            virtual void drawWindow(std::vector<std::string>) = 0;
            virtual Arcade::Events getEvents(void) = 0;
            virtual bool closeWindow(void) = 0;
            virtual Arcade::Events getKeyPressed(void) = 0;
        protected:
        private:
    };
}

#endif /* !IGRAPHICLIB_HPP_ */
