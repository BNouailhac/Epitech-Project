/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** send_handling2
*/
#include "../include/ftp.h"

int lm(SOCKET sock, t_user *user, char *buff)
{
    (void) buff;
    if (userlog(sock, user)) {
        if (user->ui == 0) {
            write(sock, "425 Use PORT or PASV first.\r\n", 30);
            return (1);
        }
        do_ls(sock, user, buff);
        if (close(user->ta) == SOCKET_ERROR)
            printf("Data socket close failed\n");
        user->ui = 0;
    }
    return (1);
}

int hb(SOCKET sock, t_user *user, char *buff)
{
    (void) buff;
    if (userlog(sock, user)) {
        write(sock, "214-The following commands are recognized.\r\n", 44);
        write(sock, "CDUP CWD HELP NOOP PASS PWD QUIT USER\r\n", 39);
        write(sock, "214 Help OK.\r\n", 13);
    }
    return (1);
}

int prepare_ftp(SOCKET sock, SOCKADDR_IN sin, char **av)
{
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(av[1]));
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((bind(sock, (SOCKADDR *) &sin, sizeof(sin))) == SOCKET_ERROR) {
        close(sock);
        write(2, "Bind socket failed.\n", 20);
        return (84);
    }
    if ((listen(sock, 90000)) == SOCKET_ERROR) {
        close(sock);
        write(2, "Listen socket failed.\n", 22);
        return (84);
    }
    if (chdir(av[2]) == -1) {
        close(sock);
        write(2, "Error: Bad path\n", 16);
        return (84);
    }
    start_ftp(sock, av[2]);
    return (0);
}

int fc(SOCKET sock, t_user *user, char *buff)
{
    SOCKET dt;
    int	port;

    (void) buff;
    if (userlog(sock, user)) {
        port = rand() % 535 + 65000;
        if ((dt = create_data(sock, port)) == -1) {
            write(sock, "530 Failed to create Passive Mode.\r\n", 38);
            return (1);
        }
        user->ta = dt;
        create_ip(sock, user, port);
        user->ui = 1;
        close(dt);
    }
    return (1);
}

int rf(SOCKET sock, t_user *user, char *buff)
{
    if (userlog(sock, user)) {
        if (check_buffer(buff)) {
            if ((user->ta = socket(AF_INET, SOCK_STREAM, 0))
            == SOCKET_ERROR) {
                write(sock, "530 Failed to create Port Mode.\r\n", 33);
                return (1);
            }
            if (make_connection(user->ta, buff) == SOCKET_ERROR) {
                write(sock, "530 Failed to create Port Mode.\r\n", 33);
                close(user->ta);
            }
            else
                write(sock, "200 PORT successfully connected.\r\n", 34);
        }
        else
            write(sock, "500 Command PORT wrong arguments.\r\n", 35);
    }
    return (1);
}