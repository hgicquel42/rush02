/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:10:34 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:35 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_keyvalue	*ft_create_list(void)
{
	t_keyvalue	*kv;

	kv = malloc(sizeof(t_keyvalue));
	if (!kv)
		return (0);
	kv->key = 0;
	kv->value = 0;
	kv->next = 0;
	return (kv);
}

t_keyvalue	*ft_list_end(t_keyvalue	*start)
{
	t_keyvalue	*list;

	list = start;
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_list_append(t_keyvalue	**start, t_keyvalue	*end)
{
	if (!*start)
		*start = end;
	else
		ft_list_end(*start)->next = end;
}
