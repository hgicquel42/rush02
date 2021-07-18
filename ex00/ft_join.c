/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:10:26 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:27 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strjoin(char *a, char *b)
{
	int		i;
	int		j;
	int		s;
	char	*c;

	s = ft_strlen(a) + ft_strlen(b);
	c = malloc((s + 2) * sizeof(char));
	if (!c)
		return (0);
	i = 0;
	j = 0;
	while (a[j])
		c[i++] = a[j++];
	c[i++] = ' ';
	j = 0;
	while (b[j])
		c[i++] = b[j++];
	c[i] = '\0';
	return (c);
}

char	*ft_strdup(char	*str)
{
	int		i;
	int		s;
	char	*res;

	s = ft_strlen(str);
	res = malloc((s + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_join(char *a, char *b)
{
	if (!a && !b)
		return (0);
	if (!a)
		return (ft_strdup(b));
	if (!b)
		return (ft_strdup(a));
	return (ft_strjoin(a, b));
}
