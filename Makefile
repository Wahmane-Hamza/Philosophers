NAME = philo

SRC = philosophers.c parcing.c commands_help.c commands_help2.c commands_help3.c

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
