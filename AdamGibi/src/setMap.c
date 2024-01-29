#include "../include/cub3d.h"
#include <fcntl.h>
//
#include <stdio.h>

int	check_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
		return (1);
	return (0);
}


void	default_map_settings(t_map *map)
{
	map->map = 	NULL;
	map->copy_map = NULL;
	map->sprite_address.e_sprite = NULL;
	map->sprite_address.w_sprite = NULL;
	map->sprite_address.s_sprite = NULL;
	map->sprite_address.n_sprite = NULL;
}

void setMap(int ac, char **av, t_map *map)
{
	default_map_settings(map);
	int fd;

	if (ac != 2)
		error_massage("Invalid number of argument!\n", map);
	if (!check_cub(av[1]))
		error_massage("Invalid file type!\n", map);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_massage("File read failed!\n", map);
	set_map_values(fd, map);
	if (!check_map(map))
		error_massage("Map is not correct!\n", map);
}