#include "ft.h"

int	ft_is_tens(char	*s, char m)
{
	if (*(s++) != m)
		return (0);
	while (*s && *s == '0')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

int	ft_convert_exact(t_keyvalue *dict, char *arg, int size)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->size == size && !ft_strncmp(kv->key, arg, size - 1))
		{
			ft_putout(kv->value);
			return (1);
		}
		kv = kv->next;
	}
	return (0);
}

int	ft_convert2(t_keyvalue *dict, char *arg, int size)
{
	t_keyvalue	*kv;

	if (!size)
		return (0);
	if (ft_convert_exact(dict, arg, size))
		return (1);
	kv = dict;
	while (kv)
	{
		if (kv->size == size && ft_is_tens(kv->key, arg[0]))
		{
			ft_putout(kv->value);
			ft_putout(" ");
			return (ft_convert2(dict, &(arg[kv->size - 1]), size - (kv->size - 1)));
		}
		kv = kv->next;
	}
	kv = dict;
	while (kv)
	{
		if (kv->size == size && ft_is_tens(kv->key, '1'))
		{
			if (!ft_convert_exact(dict, arg, 1))
				return (0);
			ft_putout(" ");
			ft_putout(kv->value);
			ft_putout(" ");
			return (ft_convert2(dict, &(arg[kv->size - 1]), size - (kv->size - 1)));
		}
		kv = kv->next;
	}
	return (0);
}

int	ft_convert(t_keyvalue *dict, char *arg)
{
	int	size;

	size = 0;
	while (ft_is_number(arg[size]))
		size++;
	if (arg[size] != '\0')
		return (0);
	if (!ft_convert2(dict, arg, size))
		return (0);
	ft_putout("\n");
	return (1);
}
