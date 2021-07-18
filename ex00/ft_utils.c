/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:11:11 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:11:12 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
		a++, b++;
	return (*a - *b);
}

int	ft_strncmp(char *a, char *b, int n)
{
	while (n && *a && *a == *b)
		a++, b++, n--;
	return (*a - *b);
}
