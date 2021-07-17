#include "ft.h"

int	ft_error()
{
	ft_puterr("Error\n");
	return (1);
}

int	ft_dict_error()
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
	t_keyvalue	*kv = dict;
	while (kv)
	{
		printf("%s\n", kv->key);
		printf("%s\n", kv->value);
		kv = kv->next;
	}
}

int	main(int argc, char **argv)
{
	t_keyvalue	*dict;

	if (argc != 2)
		return (1);
	if (!ft_open(&dict, argv[1]))
		return (ft_dict_error());
	printf("it works\n");
}