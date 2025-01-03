#include "minitalk.h"

static t_message g_msg = {0, 0, NULL};

static void handle_bit(int signum)
{
    g_msg.current_char = (g_msg.current_char << 1) | (signum == SIGUSR2);
    g_msg.bit_count++;

    if (g_msg.bit_count == 8)
    {
        if (g_msg.current_char == '\0')
        {
            write(1, "\n", 1);
        }
        else
        {
            write(1, &g_msg.current_char, 1);
        }
        g_msg.current_char = 0;
        g_msg.bit_count = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = handle_bit;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
        sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("Error setting up signal handlers");
        return (1);
    }

    printf("Server PID: %d\n", getpid());
    while (1)
        pause();
    return (0);
}
