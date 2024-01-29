#include "../../libft/include/libft.h"
#include "../../include/cub3d.h"
#include <stdlib.h>

void	error_massage(char *str, t_map *map)
{
	free_tmap(map);
	ft_putstr("Error\n");
	ft_putstr(str);
	exit(-1);
}