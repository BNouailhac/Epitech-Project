/*
** EPITECH PROJECT, 2020
** my_map.hpp
** File description:
** my_map
*/

#ifndef _MY_MAP_HPP_
#define _MY_MAP_HPP_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

class My_map
{
    public:
        My_map(int mode);
        ~My_map();

        void print_map(void);
        void fill_empty_map(void);
        int **get_map(void);
        void fill_full_map(void);
        void fill_random_map(void);
        
        int my_map[11][11];
        int posY;
        int posX;
};

#endif
