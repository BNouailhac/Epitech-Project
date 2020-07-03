/*
** EPITECH PROJECT, 2019
** things.c
** File description:
** things
*/
#include "../include/get_next_line.h"

int my_putstr(char *str)
{
    int m = 0;

    while (str[m] != '\0') {
        my_putchar(str[m]);
        m = m + 1;
    }
    return (0);
}

int my_strlen(char *str)
{
    int m = 0;

    while (str[m] != '\0') {
        m = m + 1;
    }
    return (m);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int n = 1;

    if (nb < 0) {
        my_putchar ('-');
        nb *= - 1;
    }
    while ((nb / n) >= 10)
        n *= 10;
    while (n > 0) {
        my_putchar((nb / n) % 10 + '0');
        n /= 10;
    }
    return (0);
}

long int my_getnbr(char *str, int x)
{
    int	m = 1;
    int n = 0;

    while (str[x] == '+' || str[x] == '-') {
        if (str[x] == '-')
            m = m * -1;
        x++;
    }
    while (str[x] != '\0') {
        if (str[x] >= '0' && str[x] <= '9') {
            n = n * 10;
            n = n + str[x] - '0';
            x++;
        }
        else
            return (n * m);
    }
    return (n * m);
}
