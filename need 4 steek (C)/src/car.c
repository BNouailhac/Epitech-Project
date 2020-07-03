/*
** EPITECH PROJECT, 2017
** ia.c
** File description:
** ia.c
*/
#include "../include/get_next_line.h"

void go(car_t *car, int way)
{
    int i;

    for (i = 0; i <= 4;) {
        if (car->mid < car->range[i]) {
            take_way(car->wheels[i], way);
            i = 10;
        } else
            i++;
    }
    if (i == 5)
        take_way(car->wheels[i], way);
}

int start(car_t *car)
{
    control(car);
    car->left = atof(car->tab[3]);
    car->mid = atof(car->tab[19]);
    car->right = atof(car->tab[34]);
    car->left > car->right ? go(car, 0) : go(car, 1);
    if (detect_end(car->tab[35]))
        exit(0);
    return (0);
}

int detect_end(char *str)
{
    if (strcmp(str, "Track Cleared") == 0) {
        my_putstr("stop_simulation\n");
        return (1);
    }
    return (0);
}

void control(car_t *car)
{
    int i = 0;

    for (i = 0; i <= 6;) {
        if (car->mid > car->space[i]) {
            take_speed(car->speed[i], car);
            i = 10;
        } else
            i++;
    }
    if (i == 7)
        take_speed(car->speed[i], car);
}

void take_way(double speed, int way)
{
    char *str = malloc(sizeof(char) * 100);

    my_putstr("wheels_dir:");
    if (way == 1)
        my_putstr("-");
    dprintf(1, "%.2f", speed);
    my_putstr("\n");
    str = get_next_line(0);
    if (detect_end(str) == 1) {
        free(str);
        exit(0);
    }
    free(str);
}
