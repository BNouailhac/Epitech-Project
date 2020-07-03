/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GameLibLoader
*/

#include "GameLibLoader.hpp"

Arcade::GameLibLoader::GameLibLoader() : libPath(""), handleAddr(),
			       entryPointResult(), isLibLoaded(false)
{
	this->handleAddr = nullptr;
	this->entryPointResult = nullptr;
}

Arcade::GameLibLoader::~GameLibLoader()
{
}

Arcade::IGameLib *Arcade::GameLibLoader::getLibInstance()
{
	return (this->entryPointResult);
}

bool Arcade::GameLibLoader::loadLib(const std::string &libPath)
{
    std::string tmp;
    Arcade::IGameLib *(*ret)() = nullptr;

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
