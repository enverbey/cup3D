#include "../../include/cub3d.h"
#include <fcntl.h>

int set_arg(int ac, char **av, t_map *m)
{
	int fd;

	set_default_map(m);
	if (ac != 2)
		error_massage("Invalid number of argument\n", m);
	if (check_cub(av[1]))
		error_massage("Invalid file type!", m);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_massage("File read failed!\n", m);
	if (read_part_one(fd, m) || read_part_two(fd, m)) // ||
		error_massage("Setting map failed!\n", m);
	return 0;
}