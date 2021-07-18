/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:10:00 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:02 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_convert0(t_keyvalue *dict, char *arg)
{
	char	*a;
	char	*b;
	char	*c;

	a = 0;
	b = 0;
	c = 0;
	if (arg[0] == '1' && arg[1])
		return (ft_convert_two(dict, arg));
	if (arg[0] != '0')
		a = ft_convert_tens(dict, arg);
	if (arg[1] != '0')
		b = ft_convert_digit(dict, arg[1]);
	return (ft_join(a, b));
}

char	*ft_convert1(t_keyvalue *dict, char *arg, int size, int offset)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	char	*e;

	a = 0;
	b = 0;
	c = 0;
	if (arg[0] != '0')
	{
		a = ft_convert_rec(dict, arg, offset);
		b = ft_convert_hundred(dict, size - (offset - 1));
		if (!b)
			return (0);
		c = ft_join(a, b);
	}
	d = ft_convert_rec(dict, &arg[offset], size - offset);
	e = ft_join(c, d);
	if (c)
		free(c);
	return (e);
}

char	*ft_convert_rec(t_keyvalue *dict, char *arg, int size)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	if (!size)
		return (0);
	if (size == 1)
		return (ft_convert_digit(dict, arg[0]));
	if (size == 2)
		return (ft_convert0(dict, arg));
	if (size == 3 || size % 3 == 1)
		return (ft_convert1(dict, arg, size, 1));
	if (size % 3 == 2)
		return (ft_convert1(dict, arg, size, 2));
	if (size % 3 == 0)
		return (ft_convert1(dict, arg, size, 3));
	return (0);
}

int	ft_convert(t_keyvalue *dict, char *arg)
{
	int		size;
	char	*result;

	size = 0;
	while (ft_is_number(arg[size]))
		size++;
	if (arg[size] != '\0')
		return (0);
	result = ft_convert_rec(dict, arg, size);
	if (!result)
		return (0);
	ft_putout(result);
	ft_putout("\n");
	return (1);
}
