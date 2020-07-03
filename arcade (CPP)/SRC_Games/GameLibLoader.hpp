/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GameLibLoader
*/
#ifndef GAMELIBLOADER_HPP_
#define GAMELIBLOADER_HPP_
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <fstream>
#include "IGameLib.hpp"

namespace Arcade {
    class GameLibLoader {
        public:
            GameLibLoader();
            ~GameLibLoader();
            bool loadLib(const std::string &libPath);
            IGameLib *getLibInstance();

        protected:
        private:
            std::string libPath;
            void *handleAddr;
            IGameLib *entryPointResult;
            bool isLibLoaded;
    };
}

#endif /* !GAMELIBLOADER_HPP_ */
