/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ncurse
*/
#include "ncurse.hpp"

Arcade::ncurse::ncurse()
{
    open = false;
}

Arcade::ncurse::~ncurse()
{
}

bool Arcade::ncurse::openWindow(void)
{
    open = true;
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    return (true);
}

bool Arcade::ncurse::isOpen(void)
{
    return (this->open);
}

void Arcade::ncurse::drawWindow(std::vector<std::string> game)
{
    erase();
    for (unsigned int i = 0; i < game.size(); i++) {
        mvprintw(10 + i, 50, game[i].c_str());
    }
    refresh();
}

Arcade::Events Arcade::ncurse::getEvents(void)
{
    return (NONE);
}

bool Arcade::ncurse::closeWindow(void)
{
    open = false;
    erase();
    refresh();
    getch();
    endwin();
    return (true);
}

Arcade::Events Arcade::ncurse::getKeyPressed(void)
{
    int ch = getch();

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
        case 'l':
            return (NEXTLIB);
        case 'p':
            return (PAUSE);
        case 'c':
            return (MENU);
        return (NONE);
    }
    return (NONE);
}