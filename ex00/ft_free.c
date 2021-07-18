/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:10:19 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:20 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free(t_keyvalue *dict)
{
	if (!dict)
		return ;
	free(dict->key);
	free(dict->value);
	ft_free(dict->next);
	free(dict);
}
