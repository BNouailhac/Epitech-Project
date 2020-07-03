/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr
*/

int my_putstr(char const *str)
{
    int m = 0;

    while (str[m] != '\0') {
        my_putchar (str[m]);
        m = m + 1;
    }
    return (0);
}
