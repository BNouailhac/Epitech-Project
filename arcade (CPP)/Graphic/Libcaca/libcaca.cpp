/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ncurse
*/
#include "libcaca.hpp"

Event* _event;
caca_event_t *ev;
Caca* _caca;
caca_canvas_t *cv;
caca_display_t *dp;
std::vector<std::string> game2;
int width;
int height;

Arcade::libcaca::libcaca()
{
    open = false;
}

Arcade::libcaca::~libcaca()
{
}

bool Arcade::libcaca::openWindow(void)
{
    open = true;
    cv = caca_create_canvas(width, height);
    dp = caca_create_display(cv);   
    caca_set_display_title(dp, "Game");
    width = width;
    height = height;
    return (true);
}

bool Arcade::libcaca::isOpen(void)
{
    return (this->open);
}

void Arcade::libcaca::drawWindow(std::vector<std::string> game)
{
    if (game2 != game)
        caca_clear_canvas(cv);
    game2 = game;
    for (unsigned int i = 0; i < game.size(); i++) {
        caca_put_str(cv, 15 , 10 + i, game[i].c_str());
    }
    caca_refresh_display(dp);
}

Arcade::Events Arcade::libcaca::getEvents(void)
{
    return (NONE);
}

bool Arcade::libcaca::closeWindow(void)
{
    open = false;
    caca_free_display(dp);
    return (true);
}

Arcade::Events Arcade::libcaca::getKeyPressed(void)
{
    caca_event_t event;

	if (caca_get_event(dp, CACA_EVENT_KEY_PRESS, &event, 0) == 1)
		switch (caca_get_event_key_ch(&event)) {
            case CACA_KEY_UP :
                return (UP);
            case CACA_KEY_DOWN :
                return (DOWN);
            case CACA_KEY_LEFT :
                return (LEFT);
            case CACA_KEY_RIGHT :
                return (RIGHT);
            case 'c' :
                return (MENU);
            case 'e' :
                return (NEXTGAME);
            case 'l' :
                return (NEXTLIB);
            case 'p' :
                return (PAUSE);
            case 'q' :
                return (CLOSE);
            default :
                return (NONE);
		}
    return (NONE);
}