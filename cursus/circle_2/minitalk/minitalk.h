#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_server
{
    int client_pid;
    char *message;
    int byte;
} g_server;

typedef struct s_client
{
    int server_pid;
    char *message;
    int connection;
} g_client;

void finish_sig(siginfo_t *siginfo);
int make_byte(char *c, int *bit, siginfo_t *siginfo);
void get_sig_server(int signal, siginfo_t *siginfo, void *context);
void initializing_server(struct sigaction *sigac);

void send_sig(int server_pid, char *message);
void get_sig_client(int signal, siginfo_t *siginfo, void *context);
void initializing_client(int argc, char *argv[], struct sigaction *sigac);
void initial_connect();
