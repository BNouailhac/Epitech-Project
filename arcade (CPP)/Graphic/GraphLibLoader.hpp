/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GraphLibLoader
*/

#ifndef GRAPHLIBLOADER_HPP_
#define GRAPHLIBLOADER_HPP_
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <fstream>
#include "IGraphicLib.hpp"

namespace Arcade {
    class GraphLibLoader {
        public:
            GraphLibLoader();
            ~GraphLibLoader();
            bool loadLib(const std::string &libPath);
            IGraphicLib *getLibInstance();

        protected:
        private:
            std::string libPath;
            void *handleAddr;
            IGraphicLib *entryPointResult;
            bool isLibLoaded;
    };
}

#endif /* !GRAPHLIBLOADER_HPP_ */
