#include "../../libft/include/libft.h"
#include "../../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

int read_part_two(int fd, t_map *map)
{
	char *tmp;
	char *m;
	
	m = get_next_line(fd);
	tmp = get_next_line(fd);
	while (tmp)
	{
		m = ft_strjoin_free(m, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map->map = ft_split(m, '\n');
	free(m);
	return 0;
}