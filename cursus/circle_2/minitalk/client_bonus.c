#include "minitalk.h"

g_client g_cli;

void send_sig(int server_pid, char *message)
{
    static int bit;
    static int byte;
    int temp;

    if (g_cli.connection == 0 && bit > 0)
        bit--;
    temp = (message[byte] >> (7 - bit)) & 1;
    if (temp == 0)
        kill(server_pid, SIGUSR1);
    else if (temp == 1)
        kill(server_pid, SIGUSR2);
    bit++;
    if (bit == 8)
    {
        bit = 0;
        byte++;
    }
}

void get_sig(int signal, siginfo_t *siginfo, void *context)
{
    (void)context;
    (void)siginfo;
    if (signal == SIGUSR1) // server에서 signal을 성공적으로 받았을 때
    {
        if (g_cli.connection == 0)
        {
            ft_printf("Client connected to Server\n");
            g_cli.connection = 1; // 최초에 server와 연결
        }
        send_sig(g_cli.server_pid, g_cli.message);
        usleep(50);
    }
    else if (signal == SIGUSR2)
    {
        ft_printf("Signal transfer completed\n");
        exit(EXIT_SUCCESS);
    }
}

void initializing(int argc, char *argv[], struct sigaction *sigac)
{
    if (argc != 3) // 클라이언트 실행 시 2개의 인자인 server pid와 send message가 들어오지 않았을 때의 예외처리 부분
    {
        ft_printf("Wrong! Two parameters needed");
        exit(EXIT_FAILURE);
    }
    g_cli.server_pid = ft_atoi(argv[1]);
    g_cli.message = argv[2];
    sigac->sa_flags = SA_SIGINFO;
    sigemptyset(&(sigac->sa_mask));
    sigac->__sigaction_u.__sa_sigaction = get_sig;
}

void initial_connect()
{
    if (g_cli.connection == 0) // 처음 client 프로세슷 시작시에는 server와 연결이 안 되어 있음
    {
        while (g_cli.connection != 1) // server로부터 signal을 받을 때까지 signal 전송
        {
            send_sig(g_cli.server_pid, g_cli.message);
            usleep(10000);
        }
    }
}

int main(int argc, char *argv[])
{
    struct sigaction sigac;
    // siginfo_t siginfo;

    initializing(argc, argv, &sigac);
    sigaction(SIGUSR1, &sigac, NULL); // server로부터 signal을 받았다는 신호가 오면 다음 signal 전송
    sigaction(SIGUSR2, &sigac, NULL); // server가 문자열을 끝까지 다 받고 마지막에 '\0'를 받았다는 signal
    initial_connect();        // at first
    while (1)
        pause();
    return (EXIT_SUCCESS);
}