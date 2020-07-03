/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line
*/
#include "../include/get_next_line.h"

int first(char **str, const int fd)
{
    int nb = 0;

    *str = malloc(sizeof(char) * (READ_SIZE + 1));
    if (*str == NULL)
        return (-1);
    nb = read(fd, *str, READ_SIZE);
    if (nb == -1)
        return (-1);
    (*str)[nb] = 0;
    return (0);
}

int second(char **str, char **str2)
{
    int nb = 0;

    *str2 = malloc(sizeof(char) * (READ_SIZE + 1));
    if (*str2 == NULL)
        return (-1);
    while (**str != 0 && (nb == 0 || *(*str - 1) != '\n')) {
        (*str2)[nb] = **str;
        nb++;
        (*str)++;
    }
    return (nb);
}

char *get_next_line(int fd)
{
    int nb = 0;
    static char	*str;
    static char *str2;

    if (fd == -1)
        return (NULL);
    if (str == NULL || str[0] == 0)
        nb = first(&str, fd);
    if (str == NULL || str[0] == 0 || nb == -1)
        return (NULL);
    nb = second(&str, &str2);
    if (nb == -1)
        return (NULL);
    str2[nb] = 0;
    if (nb != 0 && str2[nb - 1] == '\n')
        str2[nb - 1] = 0;
    return (str2);
}
