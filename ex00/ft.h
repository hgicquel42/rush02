/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:11:22 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:11:24 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char		*ft_join(char *a, char *b);

/* ft_check.c */

int			ft_is_number(char c);

int			ft_is_printable(char c);

int			ft_is_tens(char	*s, char m);

/* ft_parse.c */

int			ft_parse(t_keyvalue **dict, int file);

/* ft_convert.c */

int			ft_convert(t_keyvalue *dict, char *arg);

/* ft_free.c */

void		ft_free(t_keyvalue *dict);

/* ft_list.c */

t_keyvalue	*ft_create_list(void);

void		ft_list_append(t_keyvalue	**start, t_keyvalue	*end);

/* ft_convert.c ft_convert2.c */

char		*ft_convert_exact(t_keyvalue *dict, char *s);

char		*ft_convert_digit(t_keyvalue *dict, char c);

char		*ft_convert_two(t_keyvalue *dict, char *s);

char		*ft_convert_tens(t_keyvalue *dict, char *arg);

char		*ft_convert_hundred(t_keyvalue *dict, int size);

char		*ft_convert_rec(t_keyvalue *dict, char *arg, int size);

#endif
