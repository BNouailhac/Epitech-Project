/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** send_handling3
*/
#include "../include/ftp.h"

int tg(SOCKET sock, t_user *user, char *buff)
{
    if (userlog(sock, user)) {
        if (buff == NULL) {
            write(sock, "500 Unrecognised TYPE command.\r\n", 32);
            return (1);
        }
        to_lower_case(&buff);
        if (!strcmp(buff, "i"))
            write(sock, "200 Switching to Binary mode.\r\n", 31);
        else if (!strcmp(buff, "a"))
            write(sock, "200 Switching to ASCII mode.\r\n", 30);
        else
            write(sock, "500 Unrecognised TYPE command.\r\n", 32);
    }
    return (1);
}

int qs(SOCKET sock, t_user *user, char *buff)
{
    (void) buff;
    write(sock, "221 Goodbye.\r\n", 15);
    print_serv(user->dfr, " has disconnected from the server.\r\n");
    user->in = 0;
    if (user->us != NULL)
        free(user->us);
    if (user->fr != NULL)
        free(user->fr);
    free(user->string);
    free(user->str);
    return (0);
}

int cbn(SOCKET sock, t_user *user, char *buff)
{
    char *str = getpwd();

    (void) buff;
    if (userlog(sock, user)) {
        write(sock, "257 \"", 5);
        write(sock, str, strlen(str));
        write(sock, "\"\r\n", 3);
    }
    free(str);
    return (1);
}

int ujk(SOCKET sock, t_user *user, char *buff)
{
    (void) buff;
    if (userlog(sock, user))
        write(sock, "200 NOOP ok.\r\n", 15);
    return (1);
}

int xd(SOCKET sock, t_user *user, char *buff)
{
    if (userlog(sock, user)) {
        if (buff == NULL) {
            write(sock, "501 Missing parameters.\r\n", 25);
            return (1);
        }
        if (remove(buff) == SOCKET_ERROR) {
            write(sock, "550 permission denied.\r\n", 24);
            return (1);
        }
        write(sock, "250 file successfully deleted.\r\n", 32);
    }
    return (1);
}