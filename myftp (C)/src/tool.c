/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** tool
*/
#include "../include/ftp.h"

void to_lower_case(char **str)
{
    for (int i = -1; (*str)[++i];)
        (*str)[i] = tolower((*str)[i]);
}

char **Str_SPLITE2(char *str, int nb, char *delim)
{
    char *ex;
    char **tab = malloc(sizeof(char *) * nb);
    char *string = strdup(str);
    size_t size;

    if (tab) {
        ex = strtok(string, delim);
        size = 0;
        while (ex) {
            *(tab + size++) = strdup(ex);
            ex = strtok(0, delim);
        }
        *(tab + size) = 0;
    }
    free(string);
    return (tab);
}

char **Str_SPLITE(char *a_str, char c)
{
    int	nb = 0;
    char *str = a_str;
    char *lcom = NULL;
    char tab[2];

    tab[0] = c;
    tab[1] = 0;
    for (; *str; str++)
        if (c == *str) {
            nb++;
            lcom = str;
        }
    nb += lcom < (a_str + strlen(a_str) - 1);
    nb++;
    return (Str_SPLITE2(a_str, nb, tab));
}


int make_connection(SOCKET sock, char *buffer)
{
    char **ip = Str_SPLITE(buffer, ',');
    SOCKADDR_IN sin;
    char *str = malloc(sizeof(char) * (strlen(ip[0]) + strlen(ip[1])
    + strlen(ip[2]) + strlen(ip[3])) + 3);

    sprintf(str, "%s.%s.%s.%s", ip[0], ip[1], ip[2], ip[3]);
    createclient(&sin, str, ip);
    free(str);
    if (connect(sock, (SOCKADDR *) &sin, sizeof(SOCKADDR)) ==
    SOCKET_ERROR)
        return (-1);
    return (0);
}