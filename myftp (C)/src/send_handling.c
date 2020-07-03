/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** send_handling
*/
#include "../include/ftp.h"

int uy(SOCKET sock, t_user *user, char *buff)
{
    if (user->in == 42)
        write(sock, "530 Can't change from guest user.\r\n", 35);
    else {
        if (buff == NULL) {
            write(sock, "530 Permission denied.\r\n", 24);
            return (1);
        }
        to_lower_case(&buff);
        user->us = strdup(buff);
        user->in = 2;
        write(sock, "331 Please specify the password.\r\n", 34);
    }
    return (1);
}

int sd(SOCKET sock, t_user *user, char *buff)
{
    if (user->in == 42) {
        write(sock, "230 Already logged in.\r\n", 24);
        return (1);
    }
    if (user->in == 2) {
        if (buff == NULL || strcmp(buff, "")) {
            write(sock, "530 Login incorrect.\r\n", 22);
            return (1);
        }
        if (!strcmp(user->us, "anonymous")) {
            print_serv(user->dfr, " is known as Anonymous.\n");
            write(sock, "230 Login successful.\r\n", 23);
            user->in = 42;
            user->fr = strdup("");
        }
        else
            write(sock, "530 Login incorrect.\r\n", 22);
    }
    else
        write(sock, "332 Login with USER first\r\n", 27);
    return (1);
}

void create_ip(SOCKET sock, t_user *user, int port)
{
    int port2 = port / 256;
    int port3 = port - (port2 * 256);
    char **ip = Str_SPLITE(user->string, '.');
    int i = -1;
    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t len = sizeof(csin);

    printf("Passive mode on : %s.%s.%s.%s:%d\n", ip[0], ip[1], ip[2],
    ip[3], port);
    dprintf(sock, "227 Entering Passive Mode (%s,%s,%s,%s,%d,%d).\r\n",
    ip[0], ip[1], ip[2], ip[3], port2, port3);
    while (++i < 4)
        free(ip[i]);
    free(ip);
    if ((csock = accept(user->ta, (SOCKADDR *) &csin, &len)) ==
    SOCKET_ERROR)
        write(2, "Socket accept failed\n", 21);
    user->ta = csock;
}

void stor_file(SOCKET sock, t_user *user, char *buff)
{
    FILE *fp;
    int buffer[2];

    write(sock, "150 opening data connection.\r\n", 30);
    if ((fp = fopen(buff, "wb")) == NULL) {
        write(sock, "450 file cannot be created.\r\n", 31);
        return;
    }
    while (read(user->ta, (char *) &buffer, sizeof(buffer)))
        write(fileno(fp), (char *) &buffer, sizeof(buffer));
    fclose(fp);
    write(sock, "226 closing data connection.\r\n", 30);
    close(user->ta);
}

int sxc(SOCKET sock, t_user *user, char *buff)
{
    (void) sock;
    (void) buff;
    (void) user;
    if (userlog(sock, user))
        write(sock, "215 UNIX type: L8\r\n", 19);
    return (1);
}