/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** tool3
*/
#include "../include/ftp.h"

void make_file(SOCKET sock, t_user *user, FILE *fp)
{
    char *file = NULL;
    int	len;
    int	i = 0;

    fseek(fp, 0L, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    write(sock, "150 opening data connection.\r\n", 30);
    if ((file = malloc(len + 1)) != NULL) {
        fread(file, len, 1, fp);
        while (i < len)
            i += write(user->ta, file + i, len);
        free(file);
        write(sock, "226 closing data connection.\r\n", 30);
    }
    else
        write(sock, "426 Connexion closed, malloc failed.\r\n", 30);
    fclose(fp);
    close(user->ta);
}

char *getpwd(void)
{
    char *str = malloc(sizeof(char) * 1024);

    getcwd(str, 1024);
    str[strlen(str) + 1] = '\0';
    return (str);
}

void do_ls(SOCKET sock, t_user *user, char *buff)
{
    int	fd = dup(1);

    write(sock, "150 opening data connection.\r\n", 30);
    dup2(user->ta, 1);
    if (buff == NULL)
        system("ls -la");
    else
        if (!access(buff, F_OK))
            system(strcat("ls -la ", buff));
        else
            system("ls -la");
    dup2(fd, 1);
    write(sock, "226 closing data connection.\r\n", 30);
}

void createclient(SOCKADDR_IN *sin, char *addr, char **port)
{
    struct hostent *client;
    in_addr_t ip = inet_addr(addr);

    client = gethostbyaddr((char *) &ip, sizeof(ip), AF_INET);
    sin->sin_addr = *(struct in_addr *) client->h_addr;
    sin->sin_port = htons(atoi(port[4]) * 256 + atoi(port[5]));
    sin->sin_family = AF_INET;
}

int ff(SOCKET sock, t_user *user, char *buff)
{
    FILE *fp;

    if (userlog(sock, user)) {
        if (user->ui == 0) {
            write(sock, "425 Use PORT or PASV first.\r\n", 30);
            return (1);
        }
        if (buff != NULL) {
            if ((fp = fopen(buff, "rb")) == NULL) {
                write(sock, "450 file not found or locked.\r\n", 31);
                return (1);
            }
            make_file(sock, user, fp);
        }
        else
            write(sock, "500 filename is missing.\r\n", 26);
        user->ui = 0;
    }
    return (1);
}