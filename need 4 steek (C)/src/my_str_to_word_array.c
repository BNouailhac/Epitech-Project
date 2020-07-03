/*
** EPITECH PROJECT, 2019
** my_str_to_tab.c
** File description:
** my_str_to_tab
*/
#include "../include/get_next_line.h"

char **put_this(char *str, char **tab, char c)
{
    int nb = 0;
    int	i = 0;
    int	j = 0;
    int	z = 1;

    while (str[i] != '\0') {
        for (i; str[i] != '\0' && str[i] != c; i++, j++) {
            z = 0;
        }
        if (!z) {
            tab[nb] = my_strndup(str + i - j, j);
            nb++;
            j = 0;
        }
        while (str[i] == c)
            i++;
    }
    tab[nb] = NULL;
    return (tab);
}

char **my_str_to_tab(char *str, char c)
{
    int	nb = 0;
    char **tab;
    int	i = 0;
    int	z = 0;

    for (i; str[i] != '\0'; i++) {
        if (str[i] != c && z == 0) {
            nb++;
            z = 1;
        } else if (str[i] == c) {
            z = 0;
        }
    }
    tab = malloc(sizeof(char *) * (nb + 1));
    tab = put_this(str, tab, c);
    return (tab);
}