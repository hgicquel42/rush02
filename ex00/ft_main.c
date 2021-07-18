/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:10:46 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/18 20:10:48 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_error(t_keyvalue *dict)
{
	ft_puterr("Error\n");
	ft_free(dict);
	return (1);
}

int	ft_dict_error(t_keyvalue *dict)
{
	ft_puterr("Dict Error\n");
	ft_free(dict);
	return (1);
}

int	ft_open(t_keyvalue **dict, char *path)
{
	int	file;

	file = open(path, O_RDONLY);
	if (file == -1)
		return (0);
	return (ft_parse(dict, file));
}

int	main(int argc, char **argv)
{
	int			index;
	char		*path;
	t_keyvalue	*dict;

	index = 1;
	dict = 0;
	if (argc == 3)
		path = argv[index++];
	else if (argc == 2)
		path = "numbers.dict";
	else
		return (ft_error(dict));
	if (!ft_open(&dict, path))
		return (ft_dict_error(dict));
	if (!ft_convert(dict, argv[index]))
		return (ft_error(dict));
	ft_free(dict);
	return (0);
}
