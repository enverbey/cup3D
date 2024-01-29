#include "../libft/include/libft.h"
#include "../include/cub3d.h"
//
#include <stdio.h>

/*
#####################################
#.                                  #
#.        111111111111111111111111@ #
#.        1000000000110000000001001 #
#.        1011000001110000000001001 #
#.        1001000000000000000001011 #
#.111111111011000001110000000001000 #
#.100000000011000001110111111011111 #
#.11110111111111011100000010001  ...#
#.11110111111111011101110010001  ...#
#.11000000110111011101110010001  ...#
#.10000000000000001101110010001  ...#
#.10000000000000001101010010001  ...#
#.11000001110101011111011110N0111...#
#.11110111.1110101.101111010001.....#
#.11111111.1111111.111111111111.....#
#...................................#
#####################################
*/

static char
	corner(char **map, int x, int y)
{
	if (map[x - 1][y] == '1' && \
		map[x][y - 1] == '1' && \
		map[x - 1][y - 1] == '0')
		return (1);
	if (map[x + 1][y] == '1' && \
		map[x][y - 1] == '1' && \
		map[x + 1][y - 1] == '0')
		return (1);
	if (map[x - 1][y] == '1' && \
		map[x][y + 1] == '1' && \
		map[x - 1][y + 1] == '0')
		return (1);
	if (map[x + 1][y] == '1' && \
		map[x][y + 1] == '1' && \
		map[x + 1][y + 1] == '0')
		return (1);
	return (0);
}

static char
	checker(char **map, int x, int y)
{
	if (map[x + 1][y] == '0' || map[x - 1][y] == '0' || \
		map[x][y + 1] == '0' || map[x][y - 1] == '0')
		return (1);
	if (corner(map, x, y))
		return (1);
	return (0);
}

void	walkInMap(char **map, int x, int y, t_map *m)
{
	printDoubleArray(map);
	getchar();
	if (checker(map, x, y))
		error_massage("Duvarlar 1 degil!\n", m);
	map[x][y] = '.';
	if (map[x+1][y] == ' ')
		walkInMap(map, x+1, y, m);
	if (map[x-1][y] == ' ')
		walkInMap(map, x-1, y, m);
	if (map[x][y+1] == ' ')
		walkInMap(map, x, y+1, m);
	if (map[x][y-1] == ' ')
		walkInMap(map, x, y-1, m);
}


int check_map(t_map *map)
{
	if (!checkMapCharacters(map->map))
		return (0);
	map->copy_map = copyMap(map->map);
	
	
	printDoubleArray(map->copy_map);
	getchar();
	walkInMap(map->copy_map, 1, 1, map);

	printDoubleArray(map->copy_map);
	getchar();


	return (1);
}