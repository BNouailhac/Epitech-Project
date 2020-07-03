/*
** EPITECH PROJECT, 2018
** moverect.c
** File description:
** moverect
*/
#include <stdlib.h>

void lengths(int n, int *weight)
{
    if (n >= 0) {
        n = -n;
    }
    *weight = 1;
    while (n / *weight < -9) {
        *weight *= 10;
    }
}

char *itoa(int n)
{
    char *str = malloc(100);
    int weight = 0;
    size_t cur = 0;

    lengths(n, &weight);
    if (n < 0) {
        str[cur] = '-';
        cur++;
    }
    if (n > 0)
        n = -n;
    while (weight >= 1) {
        str[cur++] = -(n / weight % 10) + 48;
        weight = weight / 10;
    }
    str[cur] = '\0';
    return (str);
}
