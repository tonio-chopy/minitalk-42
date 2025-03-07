SERVER_SRCS	= src/server.c src/utils.c
CLIENT_SRCS	= src/client.c src/utils.c
SERVER_SRCS_BONUS = src/server_bonus.c src/utils.c
CLIENT_SRCS_BONUS = src/client_bonus.c src/utils.c
HEADERS		= include/minitalk.h

CC			= clang -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

all:		libft server client

bonus:		libft server_bonus client_bonus

libft:
			@make -C libft

server:		${SERVER_SRCS:.c=.o} ${HEADERS}
			${CC} ${SERVER_SRCS} ${CC_FLAGS} -o server

client:		${CLIENT_SRCS:.c=.o} ${HEADERS}
			${CC} ${CLIENT_SRCS} ${CC_FLAGS} -o client

server_bonus:		${SERVER_SRCS_BONUS:.c=.o} ${HEADERS}
			${CC} ${SERVER_SRCS_BONUS} ${CC_FLAGS} -o server_bonus

client_bonus:		${CLIENT_SRCS_BONUS:.c=.o} ${HEADERS}
			${CC} ${CLIENT_SRCS_BONUS} ${CC_FLAGS} -o client_bonus
clean:
			rm -rdf ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}
			rm -rdf ${SERVER_SRCS_BONUS:.c=.o} ${CLIENT_SRCS_BONUS:.c=.o}
			@make clean -C libft

fclean:		clean
			rm -rdf client server
			rm -rdf client_bonus server_bonus
			@make fclean -C libft

re:			fclean all

.PHONY:		all bonus libft clean fclean re
