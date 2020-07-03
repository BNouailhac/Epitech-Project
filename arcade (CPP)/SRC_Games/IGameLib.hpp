/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** IGameLib
*/

#ifndef IGAMELIB_HPP_
#define IGAMELIB_HPP_
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "../Graphic/IGraphicLib.hpp"

namespace Arcade {

    class IGameLib {
        public:
            virtual ~IGameLib() = default;
            virtual bool DoAction(Events) = 0;
            virtual std::vector<std::string> GetMap() = 0;
        protected:
        private:
    };
}

#endif /* !IGAMELIB_HPP_ */
