#include "minitalk.h"

g_server g_ser;

void finish_sig(siginfo_t *siginfo) // server가 문자열을 끝까지 다 받고 마지막 '\0'를 받았다는 signal
{
    ft_printf("%s\n", g_ser.message + (ft_strlen(g_ser.message) - g_ser.byte));
    free(g_ser.message);
    kill(siginfo->si_pid, SIGUSR2);
    g_ser.client_pid = 0; // 현재 연결된 클라이언트가 전송한 메세지를 모두 받고 출력한 후 다른 클라이언트와 연결하기 위한 부분
    g_ser.byte = 0;
    g_ser.message = 0; // dangling pointer처리인데 필요한가?
    g_ser.message = (char *)malloc(sizeof(char));
}

int make_byte(char *c, int *bit, siginfo_t *siginfo)
{
    char *temp;

    temp = g_ser.message;
    g_ser.message = ft_strjoin(g_ser.message, c);
    free(temp);
    *bit = 0;
    if (*c == '\0')
    {
        finish_sig(siginfo);
        g_ser.client_pid = 0; // 현재 연결된 클라이언트가 전송한 메세지를 모두 받고 출력한 후 다른 클라이언트와 연결하기 위한 부분
        g_ser.byte = 0;
        return (1);
    }
    g_ser.byte++;
    *c = 0;
    return (0);
}

void get_sig(int signal, siginfo_t *siginfo, void *context)
{
    static int bit;
    static char c;

    (void)context;
    if (g_ser.client_pid == 0) // 기존에 연결되어있는 클라이언트가 없다는 의미
        g_ser.client_pid = siginfo->si_pid;
    if (siginfo->si_pid != g_ser.client_pid) // 처음 연결을 맺은 클라이언트가 아닌 다른 클라이언트에 대한 시그널은 무시
        return;
    if (signal == SIGUSR1)
        c |= 0 << (7 - bit);
    else if (signal == SIGUSR2)
        c |= 1 << (7 - bit);
    bit++;
    if (bit == 8)
    {
        if (make_byte(&c, &bit, siginfo) == 1)
            return;
    }
    kill(siginfo->si_pid, SIGUSR1); // client로부터 signal을 받을 때마다 client한테 signal 전송 (ack)
}

void initializing(struct sigaction *sigac)
{
    sigac->sa_flags = SA_SIGINFO;
    sigemptyset(&(sigac->sa_mask));
    sigac->__sigaction_u.__sa_sigaction = get_sig;
    g_ser.message = (char *)malloc(sizeof(char));
}

int main()
{
    struct sigaction sigac;
    // siginfo_t siginfo;

    ft_printf("Server PID: %d\n", getpid());
    initializing(&sigac);
    sigaction(SIGUSR1, &sigac, NULL);
    sigaction(SIGUSR2, &sigac, NULL);
    while (1)
        pause();
    return (EXIT_SUCCESS);
}