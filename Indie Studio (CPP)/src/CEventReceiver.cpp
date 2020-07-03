/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CEventReceiver
*/
#include "../include/CEventReceiver.hpp"
//#include "../include/my_music.hpp"

extern My_map *map;
extern int nb_joueur;
//extern My_music *music;

CEventReceiver::CEventReceiver(std::vector<indie*> player, bool coop) {
    mplayer = player;
    mplayer[0]->living = true;
    mplayer[1]->living = true;
    mplayer[0]->time = 0;
    mplayer[1]->time = 0;
    mplayer[0]->oldtime = 0;
    mplayer[1]->oldtime = 0;
    a = 0;
    mplayer[0]->Bonus = 0;
    mplayer[1]->Bonus = 0;
    this->coop = coop;
    _menuChoice = ButtonMenu::NONE;
    mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_STAND);
    mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_STAND);
    //Par defaut on ne bouge pas
}

bool CEventReceiver::OnEvent(const irr::SEvent &event)
{
    //event clavier
    if(mplayer[0]->mesh != 0 //On verifie que le pointeur est ok
    && event.EventType == irr::EET_KEY_INPUT_EVENT //Qu'il s'agit d'un event concernant un appui/relachement de touche
    && event.KeyInput.Key == irr::KEY_KEY_Z && mplayer[0]->living) //Qu'il s'agit de la touche z
    {
        if (mplayer[0]->anim != 1)
            mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        input = irr::KEY_KEY_Z;
        mplayer[0]->m_isMoving = event.KeyInput.PressedDown; //On assigne la bonne valeur directement
        mplayer[0]->anim = 1;
        return true; //L'event est traite, on retourne true
    }
    if(mplayer[0]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_S && mplayer[0]->living)
    {
        if (mplayer[0]->anim != 1)
            mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        input = irr::KEY_KEY_S;
        mplayer[0]->anim = 1;
        mplayer[0]->m_isMoving = event.KeyInput.PressedDown;
        return true;
    }
    if(mplayer[0]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_Q && mplayer[0]->living)
    {
        if (mplayer[0]->anim != 1)
            mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        mplayer[0]->anim = 1;
        input = irr::KEY_KEY_Q;
        mplayer[0]->m_isMoving = event.KeyInput.PressedDown;
        return true;
    }
    if(mplayer[0]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_D && mplayer[0]->living)
    {
        if (mplayer[0]->anim != 1)
            mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        mplayer[0]->anim = 1;
        input = irr::KEY_KEY_D;
        mplayer[0]->m_isMoving = event.KeyInput.PressedDown;
        return true;
    }
    if (mplayer[0]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_E && mplayer[0]->bomb_active == false && mplayer[0]->living) //touche pour poser bombe
    {
        if (mplayer[0]->anim != 2)
            mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_CROUCH_STAND);
        mplayer[0]->anim = 2;
        input = irr::KEY_KEY_E;
        mplayer[0]->m_isMoving = event.KeyInput.PressedDown;
        return true;
    }
    if(event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_P) //touche pour poser bombe
    {
        input = irr::KEY_KEY_P;  
    }
    if (coop) {
        if(mplayer[1]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_I && mplayer[1]->living)
        {
            if (mplayer[1]->anim != 1)
                mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
            input = irr::KEY_KEY_I;
            mplayer[1]->m_isMoving = event.KeyInput.PressedDown;
            mplayer[1]->anim = 1;
            return true;
        }
        if(mplayer[1]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_K && mplayer[1]->living)
        {
            if (mplayer[1]->anim != 1)
                mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
            input = irr::KEY_KEY_K;
            mplayer[1]->anim = 1;
            mplayer[1]->m_isMoving = event.KeyInput.PressedDown;
            return true;
        }
        if(mplayer[1]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_J && mplayer[1]->living)
        {
            if (mplayer[1]->anim != 1)
                mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
            mplayer[1]->anim = 1;
            input = irr::KEY_KEY_J;
            mplayer[1]->m_isMoving = event.KeyInput.PressedDown;
            return true;
        }
        if(mplayer[1]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_L && mplayer[1]->living)
        {
            if (mplayer[1]->anim != 1)
                mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_RUN);
            mplayer[1]->anim = 1;
            input = irr::KEY_KEY_L;
            mplayer[1]->m_isMoving = event.KeyInput.PressedDown;
            return true;
        }
        if(mplayer[1]->mesh != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_KEY_O && mplayer[1]->bomb_active == false && mplayer[1]->living) //touche pour poser bombe
        {
            if (mplayer[1]->anim != 2)
                mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_CROUCH_STAND);
            mplayer[1]->anim = 2;
            input = irr::KEY_KEY_O;
            mplayer[1]->m_isMoving = event.KeyInput.PressedDown;
            return true;
        }
    }
    //Si on arrive la, c'est qu'on a pas traite l'event
    return false;
}
 
void CEventReceiver::majPosMesh(irr::ITimer *timer)
{
    mplayer[0]->time++;
    mplayer[1]->time++;
        //On verifie que le pointeur vers le mesh est
        //ok et que la touche est enfoncee
        if(mplayer[0]->mesh != 0 && mplayer[0]->m_isMoving == true) {
            //On commence par recuperer la position actuelle
            irr::core::vector3df v = mplayer[0]->mesh->getPosition();
            irr::core::vector3df v2 = mplayer[0]->mesh->getPosition();
            irr::core::vector3df e = mplayer[0]->mesh->getPosition();
            irr::core::vector3df R = mplayer[0]->mesh->getRotation();

            //On y ajoute la valeur de deplacement
            if (input == irr::KEY_KEY_Z && map->my_map[mplayer[0]->posy - 1][mplayer[0]->posx] == 0) {
                v.X += 10.0f;
                R.Y = 0;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                mplayer[0]->posy -= 1;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                if (mplayer[0]->Bonus == 2 && map->my_map[mplayer[0]->posy - 1][mplayer[0]->posx] == 0) {
                v.X += 10.0f;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                mplayer[0]->posy -= 1;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                }
            }
            if (input == irr::KEY_KEY_S && map->my_map[mplayer[0]->posy + 1][mplayer[0]->posx] == 0) {
                v.X -= 10.0f;
                R.Y = 200;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                mplayer[0]->posy += 1;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                if (mplayer[0]->Bonus == 2 && map->my_map[mplayer[0]->posy + 1][mplayer[0]->posx] == 0) {
                v.X -= 10.0f;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                mplayer[0]->posy += 1;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                }
            }
            if (input == irr::KEY_KEY_Q && map->my_map[mplayer[0]->posy][mplayer[0]->posx - 1] == 0) {
                v.Z += 10.0f;
                R.Y = -100;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                mplayer[0]->posx -= 1;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                if (mplayer[0]->Bonus == 2 && map->my_map[mplayer[0]->posy][mplayer[0]->posx - 1] == 0) {
                    v.Z += 10.0f;
                    map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                    mplayer[0]->posx -= 1;
                    map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                }
            }
            if (input == irr::KEY_KEY_D && map->my_map[mplayer[0]->posy][mplayer[0]->posx + 1] == 0) {
                v.Z -= 10.0f;
                R.Y = 100;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                mplayer[0]->posx += 1;
                map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                if (mplayer[0]->Bonus == 2 && map->my_map[mplayer[0]->posy][mplayer[0]->posx + 1] == 0) {
                    v.Z -= 10.0f;
                    map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 0;
                    mplayer[0]->posx += 1;
                    map->my_map[mplayer[0]->posy][mplayer[0]->posx] = 3;
                }
            }
            if (input == irr::KEY_KEY_E) {
                int i = 0;
                if (R.Y == 0) {
                    i = 1;
                //  e.X += 10.0f;
                    mplayer[0]->bombX = mplayer[0]->posx;
                    mplayer[0]->bombY = mplayer[0]->posy;
                } if (R.Y == 200) {
                    i = 1;
                //  e.X -= 10.0f;
                    mplayer[0]->bombX = mplayer[0]->posx;
                    mplayer[0]->bombY = mplayer[0]->posy;
                } if (R.Y == -100) {
                    i = 1;
                //  e.Z += 10.0f;
                    mplayer[0]->bombX = mplayer[0]->posx;
                    mplayer[0]->bombY = mplayer[0]->posy;
                } if (R.Y == 100) {
                    i = 1;
                //  e.Z -= 10.0f;
                    mplayer[0]->bombX = mplayer[0]->posx;
                    mplayer[0]->bombY = mplayer[0]->posy;
                }
                if (i == 1) {
                    mplayer[0]->bomb->setVisible(true);
                    mplayer[0]->bomb->setPosition(e);
                    v2 = e;
                    mplayer[0]->explotion[0]->setPosition(e);
                    e.X += 10.0f;
                    mplayer[0]->explotion[1]->setPosition(e);
                    e.X += 10.0f;
                    mplayer[0]->explotion[5]->setPosition(e);
                    e = v2;
                    e.X -= 10.0f;
                    mplayer[0]->explotion[2]->setPosition(e);
                    e.X -= 10.0f;
                    mplayer[0]->explotion[6]->setPosition(e);
                    e = v2;
                    e.Z += 10.0f;
                    mplayer[0]->explotion[3]->setPosition(e);
                    e.Z += 10.0f;
                    mplayer[0]->explotion[7]->setPosition(e);
                    e = v2;
                    e.Z -= 10.0f;
                    mplayer[0]->explotion[4]->setPosition(e);
                    e.Z -= 10.0f;
                    mplayer[0]->explotion[8]->setPosition(e);
                    e = v2;
                    mplayer[0]->oldtime = mplayer[0]->time;
                    mplayer[0]->bomb_active = true;
                }
            }
            //On renvoie la nouvelle position
            mplayer[0]->mesh->setPosition(v);
            mplayer[0]->mesh->setRotation(R);
        } else {
            if (mplayer[0]->anim != 0 && mplayer[0]->living)
                mplayer[0]->mesh->setMD2Animation(irr::scene::EMAT_STAND);
            mplayer[0]->anim = 0;
        }
        if (mplayer[0]->bomb_active && (mplayer[0]->time - mplayer[0]->oldtime) >= 80) {
            mplayer[0]->bomb->setVisible(false);
            //music->play_explosion();
            mplayer[0]->explotion[0]->setVisible(true);
            mplayer[0]->explotion[1]->setVisible(true);
            mplayer[0]->explotion[2]->setVisible(true);
            mplayer[0]->explotion[3]->setVisible(true);
            mplayer[0]->explotion[4]->setVisible(true);
            if (mplayer[0]->Bonus == 1) {
                mplayer[0]->explotion[5]->setVisible(true);
                mplayer[0]->explotion[6]->setVisible(true);
                mplayer[0]->explotion[7]->setVisible(true);
                mplayer[0]->explotion[8]->setVisible(true);
            }
            if (a == 0) {
                a = 1;
                //destruction block
                if (map->my_map[mplayer[0]->bombY - 1][mplayer[0]->bombX] == 2) {
                    map->my_map[mplayer[0]->bombY - 1][mplayer[0]->bombX] = 0;
                    for (int i = 0; i != 121; i++) {
                        if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY - 1))
                            mplayer[0]->MapCube[i]->mesh->setVisible(false);
                    }
                    //BOnus
                    int brps = rand() >> 4, urps;
                    brps = brps % 5 + 1;
                    if (brps == 1) {
                        mplayer[0]->Bonus = 1;
                    }
                    if (brps == 2) {
                        mplayer[0]->Bonus = 2;
                    }
                    if (brps == 3) {
                        mplayer[0]->Bonus = 3;
                    }
                    if (brps == 4) {
                    }
                    if (brps == 5) {
                    }
                } if (map->my_map[mplayer[0]->bombY + 1][mplayer[0]->bombX] == 2) {
                    map->my_map[mplayer[0]->bombY + 1][mplayer[0]->bombX] = 0;
                    for (int i = 0; i != 121; i++) {
                        if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY + 1))
                            mplayer[0]->MapCube[i]->mesh->setVisible(false);
                    }
                    int brps = rand() >> 4, urps;
                    brps = brps % 5 + 1;
                    if (brps == 1) {
                        mplayer[0]->Bonus = 1;
                    }
                    if (brps == 2) {
                        mplayer[0]->Bonus = 2;
                    }
                    if (brps == 3) {
                        mplayer[0]->Bonus = 3;
                    }
                    if (brps == 4) {
                    }
                    if (brps == 5) {
                    }
                } if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 1] == 2) {
                    map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 1] = 0;
                    for (int i = 0; i != 121; i++) {
                        if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX - 1) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY))
                            mplayer[0]->MapCube[i]->mesh->setVisible(false);
                    }
                    int brps = rand() >> 4, urps;
                    brps = brps % 5 + 1;
                    if (brps == 1) {
                        mplayer[0]->Bonus = 1;
                    }
                    if (brps == 2) {
                        mplayer[0]->Bonus = 2;
                    }
                    if (brps == 3) {
                        mplayer[0]->Bonus = 3;
                    }
                    if (brps == 4) {
                    }
                    if (brps == 5) {
                    }
                } if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 1] == 2) {
                    map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 1] = 0;
                    for (int i = 0; i != 121; i++) {
                        if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX + 1) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY))
                            mplayer[0]->MapCube[i]->mesh->setVisible(false);
                    }
                    int brps = rand() >> 4, urps;
                    brps = brps % 5 + 1;
                    if (brps == 1) {
                        mplayer[0]->Bonus = 1;
                    }
                    if (brps == 2) {
                        mplayer[0]->Bonus = 2;
                    }
                    if (brps == 3) {
                        mplayer[0]->Bonus = 3;
                    }
                    if (brps == 4) {
                    }
                    if (brps == 5) {
                    }
                }

                //destruction joueur
                if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX] == 3) {
                    //music->play_death();
                    for (int i = 0; i != 5;) {
                        if (((mplayer[0]->bombY) == (mplayer[i]->posy)) && ((mplayer[0]->bombX) == (mplayer[i]->posx))) {
                            if (mplayer[i]->Bonus == 3) {
                                mplayer[i]->Bonus = 0;
                            } else if (mplayer[i]->Bonus != 3) {
                                mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                mplayer[i]->living = false;
                                nb_joueur -= 1;
                                map->my_map[mplayer[0]->bombY][mplayer[0]->bombX] = 0;
                            }
                        }
                        i++;
                    }
                } else if (map->my_map[mplayer[0]->bombY - 1][mplayer[0]->bombX] == 3) {
                    //music->play_death();
                    for (int i = 0; i != 5;) {
                        if (((mplayer[0]->bombY - 1) == (mplayer[i]->posy)) && ((mplayer[0]->bombX) == (mplayer[i]->posx))) {
                            if (mplayer[i]->Bonus == 3) {
                                mplayer[i]->Bonus = 0;
                            } else if (mplayer[i]->Bonus != 3) {
                                mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                mplayer[i]->living = false;
                                nb_joueur -= 1;
                                map->my_map[mplayer[0]->bombY - 1][mplayer[0]->bombX] = 0;
                            }
                        }
                        i++;
                    }
                } else if (map->my_map[mplayer[0]->bombY + 1][mplayer[0]->bombX] == 3) {
                    //music->play_death();
                    for (int i = 0; i != 5;) {
                        if (((mplayer[0]->bombY + 1) == (mplayer[i]->posy)) && ((mplayer[0]->bombX) == (mplayer[i]->posx))) {
                            if (mplayer[i]->Bonus == 3) {
                                mplayer[i]->Bonus = 0;
                            } else if (mplayer[i]->Bonus != 3) {
                                mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                mplayer[i]->living = false;
                                map->my_map[mplayer[0]->bombY + 1][mplayer[0]->bombX] = 0;
                                nb_joueur -= 1;
                            }
                        }
                        i++;
                    }
                } else if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 1] == 3) {
                    //music->play_death();
                    for (int i = 0; i != 5;) {
                        if (((mplayer[0]->bombY) == (mplayer[i]->posy)) && ((mplayer[0]->bombX - 1) == (mplayer[i]->posx))) {
                            if (mplayer[i]->Bonus == 3) {
                                mplayer[i]->Bonus = 0;
                            } else if (mplayer[i]->Bonus != 3) {
                                mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                mplayer[i]->living = false;
                                map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 1] = 0;
                                nb_joueur -= 1;
                            }
                        }
                        i++;
                    }
                } else if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 1] == 3) {
                    //music->play_death();
                    for (int i = 0; i != 5;) {
                        if (((mplayer[0]->bombY) == (mplayer[i]->posy)) && ((mplayer[0]->bombX + 1) == (mplayer[i]->posx))) {
                            if (mplayer[i]->Bonus == 3) {
                                mplayer[i]->Bonus = 0;
                            } else if (mplayer[i]->Bonus != 3) {
                                mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                mplayer[i]->living = false;
                                map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 1] = 0;
                                nb_joueur -= 1;
                            }
                        }
                        i++;
                    }
                }
                if (mplayer[0]->Bonus == 1) {
                        if (map->my_map[mplayer[0]->bombY - 2][mplayer[0]->bombX] == 2) {
                            map->my_map[mplayer[0]->bombY - 2][mplayer[0]->bombX] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY - 2))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        } if (map->my_map[mplayer[0]->bombY + 2][mplayer[0]->bombX] == 2) {
                            map->my_map[mplayer[0]->bombY + 2][mplayer[0]->bombX] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY + 2))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        } if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 2] == 2) {
                            map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 2] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX - 2) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        } if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 2] == 2) {
                            map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 2] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[0]->bombX + 2) && mplayer[0]->MapCube[i]->posy == (mplayer[0]->bombY))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        }

                        //destruction joueur
                        if (map->my_map[mplayer[0]->bombY - 2][mplayer[0]->bombX] == 3) {
                            //music->play_death();
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[0]->bombY - 2) == (mplayer[i]->posy)) && ((mplayer[0]->bombX) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[0]->bombY - 2][mplayer[0]->bombX] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        } if (map->my_map[mplayer[0]->bombY + 2][mplayer[0]->bombX] == 3) {
                            //music->play_death();
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[0]->bombY + 2) == (mplayer[i]->posy)) && ((mplayer[0]->bombX) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[0]->bombY + 2][mplayer[0]->bombX] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        } if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 2] == 3) {
                            //music->play_death();
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[0]->bombY) == (mplayer[i]->posy)) && ((mplayer[0]->bombX - 2) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[0]->bombY][mplayer[0]->bombX - 2] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        } if (map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 2] == 3) {
                            //music->play_death();
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[0]->bombY) == (mplayer[i]->posy)) && ((mplayer[0]->bombX + 2) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[0]->bombY][mplayer[0]->bombX + 2] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        }
                }
            }
        }
        if (mplayer[0]->bomb_active && (mplayer[0]->time - mplayer[0]->oldtime) >= 90) {
            a = 0;
            mplayer[0]->bomb_active = false;
            mplayer[0]->explotion[0]->setVisible(false);
            mplayer[0]->explotion[1]->setVisible(false);
            mplayer[0]->explotion[2]->setVisible(false);
            mplayer[0]->explotion[3]->setVisible(false);
            mplayer[0]->explotion[4]->setVisible(false);
            mplayer[0]->explotion[5]->setVisible(false);
            mplayer[0]->explotion[6]->setVisible(false);
            mplayer[0]->explotion[7]->setVisible(false);
            mplayer[0]->explotion[8]->setVisible(false);
            mplayer[0]->time = 0;
        }
        if (coop) {
            if(mplayer[1]->mesh != 0 && mplayer[1]->m_isMoving == true) {
                //On commence par recuperer la position actuelle
                irr::core::vector3df v = mplayer[1]->mesh->getPosition();
                irr::core::vector3df v2 = mplayer[1]->mesh->getPosition();
                irr::core::vector3df e = mplayer[1]->mesh->getPosition();
                irr::core::vector3df R = mplayer[1]->mesh->getRotation();

                //On y ajoute la valeur de deplacement
                if (input == irr::KEY_KEY_I && map->my_map[mplayer[1]->posy - 1][mplayer[1]->posx] == 0) {
                    v.X += 10.0f;
                    R.Y = 0;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                    mplayer[1]->posy -= 1;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    if (mplayer[1]->Bonus == 2 && map->my_map[mplayer[1]->posy - 1][mplayer[1]->posx] == 0) {
                        v.X += 10.0f;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                        mplayer[1]->posy -= 1;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    }
                }
                if (input == irr::KEY_KEY_K && map->my_map[mplayer[1]->posy + 1][mplayer[1]->posx] == 0) {
                    v.X -= 10.0f;
                    R.Y = 200;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                    mplayer[1]->posy += 1;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    if (mplayer[1]->Bonus == 2 && map->my_map[mplayer[1]->posy + 1][mplayer[1]->posx] == 0) {
                        v.X -= 10.0f;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                        mplayer[1]->posy += 1;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    }
                }
                if (input == irr::KEY_KEY_J && map->my_map[mplayer[1]->posy][mplayer[1]->posx - 1] == 0) {
                    v.Z += 10.0f;
                    R.Y = -100;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                    mplayer[1]->posx -= 1;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    if (mplayer[1]->Bonus == 2 && map->my_map[mplayer[1]->posy][mplayer[1]->posx - 1] == 0) {
                        v.Z += 10.0f;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                        mplayer[1]->posx -= 1;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    }
                }
                if (input == irr::KEY_KEY_L && map->my_map[mplayer[1]->posy][mplayer[1]->posx + 1] == 0) {
                    v.Z -= 10.0f;
                    R.Y = 100;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                    mplayer[1]->posx += 1;
                    map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    if (mplayer[1]->Bonus == 2 && map->my_map[mplayer[1]->posy][mplayer[1]->posx + 1] == 0) {
                        v.Z -= 10.0f;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 0;
                        mplayer[1]->posx += 1;
                        map->my_map[mplayer[1]->posy][mplayer[1]->posx] = 3;
                    }
                }
                if (input == irr::KEY_KEY_O) {
                    int i = 0;
                    if (R.Y == 0) {
                        i = 1;
                    //  e.X += 10.0f;
                        mplayer[1]->bombX = mplayer[1]->posx;
                        mplayer[1]->bombY = mplayer[1]->posy;
                    } if (R.Y == 200) {
                        i = 1;
                    //  e.X -= 10.0f;
                        mplayer[1]->bombX = mplayer[1]->posx;
                        mplayer[1]->bombY = mplayer[1]->posy;
                    } if (R.Y == -100) {
                        i = 1;
                    //  e.Z += 10.0f;
                        mplayer[1]->bombX = mplayer[1]->posx;
                        mplayer[1]->bombY = mplayer[1]->posy;
                    } if (R.Y == 100) {
                        i = 1;
                    //  e.Z -= 10.0f;
                        mplayer[1]->bombX = mplayer[1]->posx;
                        mplayer[1]->bombY = mplayer[1]->posy;
                    }
                    if (i == 1) {
                        mplayer[1]->bomb->setVisible(true);
                        mplayer[1]->bomb->setPosition(e);
                        v2 = e;
                        mplayer[1]->explotion[0]->setPosition(e);
                        e.X += 10.0f;
                        mplayer[1]->explotion[1]->setPosition(e);
                        e.X += 10.0f;
                        mplayer[1]->explotion[5]->setPosition(e);
                        e = v2;
                        e.X -= 10.0f;
                        mplayer[1]->explotion[2]->setPosition(e);
                        e.X -= 10.0f;
                        mplayer[1]->explotion[6]->setPosition(e);
                        e = v2;
                        e.Z += 10.0f;
                        mplayer[1]->explotion[3]->setPosition(e);
                        e.Z += 10.0f;
                        mplayer[1]->explotion[7]->setPosition(e);
                        e = v2;
                        e.Z -= 10.0f;
                        mplayer[1]->explotion[4]->setPosition(e);
                        e.Z -= 10.0f;
                        mplayer[1]->explotion[8]->setPosition(e);
                        e = v2;
                        mplayer[1]->oldtime = mplayer[1]->time;
                        mplayer[1]->bomb_active = true;
                    }
                }
                //On renvoie la nouvelle position
                mplayer[1]->mesh->setPosition(v);
                mplayer[1]->mesh->setRotation(R);
            } else {
                if (mplayer[1]->anim != 0 && mplayer[1]->living)
                    mplayer[1]->mesh->setMD2Animation(irr::scene::EMAT_STAND);
                mplayer[1]->anim = 0;
            }
            if (mplayer[1]->bomb_active && (mplayer[1]->time - mplayer[1]->oldtime) >= 80) {
                mplayer[1]->bomb->setVisible(false);
                //music->play_explosion();
                mplayer[1]->explotion[0]->setVisible(true);
                mplayer[1]->explotion[1]->setVisible(true);
                mplayer[1]->explotion[2]->setVisible(true);
                mplayer[1]->explotion[3]->setVisible(true);
                mplayer[1]->explotion[4]->setVisible(true);
                if (mplayer[1]->Bonus == 1) {
                    mplayer[1]->explotion[5]->setVisible(true);
                    mplayer[1]->explotion[6]->setVisible(true);
                    mplayer[1]->explotion[7]->setVisible(true);
                    mplayer[1]->explotion[8]->setVisible(true);
                }
                if (a == 0) {
                    a = 1;
                    //destruction block
                    if (map->my_map[mplayer[1]->bombY - 1][mplayer[1]->bombX] == 2) {
                        map->my_map[mplayer[1]->bombY - 1][mplayer[1]->bombX] = 0;
                        for (int i = 0; i != 121; i++) {
                            if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY - 1))
                                mplayer[0]->MapCube[i]->mesh->setVisible(false);
                        }
                        //BOnus
                        int brps = rand() >> 4, urps;
                        brps = brps % 5 + 1;
                        if (brps == 1) {
                            mplayer[1]->Bonus = 1;
                        }
                        if (brps == 2) {
                            mplayer[1]->Bonus = 2;
                        }
                        if (brps == 3) {
                            mplayer[1]->Bonus = 3;
                        }
                        if (brps == 4) {
                        }
                        if (brps == 5) {
                        }
                    } if (map->my_map[mplayer[1]->bombY + 1][mplayer[1]->bombX] == 2) {
                        map->my_map[mplayer[1]->bombY + 1][mplayer[1]->bombX] = 0;
                        for (int i = 0; i != 121; i++) {
                            if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY + 1))
                                mplayer[0]->MapCube[i]->mesh->setVisible(false);
                        }
                        int brps = rand() >> 4, urps;
                        brps = brps % 5 + 1;
                        if (brps == 1) {
                            mplayer[1]->Bonus = 1;
                        }
                        if (brps == 2) {
                            mplayer[1]->Bonus = 2;
                        }
                        if (brps == 3) {
                            mplayer[1]->Bonus = 3;
                        }
                        if (brps == 4) {
                        }
                        if (brps == 5) {
                        }
                    } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 1] == 2) {
                        map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 1] = 0;
                        for (int i = 0; i != 121; i++) {
                            if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX - 1) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY))
                                mplayer[0]->MapCube[i]->mesh->setVisible(false);
                        }
                        int brps = rand() >> 4, urps;
                        brps = brps % 5 + 1;
                        if (brps == 1) {
                            mplayer[1]->Bonus = 1;
                        }
                        if (brps == 2) {
                            mplayer[1]->Bonus = 2;
                        }
                        if (brps == 3) {
                            mplayer[1]->Bonus = 3;
                        }
                        if (brps == 4) {
                        }
                        if (brps == 5) {
                        }
                    } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 1] == 2) {
                        map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 1] = 0;
                        for (int i = 0; i != 121; i++) {
                            if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX + 1) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY))
                                mplayer[0]->MapCube[i]->mesh->setVisible(false);
                        }
                        int brps = rand() >> 4, urps;
                        brps = brps % 5 + 1;
                        if (brps == 1) {
                            mplayer[1]->Bonus = 1;
                        }
                        if (brps == 2) {
                            mplayer[1]->Bonus = 2;
                        }
                        if (brps == 3) {
                            mplayer[1]->Bonus = 3;
                        }
                        if (brps == 4) {
                        }
                        if (brps == 5) {
                        }
                    }

                    //destruction joueur
                    if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX] == 3) {
                    //music->play_death();
                    for (int i = 0; i != 5;) {
                        if (((mplayer[1]->bombY) == (mplayer[i]->posy)) && ((mplayer[1]->bombX) == (mplayer[i]->posx))) {
                            if (mplayer[i]->Bonus == 3) {
                                mplayer[i]->Bonus = 0;
                            } else if (mplayer[i]->Bonus != 3) {
                                mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                mplayer[i]->living = false;
                                nb_joueur -= 1;
                                map->my_map[mplayer[1]->bombY][mplayer[1]->bombX] = 0;
                            }
                        }
                        i++;
                    }
                } else if (map->my_map[mplayer[1]->bombY - 1][mplayer[1]->bombX] == 3) {
                        for (int i = 0; i != 4; i++)
                            if (((mplayer[1]->bombY - 1) == (mplayer[i]->posy)) && ((mplayer[1]->bombX) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY - 1][mplayer[1]->bombX] = 0;
                                        nb_joueur -= 1;
                                    }
                            }
                    } if (map->my_map[mplayer[1]->bombY + 1][mplayer[1]->bombX] == 3) {
                        for (int i = 0; i != 4; i++)
                            if (((mplayer[1]->bombY + 1) == (mplayer[i]->posy)) && ((mplayer[1]->bombX) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY + 1][mplayer[1]->bombX] = 0;
                                        nb_joueur -= 1;
                                    }
                            }
                    } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 1] == 3) {
                        for (int i = 0; i != 4; i++)
                            if (((mplayer[1]->bombY) == (mplayer[i]->posy)) && ((mplayer[1]->bombX - 1) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 1] = 0;
                                        nb_joueur -= 1;
                                    }
                            }
                    } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 1] == 3) {
                        for (int i = 0; i != 4; i++)
                            if (((mplayer[1]->bombY) == (mplayer[i]->posy)) && ((mplayer[1]->bombX + 1) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 1] = 0;
                                        nb_joueur -= 1;
                                    }
                            }
                    }
                    if (mplayer[1]->Bonus == 1) {
                        if (map->my_map[mplayer[1]->bombY - 2][mplayer[1]->bombX] == 2) {
                            map->my_map[mplayer[1]->bombY - 2][mplayer[1]->bombX] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY - 2))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        } if (map->my_map[mplayer[1]->bombY + 2][mplayer[1]->bombX] == 2) {
                            map->my_map[mplayer[1]->bombY + 2][mplayer[1]->bombX] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY + 2))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 2] == 2) {
                            map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 2] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX - 2) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 2] == 2) {
                            map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 2] = 0;
                            for (int i = 0; i != 121; i++) {
                                if (mplayer[0]->MapCube[i]->posx == (mplayer[1]->bombX + 2) && mplayer[0]->MapCube[i]->posy == (mplayer[1]->bombY))
                                    mplayer[0]->MapCube[i]->mesh->setVisible(false);
                            }
                        }

                        //destruction jouedur
                        if (map->my_map[mplayer[1]->bombY - 2][mplayer[1]->bombX] == 3) {
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[1]->bombY - 2) == (mplayer[i]->posy)) && ((mplayer[1]->bombX) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY - 2][mplayer[1]->bombX] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        } if (map->my_map[mplayer[1]->bombY + 2][mplayer[1]->bombX] == 3) {
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[1]->bombY + 2) == (mplayer[i]->posy)) && ((mplayer[1]->bombX) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY + 2][mplayer[1]->bombX] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 2] == 3) {
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[1]->bombY) == (mplayer[i]->posy)) && ((mplayer[1]->bombX - 2) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY][mplayer[1]->bombX - 2] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        } if (map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 2] == 3) {
                            for (int i = 0; i != 4; i++)
                                if (((mplayer[1]->bombY) == (mplayer[i]->posy)) && ((mplayer[1]->bombX + 2) == (mplayer[i]->posx))) {
                                    if (mplayer[i]->Bonus == 3) {
                                        mplayer[i]->Bonus = 0;
                                    } else {
                                        mplayer[i]->mesh->setMD2Animation(irr::scene::EMAT_BOOM);
                                        mplayer[i]->living = false;
                                        map->my_map[mplayer[1]->bombY][mplayer[1]->bombX + 2] = 0;
                                        nb_joueur -= 1;
                                    }
                                }
                        }
                    }
                }
            }
            if (mplayer[1]->bomb_active && (mplayer[1]->time - mplayer[1]->oldtime) >= 90) {
                a = 0;
                mplayer[1]->bomb_active = false;
                mplayer[1]->explotion[0]->setVisible(false);
                mplayer[1]->explotion[1]->setVisible(false);
                mplayer[1]->explotion[2]->setVisible(false);
                mplayer[1]->explotion[3]->setVisible(false);
                mplayer[1]->explotion[4]->setVisible(false);
                mplayer[1]->explotion[5]->setVisible(false);
                mplayer[1]->explotion[6]->setVisible(false);
                mplayer[1]->explotion[7]->setVisible(false);
                mplayer[1]->explotion[8]->setVisible(false);
                mplayer[1]->time = 0;
            }
        }
}
