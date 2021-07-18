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

char	*ft_strjoin(char *a, char *b)
{
	int		i;
	int		j;
	char	*c;

	i = ft_strlen(a) + ft_strlen(b);
	c = malloc((i + 2) * sizeof(char));
	if (!c)
		return (0);
	i = 0;
	j = 0;
	while (a[j])
		c[i++] = a[j++];
	c[i++] = ' ';
	j = 0;
	while (b[j])
		c[i++] = b[j++];
	return (c);
}

char	*ft_join(char *a, char *b)
{
	if (!a && !b)
		return (0);
	if (!a)
		return (b);
	if (!b)
		return (a);
	return (ft_strjoin(a, b));
}
