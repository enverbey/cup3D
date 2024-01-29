#include "../libft/include/libft.h"
#include "../include/cub3d.h"
//
#include <stdio.h>

void printDoubleArray(char **av)
{
	for (int i=0; av[i]; i++)
	{
		printf("%s\n", av[i]);
	}
}

char **copyMap(char **map)
{
	char **s;
	int l1 = ft_strlen2(map);
	int l2 = find_max(map);
	s = (char **)malloc(sizeof(char **) * l1+4);
	
	
	s[1] = fill_array(l2, ' ');
	s[1][0] = '#';
	s[1][l2-1] = '#';

	int i=0;
	while (map[i])
	{
		s[i+2] = ft_strdup2(map[i], l2);
		i++;
	}
	s[i+2] = fill_array(l2, ' ');
	s[i+2][0] = '#';
	s[i+2][l2-1] = '#';
	s[i+3] = fill_array(l2, '#');
	s[i+4] = NULL;
	s[0] = fill_array(l2, '#');
	s[1] = fill_array(l2, ' ');
	s[1][0] = '#';
	s[1][l2-1] = '#';	

	return s;
}