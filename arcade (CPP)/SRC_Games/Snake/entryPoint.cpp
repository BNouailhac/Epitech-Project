/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** entryPoint
*/
#include <iostream>
#include "Snake.hpp"

Arcade::IGameLib *ret = nullptr;

__attribute__((constructor))
void enter()
{
	ret = new Arcade::Snake();
}

__attribute__((destructor))
void out()
{
	delete ret;
}

extern "C" Arcade::IGameLib *entryPoint()
{
	return ret;
}