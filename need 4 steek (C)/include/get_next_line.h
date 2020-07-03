/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#ifndef READ_SIZE
#define READ_SIZE (10000)

typedef struct car_s {
    double left;
    double right;
    double mid;
    char *str;
    char **tab;
    float *wheels;
    double *speed;
    int *space;
    int *range;
} car_t;

void init_struct2(car_t *car);
void lengths(int n, int *weight);
char *itoa(int n);
char **malloc_tab(char **tab);
int first(char **str, const int fd);
int second(char **str, char **str2);
char *get_next_line(int fd);
char **my_str_to_tab(char *str, char c);
char **put_this(char *str, char **tab, char c);
void move(car_t *car);
int main(void);
void take_speed(double speed, car_t *car);
void take_way(double value, int neg);
int detect_end(char *str);
void go(car_t *car, int way);
int start(car_t *car);
void control(car_t *car);
int my_putstr(char *str);
int my_strlen(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
long int my_getnbr(char *str, int x);
void free_tab(char **tab);
char *my_strndup(char *str, int n);

#endif
