/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** plazza
*/
#ifndef INDIE_HPP
#define INDIE_HPP
#include "irr/irrlicht.h"
#include "my_cube.hpp"
#include "my_map.hpp"
#include <string>
#include <cstring>
#include <vector>
#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ITimer.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>

class indie {
    public:
        indie();
        ~indie();
        int posx;
        int posy;
        int time;
        int oldtime;
        int bombX;
        int bombY;
        int Bonus;
        int anim;
        bool living;
        bool bomb_active;
        bool m_isMoving;
        std::vector<My_cube*> MapCube;
        int p;
        std::vector<irr::video::ITexture*> image;
        std::vector<irr::scene::IAnimatedMeshSceneNode*> explotion;
        irr::scene::IAnimatedMeshSceneNode *bomb;
        irr::scene::IAnimatedMeshSceneNode* mesh;
};

int main();
#endif
