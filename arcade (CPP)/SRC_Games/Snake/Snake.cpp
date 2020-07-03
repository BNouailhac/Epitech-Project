/*
** EPITECH PROJECT, 2020
** Snake.cpp
** File description:
** Snake.cpp
*/
#include "Snake.hpp"
#include <string>      
#include <iostream>     
#include <sstream>
#include <time.h>
#include <vector>
#include <cstdio>
#include <ctime>    

    class Snake_Player {
        public:
            Snake_Player(int a, int b);
            ~Snake_Player();
            int getPosition_x();
            int getPosition_y();
        protected:
        private:
            int pos_x;
            int pos_y;
    };

static int points = 0;

bool game_over = false;

static int x = 0;

static int y = 0;

bool Pause = false;

std::list<Snake_Player> snakes;

std::list<Snake_Player>::iterator it;

static int apple_posX;

static int apple_posY;

static std::vector<std::string> SNAKE_MAP = {
    "Your Score: 0. Press 'Q' to quit, 'L' to Change library,",
    "'E' to change game, 'C' to back menu, 'P' to pause.",
    " ####################### ",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    " ####################### "
};

static std::vector<std::string> ORIGIN_MAP = {
    " ####################### ",
    " ####################### ",
    " ####################### ",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    "#_______________________#",
    " ####################### "
};

Arcade::Snake::Snake()
{
    srand(time(NULL));
    apple_posX = rand() % 29 + 1;
    apple_posY = rand() % 10 + 1;
    while (apple_posY > 9 || apple_posX > 23 ||
    apple_posY < 1 || apple_posX < 1) {
        apple_posX = rand() % 29;
        apple_posY = rand() % 10;  
    }
    for (int i = 0; i < 4; i++)
        snakes.push_front(Snake_Player(3+i,3));
}

Arcade::Snake::~Snake()
{
}

Snake_Player::Snake_Player(int a, int b)
{
    this->pos_x = a;
    this->pos_y = b;
}

Snake_Player::~Snake_Player()
{
}

int Snake_Player::getPosition_x()
{
    return (this->pos_x);
}

int Snake_Player::getPosition_y()
{
    return (this->pos_y);
}

bool Arcade::Snake::DoAction(Events event)
{
    int dir = 0;

    if (event == UP) {
		dir = 3;
	}
	if (event == DOWN) {
		dir = 4;
	}
	if (event == RIGHT) {
        dir = 2;
	}
	if (event == LEFT) {
        dir = 1;	
	}
    if (event == PAUSE) {
        if (!Pause)
            Pause = true;
        else if (Pause)
            Pause = false;
	}
    game(dir);
    return (true);
}

std::vector<std::string> Arcade::Snake::GetMap()
{
    return (SNAKE_MAP);
}

void game(int dir)
{
    if (!game_over) {
        if (!Pause) {
        /*std::list<Arcade::Snake_Player> snakes;
        std::list<Arcade::Snake_Player>::iterator it;*/
        /*int apple_posX = rand() % 29 + 1;
        int apple_posY = rand() % 10 + 1;

        for (int i = 0; i < 5; i++)
            snakes.push_front(Arcade::Snake_Player(3+i,3));*/

        //start
            
                Snake_Player logic = snakes.front();
                x = logic.getPosition_x();
                y = logic.getPosition_y();
            if (dir != 0) {
                if (dir == 1) x--;
                else if (dir == 2) x++;
                else if (dir == 3) y--;
                else if (dir == 4) y++;

                
                snakes.push_front(Snake_Player(x, y));
                
            
                if (x == apple_posX && y == apple_posY) {
                    apple_posX = rand() % 29;
                    apple_posY = rand() % 10;
                    while (apple_posY > 9 || apple_posX > 23 ||
                    apple_posY < 1 || apple_posX < 1) {
                        apple_posX = rand() % 29;
                        apple_posY = rand() % 10;  
                    }
                    points++;
                } else
                    snakes.pop_back();
            }
        
            if (y > 9 || x > 23 || y < 1 || x < 1) // collision with border
                game_over = true;
        
            // Output
            //erase();
            //mvaddch(apple_posY,apple_posX,'X');
            SNAKE_MAP = ORIGIN_MAP;
            SNAKE_MAP[apple_posY + 2][apple_posX] = 'X';
            std::ostringstream a;
            a.str("");
            a << points;
            SNAKE_MAP[0] = "Your Score: " + a.str() + ". Press 'Q' to quit, 'L' to Change library,";
            SNAKE_MAP[1] =  "'E' to change game, 'C' to back menu, 'P' to pause.";
            for (it = snakes.begin(); it != snakes.end(); it++) {
            // mvaddch((*it).getPosition_y(),(*it).getPosition_x(),'o');
                if ((*it).getPosition_y() == y && (*it).getPosition_x() == x && it != snakes.begin()) // collision with snake
                    game_over = true;
                else
                    if ((*it).getPosition_y() < 13 || (*it).getPosition_x() < 31 ||
                    (*it).getPosition_y() > 1 || (*it).getPosition_x() > 1)
                        SNAKE_MAP[(*it).getPosition_y() + 2][(*it).getPosition_x()] = '0';
            }
            } else {
            SNAKE_MAP = {"         PAUSE",
                         "Press 'P' to continue"};
        }
    } else {
        std::ostringstream a;
        a.str("");
        a << points;
		SNAKE_MAP = {
        "       Game Over !",
        "              ",
		"Your Score: " + a.str() + ". Press 'Q' to quit, 'L' to Change library,",
        "'E' to change game, 'C' to back menu, 'P' to pause.",
        " ####################### ",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        "#_______________________#",
        " ####################### "};

        for (it = snakes.begin(); it != snakes.end(); it++) {
            if ((*it).getPosition_y() < 13 || (*it).getPosition_x() < 31 ||
            (*it).getPosition_y() > 1 || (*it).getPosition_x() > 1)
                SNAKE_MAP[(*it).getPosition_y() + 4][(*it).getPosition_x()] = '0';
        }
    }
        //mvprintw(0, 0, "Your Score: %i. press 'q' to quit.\n", points);
        //mvprintw(0, 0, "You lost and gained a total of %i points.\n", points);
        //refresh();
    //timeout(-1);
}