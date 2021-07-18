#include "ft.h"

int	ft_error(void)
{
	ft_puterr("Error\n");
	return (1);
}

int	ft_dict_error(void)
{
	ft_puterr("Dict Error\n");
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

void	_print_dict(t_keyvalue *dict)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		printf("%s\n", kv->key);
		printf("%d\n", kv->size);
		printf("%s\n", kv->value);
		kv = kv->next;
	}
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
		return (ft_dict_error());
	ft_convert(dict, argv[index]);
	ft_free(dict);
	return (0);
}
