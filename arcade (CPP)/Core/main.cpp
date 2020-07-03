/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/
#include "Arcade.hpp"

int main(int ac, char **av)
{
	std::string path;

	if (ac != 2) {
		std::cout << "Usage: ./arcade ./lib/[GraphicalLib].so" << std::endl;
		return (84);
	}
	path = av[1];
	std::ifstream lib(path);
	if (lib.fail()) {
		std::cout << "Invalid library" << std::endl;
		return (84);
	}
	Arcade::Core core(av[1]);
	return core.start();
}