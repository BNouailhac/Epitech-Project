/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Arcade
*/
#include "Arcade.hpp"

int pos = 0;
int grap;

Arcade::Core::Core(const std::string &libPath) : selectedLib(libPath)
{
	if (this->selectedLib == "./lib/libncurse.so")
		grap = 0;
	if (this->selectedLib == "./lib/libsdl.so")
		grap = 1;
	if (this->selectedLib == "./lib/liblibcaca.so")
		grap = 2;
    //this->parseLibDir();
}

void Arcade::Core::parseLibDir()
{
	struct dirent **namelist;
	int n = scandir("./libs", &namelist, nullptr, alphasort);
    std::regex REGEX("^[a-zA-Z0-9_]*.so");

	if (n < 0) {
		perror("scandir");
		return;
	}
	for (int i = 0 ; i < n ; i++) {
		std::cmatch cm;
		std::string name = namelist[i]->d_name;
		if (std::regex_match(name.c_str(), cm, REGEX) &&
		    std::find(this->libraryPathes.begin(),
			      this->libraryPathes.end(), "./lib/" + name) ==
		    this->libraryPathes.end()) {
			this->libraryPathes.push_back("./lib/" + name);
		}
		free(namelist[i]);
	}
}

Arcade::Core::~Core()
{
}

int Arcade::Core::start()
{
    if (!this->graphLoader.loadLib(this->selectedLib))
		return (84);
    this->graphlib = this->graphLoader.getLibInstance();

	this->menu();
}

void Arcade::Core::menu()
{
	bool ctn = true;
	Events event;
	static std::vector<std::string> Game = {
	"UP and DOWN of your Keybord to chose and E to lunch the game",
	"or L to change library",
    "-> SNAKE",
    "   PACMAN"};

    this->graphlib->openWindow();

	while (ctn) {
		this->graphlib->drawWindow(Game);

		event = this->graphlib->getKeyPressed();

		if (event == UP) {
			Game = {
			"UP and DOWN of your Keybord to chose and E to lunch the game",
			"or L to change library",
			"-> SNAKE",
			"   PACMAN"};
			pos = 0;
		}
		if (event == DOWN) {
			Game = {
			"UP and DOWN of your Keybord to chose and E to lunch the game",
			"or L to change library",
			"   SNAKE",
			"-> PACMAN"};
			pos = 1;
		}
		if (event == NEXTGAME) {
			if (pos == 0) {
				this->gameLoader.loadLib("./games/lib_arcade_nibbler.so");
				this->gamelib = this->gameLoader.getLibInstance();
				this->game();
			}
			else if (pos == 1) {
				this->gameLoader.loadLib("./games/lib_arcade_pacman.so");
				this->gamelib = this->gameLoader.getLibInstance();
				this->game();
			}
		}
		if (event == NEXTLIB) {
			if (grap == 0) {
				grap = 1;
				this->graphlib->closeWindow();
				dlclose(graphlib);
				this->graphLoader.loadLib("./lib/libsdl.so");
				this->graphlib = this->graphLoader.getLibInstance();
				this->graphlib->openWindow();
			}
			else if (grap == 1) {
				grap = 2;
				this->graphlib->closeWindow();
				dlclose(graphlib);
				this->graphLoader.loadLib("./lib/liblibcaca.so");
				this->graphlib = this->graphLoader.getLibInstance();
				this->graphlib->openWindow();
			}
			else if (grap == 2) {
				grap = 0;
				this->graphlib->closeWindow();
				dlclose(graphlib);
				this->graphLoader.loadLib("./lib/libncurse.so");
				this->graphlib = this->graphLoader.getLibInstance();
				this->graphlib->openWindow();
			}
		}
		if (event == CLOSE) {
			ctn = false;
		}
	}
	this->graphlib->closeWindow();
	dlclose(graphlib);
}

void Arcade::Core::game()
{
	bool ctn = true;
	Events event;

	while (ctn) {
		this->graphlib->drawWindow(this->gamelib->GetMap());

		event = this->graphlib->getKeyPressed();

		if (event == NEXTGAME) {
			if (pos == 1 ){
				pos = 0;
				this->gameLoader.loadLib("./games/lib_arcade_nibbler.so");
				this->gamelib = this->gameLoader.getLibInstance();
				this->game();
			}
			else if (pos == 0 ) {
				pos = 1;
				this->gameLoader.loadLib("./games/lib_arcade_pacman.so");
				this->gamelib = this->gameLoader.getLibInstance();
				this->game();
			}
		}
		if (event == NEXTLIB) {
			if (grap == 0) {
				grap = 1;
				this->graphlib->closeWindow();
				dlclose(graphlib);
				this->graphLoader.loadLib("./lib/libsdl.so");
				this->graphlib = this->graphLoader.getLibInstance();
				this->graphlib->openWindow();
			}
			else if (grap == 1) {
				grap = 2;
				this->graphlib->closeWindow();
				dlclose(graphlib);
				this->graphLoader.loadLib("./lib/liblibcaca.so");
				this->graphlib = this->graphLoader.getLibInstance();
				this->graphlib->openWindow();
			}
			else if (grap == 2) {
				grap = 0;
				this->graphlib->closeWindow();
				dlclose(graphlib);
				this->graphLoader.loadLib("./lib/libncurse.so");
				this->graphlib = this->graphLoader.getLibInstance();
				this->graphlib->openWindow();
			}
		}
		if (event == CLOSE) {
			this->graphlib->closeWindow();
			dlclose(graphlib);
			exit(0);
		}
		if (event == MENU) {
			ctn = false;
		}


		this->gamelib->DoAction(event);
	}
}
