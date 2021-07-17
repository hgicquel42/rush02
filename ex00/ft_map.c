

int	ft_show(char *arg, int size)
{
	if (size == 1)

	return (1);
}

int	ft_map(char *arg)
{
	int	size;

	size = 0;
	while (ft_is_number(arg[size]))
		size++;
	if (arg[size] != '\0')
		return (0);
	return (ft_show(arg, size));
}