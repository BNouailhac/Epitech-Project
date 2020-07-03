/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GraphLibLoader
*/

#include "GraphLibLoader.hpp"

Arcade::GraphLibLoader::GraphLibLoader() : libPath(""), handleAddr(),
			       entryPointResult(), isLibLoaded(false)
{
	this->handleAddr = nullptr;
	this->entryPointResult = nullptr;
}

Arcade::GraphLibLoader::~GraphLibLoader()
{
}

Arcade::IGraphicLib *Arcade::GraphLibLoader::getLibInstance()
{
	return (this->entryPointResult);
}

bool Arcade::GraphLibLoader::loadLib(const std::string &libPath)
{
    std::string tmp;
    Arcade::IGraphicLib *(*ret)() = nullptr;

    if ((this->handleAddr = dlopen(libPath.c_str(), RTLD_LAZY))) {
		*(void **) (&ret) = dlsym(this->handleAddr, "entryPoint");
		if (!ret)
            return (false);
		this->entryPointResult = ret();
        return (true);
	}
    else
		std::cout << dlerror() << std::endl;
    return (false);
}
