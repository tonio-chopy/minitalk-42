#include "minitalk.h"

static void send_char(int pid, char c)
{
    int bit;
    int i;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        if (bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        i--;
    }
}

static void send_string(int pid, char *str)
{
    while (*str)
    {
        send_char(pid, *str);
        str++;
    }
    send_char(pid, '\0');
}

int main(int argc, char *argv[])
{
    int server_pid;

    if (argc != 3)
    {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return (1);
    }

    server_pid = atoi(argv[1]);
    if (server_pid <= 0)
    {
        printf("Invalid PID\n");
        return (1);
    }

    send_string(server_pid, argv[2]);
    return (0);
}
