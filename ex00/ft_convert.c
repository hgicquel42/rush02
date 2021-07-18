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

int	ft_convert_exact(t_keyvalue *dict, char c)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->key[0] == c)
		{
			ft_putout(kv->value);
			return (1);
		}
		kv = kv->next;
	}
	return (0);
}

int	ft_convert_tens(t_keyvalue *dict, char *arg)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->size == 2 && ft_is_tens(kv->key, arg[0]))
		{
			ft_putout(kv->value);
			return (1);
		}
		kv = kv->next;
	}
	return (0);
}

int	ft_convert_hundred(t_keyvalue *dict, int size)
{
	t_keyvalue	*kv;

	kv = dict;
	while (kv)
	{
		if (kv->size == size && ft_is_tens(kv->key, '1'))
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
	if (!size)
		return (0);
	if (size == 1)
		return (ft_convert_exact(dict, arg[0]));
	if (size == 2)
	{
		if (arg[0] != '0')
		{
			if (!ft_convert_tens(dict, arg))
				return (0);
			ft_putout(" ");
		}
		if (arg[1] != '0')
		{
			if (!ft_convert_exact(dict, arg[1]))
				return (0);
		}
		return (1);
	}
	if (size >= 3)
	{
		if (arg[0] != '0')
		{
			if (!ft_convert_exact(dict, arg[0]))
				return (0);
			ft_putout(" ");
			if (!ft_convert_hundred(dict, size))
				return (0);
			ft_putout(" ");
		}
		return (ft_convert2(dict, &arg[1], size - 1));
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
