/*
** EPITECH PROJECT, 2020
** my_map.cpp
** File description:
** my_map
*/

#include "../include/my_map.hpp"

My_map::My_map(int mode)
{
    int choice = 0;

    if (mode == 0) {           //mode 0 = map predefinis
        if (choice == 0) {
            fill_empty_map();
        } else if (choice == 1) {
            fill_full_map();
        }
    } else if (mode == 1) {    //mode 1 = map au hasard
        fill_random_map();
    }
    //print_map();
}

My_map::~My_map(void)
{
    delete this;
}

void My_map::print_map(void)
{
    for (int iterator = 0; iterator < 11; iterator++) {
        for (int iterator2 = 0; iterator2 < 11; iterator2++) {
            if (iterator2 == 10) {
                std::cout << this->my_map[iterator][iterator2] << std::endl;
            } else {
                std::cout << this->my_map[iterator][iterator2] << ", ";
            }
        }
    }
}

void My_map::fill_empty_map(void)
{
    for (int iterator = 0; iterator < 11; iterator++) {
        this->my_map[0][iterator] = 1;
        this->my_map[10][iterator] = 1;
        if (iterator == 0 || iterator == 10) {
            this->my_map[1][iterator] = 1;
            this->my_map[2][iterator] = 1;
            this->my_map[3][iterator] = 1;
            this->my_map[4][iterator] = 1;
            this->my_map[5][iterator] = 1;
            this->my_map[6][iterator] = 1;
            this->my_map[7][iterator] = 1;
            this->my_map[8][iterator] = 1;
            this->my_map[9][iterator] = 1;
        } else {
            this->my_map[1][iterator] = 0;
            this->my_map[3][iterator] = 0;
            this->my_map[5][iterator] = 0;
            this->my_map[7][iterator] = 0;
            this->my_map[9][iterator] = 0;
            if ((iterator % 2) == 0) {
                this->my_map[2][iterator] = 1;
                this->my_map[4][iterator] = 1;
                this->my_map[6][iterator] = 1;
                this->my_map[8][iterator] = 1;
            } else {
                this->my_map[2][iterator] = 0;
                this->my_map[4][iterator] = 0;
                this->my_map[6][iterator] = 0;
                this->my_map[8][iterator] = 0;
            }
        }
    }
    /*
    0 = vide
    1 = bloc incassable
    2 = bloc cassable
    3 = joueur

    int my_map[11][11] = {                   // Le code au dessus donne cette map
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    }
    */
}

void My_map::fill_full_map(void)
{
    for (int iterator = 0; iterator < 11; iterator++) {
        this->my_map[0][iterator] = 1;
        this->my_map[10][iterator] = 1;
        if (iterator == 0 || iterator == 10) {
            this->my_map[1][iterator] = 1;
            this->my_map[2][iterator] = 1;
            this->my_map[3][iterator] = 1;
            this->my_map[4][iterator] = 1;
            this->my_map[5][iterator] = 1;
            this->my_map[6][iterator] = 1;
            this->my_map[7][iterator] = 1;
            this->my_map[8][iterator] = 1;
            this->my_map[9][iterator] = 1;
        } else {
            this->my_map[3][iterator] = 2;
            this->my_map[5][iterator] = 2;
            this->my_map[7][iterator] = 2;
            this->my_map[1][iterator] = 2;
            this->my_map[9][iterator] = 2;
            if (iterator < 3 || iterator > 7) {
                this->my_map[1][iterator] = 0;
                this->my_map[9][iterator] = 0;
            }
            if ((iterator % 2) == 0) {
                this->my_map[2][iterator] = 1;
                this->my_map[4][iterator] = 1;
                this->my_map[6][iterator] = 1;
                this->my_map[8][iterator] = 1;
            } else {
                this->my_map[2][iterator] = 2;
                this->my_map[4][iterator] = 2;
                this->my_map[6][iterator] = 2;
                this->my_map[8][iterator] = 2;
            }
        }
    }
    this->my_map[2][1] = 0;
    this->my_map[2][9] = 0;
    this->my_map[8][1] = 0;
    this->my_map[8][9] = 0;
    /*
    0 = vide
    1 = bloc incassable
    2 = bloc cassable
    3 = joueur

    int my_map[11][11] = {                   // Le code au dessus donne cette map
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 0, 0, 2, 2, 2, 2, 2, 0, 0, 1},
        { 1, 0, 1, 2, 1, 2, 1, 2, 1, 0, 1},
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        { 1, 0, 1, 2, 1, 2, 1, 2, 1, 0, 1},
        { 1, 0, 0, 2, 2, 2, 2, 2, 0, 0, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    */
}

void My_map::fill_random_map(void)
{
    fill_full_map();
    for (int i = 0; i < 11; i++) {
        for (int i2 = 0; i2 < 11; i2++) {
            if (this->my_map[i][i2] == 2) {
                this->my_map[i][i2] = (rand() > RAND_MAX / 2) ? 0 : 2;
            }
        }
    }
}