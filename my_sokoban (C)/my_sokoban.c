/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** my_sokoban
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int sokoban(char *str, char **av, int ac)
{
    int i = 0;
    int box = 0;
    int goal = 0;
    int player = 0;
    WINDOW *window;
    int size = 0;
    int key = 0;

    while (str[i] != '\0') {
        if (i == 0)
            while (str[i] == '#') {
                size++;
                i++;
            }
        i++;
    }
    if (size > 158)
        return(84);
    size = size + 1;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] != 'P' && str[i] != 'X' &&
            str[i] != 'O' && str[i] != '#'
            && str[i] != ' ' && str[i] != '\n') {
            return(84);
        }
        if (str[i] == 'P') {
            player = i;
        }
        if (str[i] == 'X') {
            box = i;
        }
        if (str[i] == 'O') {
            goal = i;
        }
        i++;
    }
    i = 0;
    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        printw(str);
        key = getch();
        refresh();
        if (key == 27) {
            break;
        }
        if (key == 32) {
            main(ac, av);
            return(1);
        }
        if (key == KEY_RIGHT) {
            if (str[player + 1] == '#') {
            } else if (str[player + 1] == 'X') {
                if (str[player + 2] != '#') {
                    if (player == goal) {
                        box++;
                        player++;
                        str[player + 1] = 'X';
                        str[player] = 'P';
                        str[player - 1] = 'O';
                    } else {
                        box++;
                        player++;
                        str[player + 1] = 'X';
                        str[player] = 'P';
                        str[player - 1] = ' ';
                    }
                }
            } else {
                if (player == goal) {
                    player++;
                    str[player] = 'P';
                    str[player - 1] = 'O';
                } else {
                    player++;
                    str[player] = 'P';
                    str[player - 1] = ' ';
                }
            }
        }
        if (key == KEY_LEFT) {
            if (str[player - 1] == '#') {
            } else if (str[player - 1] == 'X') {
                if (str[player - 2] != '#') {
                    if (player == goal) {
                        box--;
                        player--;
                        str[player - 1] = 'X';
                        str[player] = 'P';
                        str[player + 1] = 'O';
                    } else {
                        box--;
                        player--;
                        str[player - 1] = 'X';
                        str[player] = 'P';
                        str[player + 1] = ' ';
                    }
                }
            } else {
                if (player == goal) {
                    player--;
                    str[player] = 'P';
                    str[player + 1] = 'O';
                } else {
                    player--;
                    str[player] = 'P';
                    str[player + 1] = ' ';
                }
            }
        }
        if (key == KEY_DOWN) {
            if (str[player + size] == '#') {
            } else if (str[player + size] == 'X') {
                if (str[player + size + size] != '#') {
                    if (player == goal) {
                        box = box + size;
                        player = player + size;
                        str[player + size] = 'X';
                        str[player] = 'P';
                        str[player - size] = 'O';
                    } else {
                        box = box + size;
                        player = player + size;
                        str[player + size] = 'X';
                        str[player] = 'P';
                        str[player - size] = ' ';
                    }
                }
            } else {
                if (player == goal) {
                    player = player + size;
                    str[player] = 'P';
                    str[player - size] = 'O';
                } else {
                    player = player + size;
                    str[player] = 'P';
                    str[player - size] = ' ';
                }
            }
        }
        if (key == KEY_UP) {
            if (str[player - size] == '#') {
            } else if (str[player - size] == 'X') {
                if (str[player - size - size] != '#') {
                    if (player == goal) {
                        box = box - size;
                        player = player - size;
                        str[player - size] = 'X';
                        str[player] = 'P';
                        str[player + size] = 'O';
                    } else {
                        box = box - size;
                        player = player - size;
                        str[player - size] = 'X';
                        str[player] = 'P';
                        str[player + size] = ' ';
                    }
                }
            } else {
                if (player == goal) {
                    player = player - size;
                    str[player] = 'P';
                    str[player + size] = 'O';
                } else {
                    player = player - size;
                    str[player] = 'P';
                    str[player + size] = ' ';
                }
            }
        }
        if (box == goal) {
            return(0);
        }
        if (str[box + 1] == '#' && str[box - 1] == '#' ||
            str[box + 1] == '#' && str[box + size] == '#'
            || str[box + 1] == '#' && str[box - size] == '#' ||
            str[box - 1] == '#' && str[box + size] == '#'
            || str[box - 1] == '#' && str[box - size] == '#' ||
            str[box + size] == '#' && str[box - size] == '#')
            return(1);
    }
    endwin();
    return (0);
}

void main(int ac, char **av)
{
    struct stat file;
    char *str;
    int	count = 0;
    int z = open(av[1], O_RDONLY);

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        description();
    if (z == -1)
        return (84);
    stat(av[1], &file);
    str = malloc(sizeof(char *) * file.st_size);
    include(ac, av, str);
    count = allow(str);
    sokoban(str, av, ac);
    free(str);
}

void description(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n     map  "
              "file representing the warehouse map, containing '#' for walls,\n"
              "	  'P' for the player, 'X' for boxes and 'O' for "
              "storage locations.\n");
}
