#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_s.h"


int 	check_map(t_map *map);
void	error_massage(char *str, t_map *map);
void	set_map_values(int fd, t_map *map);
void	setMap(int ac, char **av, t_map *map);
int		checkMapCharacters(char **av);

char	 **copyMap(char **map);
void 	printDoubleArray(char **av);

//print
void print_map_information(t_map *map);
void print_sprite_information(t_map *map);

//utils
int find_max(char **av);
int ft_strlen2(char **av);
char *fill_array(int c, char a);

#endif