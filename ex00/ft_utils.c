#include "ft.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
		a++, b++;
	return (*a - *b);
}

int	ft_strncmp(char *a, char *b, int n)
{
	while (n && *a && *a == *b)
		a++, b++, n--;
	return (*a - *b);
}
