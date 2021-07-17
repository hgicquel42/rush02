NAME = rush-02

FILES = \
	ft_main.c \
	ft_parse.c \
	ft_list.c \
	ft_out.c

all: ${NAME}

${NAME}:
	cc -Wall -Wextra -Werror ${FILES} -o ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all