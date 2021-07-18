NAME = rush-02

FILES = \
	ft_main.c \
	ft_parse.c \
	ft_list.c \
	ft_out.c \
	ft_utils.c \
	ft_convert.c \
	ft_convert2.c \
	ft_free.c \
	ft_check.c \
	ft_join.c

all: ${NAME}

${NAME}:
	cc -Wall -Wextra -Werror ${FILES} -o ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all