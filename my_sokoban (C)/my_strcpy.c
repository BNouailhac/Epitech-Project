/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** my_strcpy
*/
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char*) * my_strlen(src));
    while (src[i] != '\0') {
	dest[i] = src[i];
        i++;
    }
    return(dest);
}
