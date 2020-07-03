/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ncurse
*/
#include "sdl.hpp"
#include <ncurses.h>
#include <curses.h>
Uint32	_resetTicks;
SDL_Surface *ecran = NULL, *texte2, *fond = NULL;
SDL_Rect position;
SDL_Event event;
TTF_Font *police = NULL;
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};

Arcade::sdl::sdl()
{
    open = false;
}

Arcade::sdl::~sdl()
{
}

void apply_surface (int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL) {

    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, clip, ecran, &offset);
}

bool Arcade::sdl::openWindow(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    ecran = SDL_SetVideoMode(1000, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Game", NULL);
    fond = IMG_Load("Graphic/SDL/grey.jpg");
    police = TTF_OpenFont("Graphic/SDL/Apple.ttf", 25);
    return (true);
}

bool Arcade::sdl::isOpen(void)
{
    return (this->open);
}

void Arcade::sdl::drawWindow(std::vector<std::string> game)
{
    std::vector<SDL_Surface*> texte;
    
    for (unsigned int i = 0; i < game.size(); i++) {
       texte2 = TTF_RenderText_Blended(police, game[i].c_str(), couleurNoire);
       texte.push_back(texte2);
    }
    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(fond, NULL, ecran, &position);

    for (unsigned int i = 0; i < texte.size(); i++) {
        apply_surface(200, 10 + (i * 30) , texte[i], ecran);
    }
    SDL_Flip(ecran);
}

Arcade::Events Arcade::sdl::getEvents(void)
{
    return (NONE);
}

bool Arcade::sdl::closeWindow(void)
{
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();

    return (true);
}

Arcade::Events Arcade::sdl::getKeyPressed(void)
{
    SDL_Event	event;
	
    while (!SDL_PollEvent(&event));
	if (event.type == SDL_QUIT)
		return (CLOSE);
    if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_LEFT) {
                return (LEFT);
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                return (RIGHT);
            }
            if (event.key.keysym.sym == SDLK_UP) {
                return (UP);
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                return (DOWN);
            }
            if (event.key.keysym.sym == SDLK_e) {
                return (NEXTGAME);
            }
            if (event.key.keysym.sym == SDLK_q) {
                return (CLOSE);
            }
            if (event.key.keysym.sym == SDLK_l) {
                return (NEXTLIB);
            }
            if (event.key.keysym.sym == SDLK_c) {
                return (MENU);
            }
            if (event.key.keysym.sym == SDLK_p) {
                return (PAUSE);
            }
        }
    /*SDL_Event event;
    SDL_WaitEvent(&event);
    if (SDL_PollEvent(&event)) {
        if(event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_LEFT) {
                return (LEFT);
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                return (RIGHT);
            }
            if (event.key.keysym.sym == SDLK_UP) {
                return (UP);
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                return (DOWN);
            }
            if (event.key.keysym.sym == SDLK_e) {
                return (NEXTGAME);
            }
            if (event.key.keysym.sym == SDLK_q) {
                return (NEXTGAME);
            }
        }
    }
    switch(event.type) {
        case SDL_QUIT:
            return (CLOSE);
    }*/
    /*int ch = getch();

    switch(ch) {
        case KEY_LEFT:
            return (LEFT);
        case KEY_RIGHT:
            return (RIGHT);
        case KEY_UP:
            return (UP);
        case KEY_DOWN:
            return (DOWN);
        case 'q':
            return (CLOSE);
        case 'e':
            return (NEXTGAME);
        return (NONE);
    }*/
    return (NONE);
}