/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CEventReceiver
*/
#include "irr/irrlicht.h"
#include "indie.hpp"
#include "my_map.hpp"
#include <string>
#include <cstring>
#include <vector>
#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <ITimer.h>
#include <stdio.h>

enum ButtonMenu
{
    NONE,
    PLAY,
    HELP,
    OPTIONS,
    HOME,
    EXIT,
    BACK,
    RESUME,
};

class CEventReceiver : public irr::IEventReceiver {
public :
    //Le constructeur
    CEventReceiver(std::vector<indie*> player, bool coop);
    virtual bool OnEvent(const irr::SEvent &event); //Capte automatiquement les events.
    void majPosMesh(irr::ITimer *timer); //Met a jour la position du mesh.
private :
    ButtonMenu _menuChoice;
    std::vector<indie*> mplayer;
    irr::IrrlichtDevice *device;
    bool coop;
    int a;
    irr::EKEY_CODE input;
};