/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int m = 0;

    while (str[m] != '\0') {
        m++;
    }
    return (m);
}
