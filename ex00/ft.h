#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_keyvalue
{
	char				*key;
	char				*value;
	struct s_keyvalue	*next;
}	t_keyvalue;

void		ft_putout(char *s);

void		ft_puterr(char *s);

int			ft_is_number(char c);

int			ft_is_printable(char c);

int			ft_parse(t_keyvalue **dict, int file);

t_keyvalue	*ft_create_list();

void		ft_list_append(t_keyvalue	**start, t_keyvalue	*end);

#endif