/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/
#include "../include/get_next_line.h"

void init_struct(car_t *car)
{
    car->left = 0;
    car->mid = 0;
    car->right = 0;
    car->wheels = malloc(sizeof(float) * 6);
    car->wheels[0] = 0.33;
    car->wheels[1] = 0.3;
    car->wheels[2] = 0.22;
    car->wheels[3] = 0.18;
    car->wheels[4] = 0.03;
    car->wheels[5] = 0.01;
    car->speed = malloc(sizeof(double) * 8);
    car->speed[0] = 1.0;
    car->speed[1] = 0.8;
    car->speed[2] = 0.62;
    car->speed[3] = 0.5;
    car->speed[4] = 0.4;
    car->speed[5] = 0.3;
    car->speed[6] = 0.2;
    car->speed[7] = 0.1;
    init_struct2(car);
}

void init_struct2(car_t *car)
{
    car->space = malloc(sizeof(float) * 7);
    car->space[0] = 2500;
    car->space[1] = 2000;
    car->space[2] = 1500;
    car->space[3] = 1000;
    car->space[4] = 500;
    car->space[5] = 400;
    car->space[6] = 300;
    car->range = malloc(sizeof(int) * 5);
    car->range[0] = 400;
    car->range[1] = 500;
    car->range[2] = 700;
    car->range[3] = 1020;
    car->range[4] = 1350;
}

void move(car_t *car)
{
    take_speed(0.5, car);
    while (1) {
        my_putstr("get_info_lidar\n");
        car->str = get_next_line(0);
        if (detect_end(car->str)) {
            free(car->str);
            break;
        }
        car->tab = my_str_to_tab(car->str, ':');
        free(car->str);
        if (strcmp(car->tab[1], "OK") == 0)
            start(car);
    }
}

int main(void)
{
    car_t *car = malloc(sizeof(car_t));

    init_struct(car);
    car->str = malloc(sizeof(char) * 100);
    car->tab = malloc_tab(car->tab);
    my_putstr("start_simulation\n");
    car->str = get_next_line(0);
    if (detect_end(car->str)) {
        free(car->str);
        return (0);
    }
    free(car->str);
    move(car);
    free_tab(car->tab);
    free(car->space);
    free(car->range);
    free(car->speed);
    free(car->wheels);
    free(car);
    return (0);
}

void take_speed(double speed, car_t *car)
{
    my_putstr("car_forward:");
    dprintf(1, "%.2f", speed);
    my_putstr("\n");
    car->str = get_next_line(0);
    if (detect_end(car->str) == 1) {
        free(car->str);
        exit(0);
    }
    free(car->str);
}
