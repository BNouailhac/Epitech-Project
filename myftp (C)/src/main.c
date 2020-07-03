/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** main
*/
#include "../include/ftp.h"

int cv(SOCKET sock, t_user *user, char *buff)
{
    char *str;

    if (userlog(sock, user)) {
        if (buff != NULL) {
            str = getpwd();
            if (!strcmp(user->str, str) && !strcmp(buff, "..")) {
                write(sock, "250 Directory successfully changed.\r\n", 37);
                free(str);
            }
            else if (!access(buff, F_OK)) {
                chdir(buff);
                write(sock, "250 Directory successfully changed.\r\n", 37);
            }
            else
                write(sock, "550 Failed to change directory.\r\n", 33);
        }
        else
            write(sock, "550 Failed to change directory.\r\n", 33);
    }
    return (1);
}

int az(SOCKET sock, t_user *user, char *buff)
{
    char *str;

    (void) buff;
    if (userlog(sock, user)) {
        str = getpwd();
        if (!strcmp(user->str, str)) {
            write(sock, "200 Directory successfully changed.\r\n", 37);
            free(str);
        }
        else if (!access(user->str, F_OK)) {
            chdir("..");
            write(sock, "200 Directory successfully changed.\r\n", 37);
        }
        else
            write(sock, "550 Failed to change directory.\r\n", 33);
    }
    return (-1);
}

void rerulesocket(SOCKET sock)
{
    int	nb = 1;

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &nb,
    sizeof(int)) < 0) {
        close(sock);
        printf("setsockopt failed\n");
        return;
    }
}

int main(int ac, char **av)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN sin;
    int i = 1;

    srand(time(NULL));
    if (ac != 3 || sock == SOCKET_ERROR) {
        printf("USAGE: ./myftp [port] [path]\n");
        printf("\tport  is the port number on which");
        printf(" the server socket listens\n\tpath  is the path to the home ");
        printf("directory for the Anonymous user");
        close(sock);
        return (84);
    }
    if (setsockopt(sock, 1, 2 | 15, &i,
    sizeof(int)) < 0) {
        close(sock);
        return (84);
    }
    return (prepare_ftp(sock, sin, av));
}