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
	int					size;
	struct s_keyvalue	*next;
}	t_keyvalue;

/* ft_out.c */

void		ft_putout(char *s);

void		ft_puterr(char *s);

/* ft_utils.c */

int			ft_strlen(char *s);

int			ft_strcmp(char *a, char *b);

int			ft_strncmp(char *a, char *b, int n);

int			ft_is_number(char c);

int			ft_is_printable(char c);

int			ft_is_tens(char	*s, int m);

int			ft_parse(t_keyvalue **dict, int file);

int			ft_convert(t_keyvalue *dict, char *arg);

t_keyvalue	*ft_create_list();

void		ft_list_append(t_keyvalue	**start, t_keyvalue	*end);

#endif