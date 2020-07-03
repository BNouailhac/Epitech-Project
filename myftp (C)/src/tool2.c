/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** tool2
*/
#include "../include/ftp.h"

int create_data(SOCKET sock, int port)
{
    SOCKET csock = socket(2, SOCK_STREAM, 0);
    SOCKADDR_IN sin;
    int	errno;

    (void) sock;
    rerulesocket(csock);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = htonl(((in_addr_t) 0x00000000));
    if ((errno = bind(csock, (SOCKADDR *) &sin, sizeof(sin)))
    == SOCKET_ERROR) {
        close(csock);
        write(2, "Bind data socket failed.\n", 25);
        return (-1);
    }
    return (create_data2(sock, port, csock));
}

int userlog(SOCKET sock, t_user *user)
{
    if (user->in != 42) {
        write(sock, "530 Please login with USER and PASS.\r\n", 38);
        return (0);
    }
    return (1);
}

int create_data2(SOCKET sock, int port, SOCKET csock)
{
    if ((listen(csock, 10)) == SOCKET_ERROR) {
        close(csock);
        write(2, "Listen socket failed.\n", 22);
        return (-1);
    }
    return (csock);
}

int check_buffer(char *buff)
{
    int	dot = 0;
    char *str = buff;
    int	nb = 0;

    for (;*str; str++) {
        if (*str >= 48 && *str <= 57)
            nb++;
        else if (*str == 44)
            dot++;
    }
    if (nb++ <= 18 && dot == 5)
        return (1);
    return (0);
}

int th(SOCKET sock, t_user *user, char *buff)
{
    if (userlog(sock, user)) {
        if (user->ui == 0) {
            write(sock, "425 Use PORT or PASV first.\r\n", 30);
            return (1);
        }
        if (buff != NULL)
            stor_file(sock, user, buff);
        else
            write(sock, "500 filename is missing.\r\n", 26);
        user->ui = 0;
    }
    return (1);
}