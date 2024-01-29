#include "../libft/include/libft.h"
#include "../include/cub3d.h"

char *fill_array(int c, char a)
{
	char *s;
	s = (char *)malloc(sizeof(char) * c);
	for (int i=0; i<c; i++)
		s[i] = a;
	s[c] = '\0';
	return s;
}

int find_max(char **av)
{
	int big = ft_strlen(av[0]);
	for (int i=0; av[i]; i++)
	{
		int tmp = ft_strlen(av[i]);
		if (tmp > big)
			big = tmp;
	}
	return (big + 4);
}

int ft_strlen2(char **av)
{
	int i=0;
	while (av[i])
		i++;
	return i;
}