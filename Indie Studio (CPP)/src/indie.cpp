/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** indie
*/
#include "../include/indie.hpp"

indie::indie() {
    this->Bonus = 0;
    this->anim = 0;
    this->p = 0;
    this->living = true;
    bomb_active = false;
    m_isMoving = false;
}

indie::~indie() {
}