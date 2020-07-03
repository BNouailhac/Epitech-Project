/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/

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
