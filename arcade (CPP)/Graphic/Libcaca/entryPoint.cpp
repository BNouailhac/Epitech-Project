/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** entryPoint.cpp
*/
#include <iostream>
#include "libcaca.hpp"

Arcade::IGraphicLib *ret = nullptr;

__attribute__((constructor))
void enter()
{
	ret = new Arcade::libcaca();
}

__attribute__((destructor))
void out()
{
	delete ret;
}

extern "C" Arcade::IGraphicLib *entryPoint()
{
	return ret;
}
