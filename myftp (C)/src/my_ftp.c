/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** my_ftp
*/
#include "../include/ftp.h"

t_funccmd tabcmd[] = {
    {&uy, "user"}, {&sd, "pass"},
    {&cv, "cwd"}, {&az, "cdup"},
    {&sxc, "syst"}, {&qs, "quit"},
    {&cbn, "pwd"}, {&fc, "pasv"},
    {&rf, "port"}, {&qs, "quit"},
    {&lm, "list"}, {&tg, "type"},
    {&xd, "dele"}, {&ff, "retr"},
    {&th, "stor"}, {&hb, "help"},
    {&ujk, "noop"}, {NULL, "0"}
};

void print_serv(char *ip, char *msg)
{
    if (strlen(msg) <= 1)
        return;
    write(1, ip, strlen(ip));
    write(1, " ", 1);
    write(1, msg, strlen(msg));
}

short loop_func(SOCKET sock, char *buff, t_user *user)
{
    int	i = 0;
    short ret = 1;
    char *tmp = NULL;

    if (strlen(buff) == 1)
        return (1);
    strtok(buff, "\n");
    if (strchr(buff, 32)) {
        tmp = strndup(strchr(buff, 32) + 1, strlen(strchr(buff, 32) + 1));
        strtok(buff, " ");
    }
    to_lower_case(&buff);
    while (strcmp(buff, tabcmd[i].str) && strcmp(tabcmd[i].str, "0"))
        i++;
    if (strcmp(tabcmd[i].str, "0") && (!strcmp(buff, tabcmd[i].str)))
        tabcmd[i].ptr(sock, user, tmp);
    else
        write(sock, "500 Unknown command.\r\n", 22);
    free(tmp);
    return (ret);
}

void prepare_client(SOCKET sock, t_user *user, SOCKADDR_IN *csin)
{
    SOCKADDR_IN sin;
    socklen_t len = sizeof(sin);

    user->us = NULL;
    user->in = 1;
    user->ui = 0;
    user->fr = NULL;
    user->port = ntohs(csin->sin_port);
    if (getsockname(sock, (SOCKADDR *) &sin, &len) == SOCKET_ERROR) {
        close(sock);
        exit(1);
    }
    user->string = strdup(inet_ntoa(sin.sin_addr));
    user->dfr = inet_ntoa(csin->sin_addr);
}

void connection(SOCKET csock, SOCKADDR_IN *csin, char *path)
{
    char buff[4096];
    t_user user;

    prepare_client(csock, &user, csin);
    if (!access(path, F_OK)) {
        chdir(path);
        user.str = getpwd();
    }
    write(csock, "220 (lFTPx 1.0.0)\r\n", 19);
    print_serv(user.dfr, " is connected to the server.\n");
    while (user.in) {
        bzero(buff, 4096);
        if (read(csock, buff, 4096) == 0)
            qs(csock, &user, buff);
        print_serv(user.dfr, buff);
        strtok(buff, "\r");
        loop_func(csock, buff, &user);
    }
    close(csock);
}

void start_ftp(SOCKET sock, char *path)
{
    SOCKET csock;
    SOCKADDR_IN csin;
    socklen_t len = sizeof(csin);
    pid_t pid;

    while (10) {
        if ((csock = accept(sock, (struct sockaddr *) &csin, &len))
        == SOCKET_ERROR)
            write(2, "Socket accept failed\n", 21);
        if ((pid = fork()) == 0) {
            close(sock);
            connection(csock, &csin, path);
            return;
        }
        else if (pid > 0)
            close(csock);
        else
            write(2, "Fork failed.\n", 13);
    }
    close(sock);
}