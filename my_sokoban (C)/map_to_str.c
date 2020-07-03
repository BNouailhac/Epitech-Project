/*
** EPITECH PROJECT, 2018
** map_to_str.c
** File description:
** map_to_str
*/
#include <fcntl.h>
#include <stdio.h>

void include(int ac, char **av, char *str)
{
    char buffer[BUFSIZ];
    int	nb = 0;
    int	cpt = 0;
    int i = 1;
    int	str2;
    int z = open(av[1], O_RDONLY);

    while (i != 0) {
        i = read(z, buffer, BUFSIZ);
        str2 = i;
        while (str2 > 0) {
            str[nb] = buffer[cpt];
            nb++;
            str2--;
            cpt++;
        }
    }
    close(z);
}

void allow(char *str)
{
    int	nb = 0;
    int	cnt = 0;
    int	i = 1;

    while (str[nb] != '\n')
        nb++;
    nb--;
    while (nb >= 0) {
        cnt = cnt + ((str[nb] - 48) * i);
        nb--;
        i = i * 10;
    }
}
