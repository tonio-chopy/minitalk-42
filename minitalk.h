# ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 8

typedef struct s_message {
    char    current_char;
    int     bit_count;
    char    *message;
} t_message;

#endif
