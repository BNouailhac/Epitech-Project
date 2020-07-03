/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Arcade
*/
#ifndef ARCADE_HPP_
#define ARCADE_HPP_
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <fstream>
#include "../Graphic/GraphLibLoader.hpp"
#include "../Graphic/IGraphicLib.hpp"
#include "../SRC_Games/GameLibLoader.hpp"
#include "../SRC_Games/IGameLib.hpp"

namespace Arcade {
    class Core {
	public:
        Core(const std::string &libPath);
		~Core();
        void parseLibDir();
        bool loadLib(const std::string libPath);
        int start();
        void menu();
        void game();
    protected:
        GraphLibLoader graphLoader;
        GameLibLoader gameLoader;
        std::string selectedLib;
        std::vector<std::string> libraryPathes;
        std::string libPath;
		IGraphicLib *graphlib;
        IGameLib *gamelib;
		bool isLibLoaded;
    };
}

#endif /* !ARCADE_HPP_ */
