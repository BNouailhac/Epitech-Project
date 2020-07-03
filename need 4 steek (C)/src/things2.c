/*
** EPITECH PROJECT, 2019
** things2.c
** File description:
** things2
*/
#include "../include/get_next_line.h"

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char **malloc_tab(char **tab)
{
    int i = 0;

    tab = malloc(sizeof(char *) * 100);
    while (tab[i] != NULL) {
        tab[i] = malloc(sizeof(char ) * 100);
        i++;
    }
    return (tab);
}

char *my_strndup(char *str, int n)
{
    char *dest = malloc(sizeof(char*) * my_strlen(str));
    int	i = 0;

    while (i < n) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
