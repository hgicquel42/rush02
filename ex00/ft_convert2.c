/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:10:08 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:10 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_convert_exact(t_keyvalue *dict, char *s)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (!ft_strcmp(kv->key, s))
			return (kv->value);
		kv = kv->next;
	}
	return (0);
}

char	*ft_convert_digit(t_keyvalue *dict, char c)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->key[0] == c)
			return (kv->value);
		kv = kv->next;
	}
	return (0);
}

char	*ft_convert_two(t_keyvalue *dict, char *s)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->size == 2 && !ft_strncmp(kv->key, s, 1))
			return (kv->value);
		kv = kv->next;
	}
	return (0);
}

char	*ft_convert_tens(t_keyvalue *dict, char *arg)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->size == 2 && ft_is_tens(kv->key, arg[0]))
			return (kv->value);
		kv = kv->next;
	}
	return (0);
}

char	*ft_convert_hundred(t_keyvalue *dict, int size)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->size == size && ft_is_tens(kv->key, '1'))
			return (kv->value);
		kv = kv->next;
	}
	return (0);
}
