/*
** EPITECH PROJECT, 2019
** tail
** File description:
** 
*/
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct tail_s {
    int v_q;
    int c_n;
    int line;
} tail_t;

char *re(char *str);
char *include(int ac, char **av, char *str);
int tail(char *str, int ac, char **av, tail_t *ta);
long int my_getnbr(char *str, int x);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int manage_flag(tail_t *ta, char **tab, char **av, int ac);
void condn(char *flag, tail_t *ta);
void condq(char *flag, tail_t *ta);
void condc(char *flag, tail_t *ta);
int my_strn_count(char **tab);
char **my_str_to_tab(char *str, char c);
void show_tab(char **tab, int count, int line);
char *my_strndup(char *str, int n);
void free_tab(char **tab);
char *get_next_line(int fd);
