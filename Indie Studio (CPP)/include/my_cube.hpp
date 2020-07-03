/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** my_cube
*/

#ifndef MY_CUBE_HPP_
#define MY_CUBE_HPP_
#include "irr/irrlicht.h"

class My_cube
{
    public:
        My_cube();
        ~My_cube();
        int posx;
        int posy;
        irr::scene::IAnimatedMeshSceneNode* mesh;
};

#endif /* !MY_CUBE_HPP_ */
