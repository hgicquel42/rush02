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
	if (argc == 2)
		path = "numbers.dict";
	else
		path = argv[index++];
	if (!ft_open(&dict, path))
		return (ft_dict_error(dict));
	if (!ft_convert(dict, argv[index]))
		return (ft_error(dict));
	ft_free(dict);
	return (0);
}
