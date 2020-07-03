/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** my_malloc
*/
#ifndef FTP_H
#define FTP_H_
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#define SOCKET_ERROR -1

typedef struct s_user
{
    char *str;
    int ta;
    char *dfr;
    short ui;
    char *string;
    char *us;
    char *fr;
    short in;
    uint16_t port;
} t_user;

typedef struct s_funccmd
{
    int	(*ptr)(SOCKET sock, t_user *user, char *path);
    char *str;
} t_funccmd;

void start_ftp(SOCKET sock, char *path);
void to_lower_case(char **);
int sxc(SOCKET sock, t_user *user, char *buff);
int tg(SOCKET sock, t_user *user, char *buff);
int create_data2(SOCKET sock, int port, SOCKET csock);
int open_socket(SOCKET, int, char *);
int xd(SOCKET sock, t_user *user, char *buff);
int rf(SOCKET sock, t_user *user, char *buff);
void print_serv(char *, char *);
void rerulesocket(SOCKET);
int az(SOCKET sock, t_user *user, char *buff);
int cbn(SOCKET sock, t_user *user, char *buff);
int hb(SOCKET sock, t_user *user, char *buff);
void create_ip(SOCKET sock, t_user *user, int port);
void stor_file(SOCKET sock, t_user *user, char *buff);
int lm(SOCKET sock, t_user *user, char *buff);
int fc(SOCKET sock, t_user *user, char *buff);
short loop_func(SOCKET, char *, t_user *user);
int userlog(SOCKET, t_user *user);
char *getpwd(void);
int qs(SOCKET sock, t_user *user, char *buff);
int ujk(SOCKET sock, t_user *user, char *buff);
int prepare_ftp(SOCKET sock, SOCKADDR_IN sin, char **av);
void do_ls(SOCKET, t_user *user, char *);
void make_file(SOCKET, t_user *user, FILE *);
void prepare_client(SOCKET, t_user *user, SOCKADDR_IN *);
int cv(SOCKET sock, t_user *user, char *buff);
int ff(SOCKET sock, t_user *user, char *buff);
int create_data(int, int);
int make_connection(SOCKET sock, char *buffer);
char *returnIP(SOCKET);
int uy(SOCKET sock, t_user *user, char *buff);
int sd(SOCKET sock, t_user *user, char *buff);
int th(SOCKET sock, t_user *user, char *buff);
char **Str_SPLITE(char *, const char);
int check_buffer(char *);

#endif /* !FTP_H_ */
