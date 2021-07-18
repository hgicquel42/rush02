int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 127);
}

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
