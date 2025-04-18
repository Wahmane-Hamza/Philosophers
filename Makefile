NAME = philo

SRC = philosophers.c parcing.c commands_help.c commands_help2.c commands_help3.c commands_help4.c

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
