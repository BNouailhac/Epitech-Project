/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** main
*/
#include "../include/indie.hpp"
#include "../include/CEventReceiver.hpp"
//#include "../include/my_music.hpp"
#include "../include/irr/irrlicht.h"
#include "../include/my_cube.hpp"
#include <ITimer.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>

My_map *map;
//My_music *music;
int nb_joueur = 4;

void ia_move(indie *player, std::vector<indie*> mplayer)
{
    player->time++;
    irr::core::vector3df v = player->mesh->getPosition();
    irr::core::vector3df v2 = player->mesh->getPosition();
    irr::core::vector3df e = player->mesh->getPosition();
    irr::core::vector3df R = player->mesh->getRotation();
    int brps = rand() >> 4;
    brps = brps % 5 + 1;
 
    if (brps == 1 && map->my_map[player->posy - 1][player->posx] == 0 && player->living) {
        v.X += 10.0f;
        R.Y = 0;
        map->my_map[player->posy][player->posx] = 0;
        player->posy -= 1;
        map->my_map[player->posy][player->posx] = 3;
        if (player->anim == 0) {
            player->anim = 1;
            player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        }
    }
    if (brps == 2 && map->my_map[player->posy + 1][player->posx] == 0 && player->living) {
        v.X -= 10.0f;
        R.Y = 200;
        map->my_map[player->posy][player->posx] = 0;
        player->posy += 1;
        map->my_map[player->posy][player->posx] = 3;
        player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        if (player->anim == 0) {
            player->anim = 1;
            player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        }
    }
    if (brps == 3 && map->my_map[player->posy][player->posx - 1] == 0 && player->living) {
        v.Z += 10.0f;
        R.Y = -100;
        map->my_map[player->posy][player->posx] = 0;
        player->posx -= 1;
        map->my_map[player->posy][player->posx] = 3;
        player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        if (player->anim == 0) {
            player->anim = 1;
            player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        }
    }
    if (brps == 4 && map->my_map[player->posy][player->posx + 1] == 0 && player->living) {
        v.Z -= 10.0f;
        R.Y = 100;
        map->my_map[player->posy][player->posx] = 0;
        player->posx += 1;
        map->my_map[player->posy][player->posx] = 3;
        player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        if (player->anim == 0) {
            player->anim = 1;
            player->mesh->setMD2Animation(irr::scene::EMAT_RUN);
        }
    }
    if (brps == 5) {
    }
    player->mesh->setPosition(v);
    player->mesh->setRotation(R);
}

void scaleNode(irr::scene::IAnimatedMeshSceneNode* mesh, irr::f32 desiredX)
{
    irr::core::vector3df extent = mesh->getTransformedBoundingBox().getExtent();
    irr::f32 factor = desiredX/extent.X;
    irr::core::vector3d<irr::f32> factorEscalate(factor,factor,factor);
    mesh->setScale(factorEscalate);
}

void game(std::vector<indie*> player, bool coop, irr::video::IVideoDriver* driver, irr::IrrlichtDevice* device, irr::scene::ISceneManager *sceneManager)
{
    //music->stop_menu();
    //music->play_game();
    int i = 0;
    //On cree le capteur d'event et on l'associe au device.
    CEventReceiver receiver(player, coop);
    device->setEventReceiver(&receiver);
    irr::video::ITexture *image;
    if (coop)
        image = driver->getTexture("recources/ciel étoilé1.jpg");
    if (!coop)
        image = driver->getTexture("recources/ciel étoilé2.jpg");
    scaleNode(player[0]->mesh, 9.0f);
    scaleNode(player[1]->mesh, 8.0f);
    scaleNode(player[2]->mesh, 8.0f);
    scaleNode(player[3]->mesh, 8.0f);
    for (int y = 0; y != 11 ;y++) {
        for (int x = 0; x != 11; x++) {
            if (map->my_map[y][x] == 0) {
                
            } else {
                irr::scene::IAnimatedMesh* mesh = sceneManager->getMesh("recources/dest.cube.obj"); // tu mets ton obj ici
                irr::scene::IAnimatedMeshSceneNode* Cube = sceneManager->addAnimatedMeshSceneNode(mesh);
                if (map->my_map[y][x] == 1) {
                    Cube->setMaterialTexture( 0, driver->getTexture("recources/rockwall.jpg"));
                    Cube->setVisible(true);
                }
                else if (map->my_map[y][x] == 2) {
                    Cube->setMaterialTexture( 0, driver->getTexture("recources/ter.jpg"));
                    Cube->setVisible(true);
                } else {
                    Cube->setMaterialTexture( 0, driver->getTexture("recources/ter.jpg"));
                    Cube->setVisible(false);
                }
                Cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                Cube->setPosition(irr::core::vector3df(40.0f - (10.0f * y), 0.0f, 40.0f - (10.0f * x)));
                scaleNode(Cube, 10.0f);
                player[0]->MapCube[i]->mesh = Cube;
                player[0]->MapCube[i]->posx = x;
                player[0]->MapCube[i]->posy = y;
                i++;
            }
        }
    }
    irr::scene::IAnimatedMesh* mesh2 = sceneManager->getMesh("recources/dest.cube.obj"); // tu mets ton obj ici
    irr::scene::IAnimatedMeshSceneNode* Cube2 = sceneManager->addAnimatedMeshSceneNode(mesh2);
    Cube2->setMaterialTexture( 0, driver->getTexture("recources/wall.bmp"));
    Cube2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Cube2->setPosition(irr::core::vector3df(-15.0f, -90.0f, -10.0f));
    scaleNode(Cube2, 120.0f);
    device->getGUIEnvironment()->clear();
    irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();
    irr::gui::IGUIButton *mon_bouton1 = guienv->addButton(irr::core::rect<irr::s32>(730, 645,930,730), 0, ButtonMenu::PLAY, L"HOME");

    //La boucle de rendu
    while (device->run())
    {
    try{
        driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
        receiver.majPosMesh(device->getTimer());
        driver->draw2DImage(image, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(0,0,1500,900), 0, irr::video::SColor (255,255,255,255), true);
            if (nb_joueur <= 1) {
                device->getCursorControl()->setVisible(true);
                if (player[1]->living) {
                    if (coop)
                        image = driver->getTexture("recources/finj2.jpg");
                    else
                        image = driver->getTexture("recources/finIA1.jpg"); 
                }
                else if (player[2]->living) {
                    if (coop)
                        image = driver->getTexture("recources/finIA1.jpg");
                    else
                        image = driver->getTexture("recources/finIA2.jpg"); 
                }
                else if (player[3]->living) {
                    if (coop)
                        image = driver->getTexture("recources/finIA2.jpg");
                    else
                        image = driver->getTexture("recources/finIA3.jpg"); 
                } else
                {
                    image = driver->getTexture("recources/finj1.jpg");
                }
                
                if (mon_bouton1->isPressed())
                    break;
                //Victoire
            } else {
                ia_move(player[2], player);
                ia_move(player[3], player);
                if (coop) {

                } else
                    ia_move(player[1], player);
                if (!player[0]->living)
                    driver->draw2DImage(player[0]->image[0], irr::core::position2d<irr::s32>(20,0), irr::core::rect<irr::s32>(0,0,150,150), 0, irr::video::SColor (255,255,255,255), true);
                if (player[0]->Bonus == 1)
                    driver->draw2DImage(player[0]->image[1], irr::core::position2d<irr::s32>(310,70), irr::core::rect<irr::s32>(0,0,60,60), 0, irr::video::SColor (255,255,255,255), true);
                if (player[0]->Bonus == 2)
                    driver->draw2DImage(player[0]->image[2], irr::core::position2d<irr::s32>(310,70), irr::core::rect<irr::s32>(0,0,60,60), 0, irr::video::SColor (255,255,255,255), true);
                if (player[0]->Bonus == 3)
                    driver->draw2DImage(player[0]->image[3], irr::core::position2d<irr::s32>(310,70), irr::core::rect<irr::s32>(0,0,60,60), 0, irr::video::SColor (255,255,255,255), true);
                if (!player[1]->living)
                    driver->draw2DImage(player[1]->image[0], irr::core::position2d<irr::s32>(1300,0), irr::core::rect<irr::s32>(0,0,150,150), 0, irr::video::SColor (255,255,255,255), true);
                if (player[1]->Bonus == 1)
                    driver->draw2DImage(player[1]->image[1], irr::core::position2d<irr::s32>(1130,70), irr::core::rect<irr::s32>(0,0,60,60), 0, irr::video::SColor (255,255,255,255), true);
                if (player[1]->Bonus == 2)
                    driver->draw2DImage(player[1]->image[2], irr::core::position2d<irr::s32>(1130,70), irr::core::rect<irr::s32>(0,0,60,60), 0, irr::video::SColor (255,255,255,255), true);
                if (player[1]->Bonus == 3)
                    driver->draw2DImage(player[1]->image[3], irr::core::position2d<irr::s32>(1130,70), irr::core::rect<irr::s32>(0,0,60,60), 0, irr::video::SColor (255,255,255,255), true);
                if (!player[2]->living)
                    driver->draw2DImage(player[2]->image[0], irr::core::position2d<irr::s32>(20,750), irr::core::rect<irr::s32>(0,0,150,150), 0, irr::video::SColor (255,255,255,255), true);
                if (!player[3]->living)
                    driver->draw2DImage(player[3]->image[0], irr::core::position2d<irr::s32>(1300,750), irr::core::rect<irr::s32>(0,0,150,150), 0, irr::video::SColor (255,255,255,255), true);
                sceneManager->drawAll();
            }
        driver->endScene ();
        //map->print_map();
        }
        catch (std::exception& e)
        {
            std::cerr << "Exception caught : " << e.what() << std::endl;
        }
    }
    //music->stop_game();
    device->drop();
    main();
}

void prepare_game(bool coop, irr::IrrlichtDevice* device)
{
    std::vector<indie*> player;
    for (int i = 0; i != 5; i++)
        player.push_back(new indie());
    for (int i = 0; i != 121; i++)
        player[0]->MapCube.push_back(new My_cube());

    srand(time(NULL));
    //create MAP
    map = new My_map(1);
    map->my_map[1][1] = 3;
    player[0]->posx = 1;
    player[0]->posy = 1;
    map->my_map[1][9] = 3;
    player[1]->posx = 9;
    player[1]->posy = 1;
    map->my_map[9][1] = 3;
    player[2]->posx = 1;
    player[2]->posy = 9;
    map->my_map[9][9] = 3;
    player[3]->posx = 9;
    player[3]->posy = 9;

    //Device, driver et graphe de scene.
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager *sceneManager = device->getSceneManager();

    device->getCursorControl()->setVisible(false); //On rend invisible le curseur.

    //Sydney
    irr::scene::IAnimatedMeshMD2* modele;
    modele = (irr::scene::IAnimatedMeshMD2*)sceneManager->getMesh("recources/sydney.md2");
    player[0]->mesh = sceneManager->addAnimatedMeshSceneNode(modele);
    player[0]->mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    player[0]->mesh->setFrameLoop(0, 0);
    player[0]->mesh->setMaterialTexture(0, driver->getTexture("recources/sydney.bmp"));
    player[0]->mesh->setPosition(irr::core::vector3df(30.0f, 0.0f, 30.0f));
    player[1]->mesh = sceneManager->addAnimatedMeshSceneNode(modele);
    player[1]->mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    player[1]->mesh->setFrameLoop(0, 0);
    player[1]->mesh->setMaterialTexture(0, driver->getTexture("recources/sydney-green.bmp"));
    player[1]->mesh->setPosition(irr::core::vector3df(30.0f, 0.0f, -50.0f));
    player[2]->mesh = sceneManager->addAnimatedMeshSceneNode(modele);
    player[2]->mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    player[2]->mesh->setFrameLoop(0, 0);
    player[2]->mesh->setPosition(irr::core::vector3df(-50.0f, 0.0f, 30.0f));
    player[2]->mesh->setMaterialTexture(0, driver->getTexture("recources/sydney-blue.bmp"));
    player[3]->mesh = sceneManager->addAnimatedMeshSceneNode(modele);
    player[3]->mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    player[3]->mesh->setFrameLoop(0, 0);
    player[3]->mesh->setMaterialTexture(0, driver->getTexture("recources/sydney-red.bmp"));
    player[3]->mesh->setPosition(irr::core::vector3df(-50.0f, 0.0f, -50.0f));
    scaleNode(player[0]->mesh, 8.0f);
    scaleNode(player[1]->mesh, 8.0f);
    scaleNode(player[2]->mesh, 8.0f);
    scaleNode(player[3]->mesh, 8.0f);
    //bombe
    irr::scene::IAnimatedMeshMD2* bomb;
    bomb = (irr::scene::IAnimatedMeshMD2*)sceneManager->getMesh("recources/Bomb.obj");
    for (int i = 0; i != 5; i++) {
        player[i]->bomb = sceneManager->addAnimatedMeshSceneNode(bomb);
        player[i]->bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        player[i]->bomb->setFrameLoop(0, 0);
        player[i]->bomb->setMaterialTexture( 0, driver->getTexture("recources/Bomb.png"));
        player[i]->bomb->setVisible(false);
        scaleNode(player[i]->bomb, 5.0f); 
    }

    sceneManager->addCameraSceneNode(0, // cree une camera fixe
    irr::core::vector3df(0.0f, 120.0f, -10.0f), // position de la cam
    irr::core::vector3df(0.0f, 0.0f, -10.0f));

    for (int i = 0; i != 5; i++) {
        irr::video::ITexture *image = driver->getTexture("recources/croix.png");
        irr::video::ITexture *image2 = driver->getTexture("recources/Fire.png");
        irr::video::ITexture *image3 = driver->getTexture("recources/Skate.png");
        irr::video::ITexture *image4 = driver->getTexture("recources/bouc.png");
        player[i]->image.push_back(image);
        player[i]->image.push_back(image2);
        player[i]->image.push_back(image3);
        player[i]->image.push_back(image4);
    }
    //explotion
    for (int i = 0; i != 5; i++) {
        irr::scene::IAnimatedMesh* mesh = sceneManager->getMesh("recources/dest.cube.obj"); // tu mets ton obj ici
        irr::scene::IAnimatedMeshSceneNode* explotion = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion2 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion2->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion3 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion3->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion3->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion4 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion4->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion4->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion5 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion5->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion5->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion6 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion6->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion6->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion7 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion7->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion7->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion8 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion8->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion8->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        irr::scene::IAnimatedMeshSceneNode* explotion9 = sceneManager->addAnimatedMeshSceneNode(mesh);
        explotion9->setMaterialTexture( 0, driver->getTexture("recources/fireball.bmp"));
        explotion9->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        explotion->setVisible(false);
        explotion2->setVisible(false);
        explotion3->setVisible(false);
        explotion4->setVisible(false);
        explotion5->setVisible(false);
        explotion6->setVisible(false);
        explotion7->setVisible(false);
        explotion8->setVisible(false);
        explotion9->setVisible(false);
        scaleNode(explotion, 10.0f);
        scaleNode(explotion2, 10.0f);
        scaleNode(explotion3, 10.0f);
        scaleNode(explotion4, 10.0f);
        scaleNode(explotion5, 10.0f);
        scaleNode(explotion6, 10.0f);
        scaleNode(explotion7, 10.0f);
        scaleNode(explotion8, 10.0f);
        scaleNode(explotion9, 10.0f);
        player[i]->explotion.push_back(explotion);
        player[i]->explotion.push_back(explotion2);
        player[i]->explotion.push_back(explotion3);
        player[i]->explotion.push_back(explotion4);
        player[i]->explotion.push_back(explotion5);
        player[i]->explotion.push_back(explotion6);
        player[i]->explotion.push_back(explotion7);
        player[i]->explotion.push_back(explotion8);
        player[i]->explotion.push_back(explotion9);
    }
    game(player, coop, driver, device, sceneManager);
}

void menu2(bool coop, irr::IrrlichtDevice* device) {
    irr::video::IVideoDriver *driver = device->getVideoDriver();
    irr::scene::ISceneManager *sceneManager = device->getSceneManager();
    irr::gui::IGUIButton *curr;
    device->getGUIEnvironment()->clear();
    irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();
    irr::scene::IAnimatedMeshMD2* modele;
    modele = (irr::scene::IAnimatedMeshMD2*)sceneManager->getMesh("recources/sydney.md2");
    irr::scene::IAnimatedMeshSceneNode* joueur = sceneManager->addAnimatedMeshSceneNode(modele);
    joueur->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    joueur->setFrameLoop(0, 0);
    joueur->setMaterialTexture(0, driver->getTexture("recources/sydney.bmp"));
    joueur->setPosition(irr::core::vector3df(-0.75f, 0.0f, 0.0f));
    joueur->setRotation(irr::core::vector3df(0.0f, 80.0f, 0.0f));
    irr::scene::IAnimatedMeshSceneNode* joueur2 = sceneManager->addAnimatedMeshSceneNode(modele);
    joueur2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    joueur2->setFrameLoop(0, 0);
    joueur2->setMaterialTexture(0, driver->getTexture("recources/sydney-green.bmp"));
    joueur2->setPosition(irr::core::vector3df(0.73f, 0.0f, 0.0f));
    joueur2->setRotation(irr::core::vector3df(0.0f, 80.0f, 0.0f));
    joueur2->setMD2Animation(irr::scene::EMAT_STAND);
    joueur->setMD2Animation(irr::scene::EMAT_STAND);
    scaleNode(joueur, 0.25f);
    scaleNode(joueur2, 0.25f);
    irr::gui::IGUIButton *mon_bouton1 = guienv->addButton(irr::core::rect<irr::s32>(660, 615,870,715), 0, ButtonMenu::PLAY, L"PLAY");
    irr::gui::IGUIButton *mon_bouton2 = guienv->addButton(irr::core::rect<irr::s32>(660, 750,870,850), 0, ButtonMenu::EXIT, L"BACK");
    irr::gui::IGUIButton *mon_bouton3 = guienv->addButton(irr::core::rect<irr::s32>(1200, 750,1400,850), 0, ButtonMenu::PLAY, L"COOP : ON");
    irr::video::ITexture *image = driver->getTexture("recources/menu2.png");
    int i = 0;

    while (device->run()) {
        if (mon_bouton1->isPressed()) {
            i = 1;
            break;
        }
        if (mon_bouton2->isPressed()) {
            i = 2;
            break;
        }
        if (mon_bouton3->isPressed()) {
            if (coop) {
                coop = false;
                mon_bouton3 = guienv->addButton(irr::core::rect<irr::s32>(1200, 750,1400,850), 0, ButtonMenu::PLAY, L"COOP : OFF");
            }
            else if (!coop) {
                coop = true;
                mon_bouton3 = guienv->addButton(irr::core::rect<irr::s32>(1200, 750,1400,850), 0, ButtonMenu::PLAY, L"COOP : ON");
            }
        }
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
            driver->draw2DImage(image, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(0,0,1500,900), 0, irr::video::SColor (255,255,255,255), true);
            //driver->draw2DImage(image2, irr::core::position2d<irr::s32>(1200,300), irr::core::rect<irr::s32>(0,0,150,150), 0, irr::video::SColor (255,255,255,255), true);
            device->getGUIEnvironment()->drawAll();
            sceneManager->drawAll();
            device->getVideoDriver()->endScene();
        }
    }
    if (device->run() && i == 1)
        prepare_game(coop, device);
    if (i == 2) {
        device->drop();
        main();
    }

}

int main()
{
    //MENU
    //music = new My_//music();
    //music->play_menu();
    bool coop = true;
    irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1500,900), 32, false, false, false);
    device->setWindowCaption(L"Bomberman"); // titre de la fenetre
    nb_joueur = 4;
    irr::video::IVideoDriver *driver = device->getVideoDriver();
    irr::scene::ISceneManager *sceneManager = device->getSceneManager();
    irr::gui::IGUIButton *curr;
    irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();
    irr::gui::IGUIButton *mon_bouton1 = guienv->addButton(irr::core::rect<irr::s32>(560, 50,630,100), 0, ButtonMenu::PLAY, L"PLAY");
    irr::gui::IGUIButton *mon_bouton2 = guienv->addButton(irr::core::rect<irr::s32>(560, 50,630,100), 0, ButtonMenu::EXIT, L"EXIT");
    mon_bouton1->setRelativePosition(irr::core::rect<irr::s32>(500, 725, 600, 780));
    mon_bouton2->setRelativePosition(irr::core::rect<irr::s32>(900, 725, 1000, 780));
    irr::video::ITexture *image = driver->getTexture("recources/ciel étoilé.jpg");
    irr::video::ITexture *image2 = driver->getTexture("recources/title2.png");
    irr::video::ITexture *image3 = driver->getTexture("recources/Play.png");
    irr::video::ITexture *image4 = driver->getTexture("recources/Exit.png");
    
    try
    {
        while (device->run())
        {
            if (mon_bouton1->isPressed()) {
                break;
            }
            if (mon_bouton2->isPressed())
                device->closeDevice();
            if (device->isWindowActive())
            {
                driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
                driver->draw2DImage(image, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(0,0,1500,900), 0, irr::video::SColor (255,255,255,255), true);
                driver->draw2DImage(image2, irr::core::position2d<irr::s32>(490,100), irr::core::rect<irr::s32>(0,0,600,290), 0, irr::video::SColor (255,255,255,255), true);
                device->getGUIEnvironment()->drawAll();
                driver->draw2DImage(image3, irr::core::position2d<irr::s32>(475,650), irr::core::rect<irr::s32>(0,0,200,200), 0, irr::video::SColor (255,255,255,255), true);
                driver->draw2DImage(image4, irr::core::position2d<irr::s32>(850,650), irr::core::rect<irr::s32>(0,0,200,200), 0, irr::video::SColor (255,255,255,255), true);
                device->getVideoDriver()->endScene();
            }
        }
        if (device->run())
            menu2(coop, device);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
        return (84);
    }
    return (0);
}