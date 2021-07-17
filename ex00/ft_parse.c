#include "ft.h"

#define BUF_SIZE 1024

char	*ft_split_first(char *input, int *offset, int size)
{
	int		i;
	int		o;
	char	*output;

	i = *offset;
	o = 0;
	while (i < size && ft_is_number(input[i]))
		i++, o++;
	output = malloc((o + 1) * sizeof(char));
	i = *offset;
	o = 0;
	while (i < size && ft_is_number(input[i]))
		output[o++] = input[i++];
	output[o] = '\0';
	*offset = i;
	return (output);
}

char	*ft_split_last(char *input, int *offset, int size)
{
	int		i;
	int		o;
	char	*output;

	i = *offset;
	o = 0;
	while (i < size && ft_is_printable(input[i]))
		i++, o++;
	output = malloc((o + 1) * sizeof(char));
	i = *offset;
	o = 0;
	while (i < size && ft_is_printable(input[i]))
		output[o++] = input[i++];
	output[o] = '\0';
	*offset = i;
	return (output);
}

t_keyvalue	*ft_split(char	*buffer, int size)
{
	int			i;
	t_keyvalue	*kv;

	kv = ft_create_list();
	if (!kv)
		return (0);
	i = 0;
	kv->key = ft_split_first(buffer, &i, size);
	if (!kv->key)
		return (0);
	while (i < size && buffer[i] == ' ')
		i++;
	if (buffer[i++] != ':')
		return (0);
	while (i < size && buffer[i] == ' ')
		i++;
	kv->value = ft_split_last(buffer, &i, size);
	if (!kv->value)
		return (0);
	if (i != size)
		return (0);
	return (kv);
}

int	ft_parse(t_keyvalue **dict, int file)
{
	t_keyvalue	*curr;
	char		buffer[1024];
	int			offset;

	offset = 0;
	while (read(file, &buffer[offset], 1))
	{
		if (offset == BUF_SIZE)
			return (0);
		if (buffer[offset] != '\n')
		{
			offset++;
			continue ;
		}
		if (offset)
		{
			curr = ft_split(buffer, offset);
			if (!curr)
				return (0);
			ft_list_append(dict, curr);
		}
		offset = 0;
	}
	return (1);
}