#include "../../libft/include/libft.h"
#include "../../include/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void put_sprite(char **str, char *tmp, int i, t_map *m)
{
	if (*str != NULL)
		error_massage("don't repeat in file content!!\n", m);
	if (tmp[2] != ' ' && tmp[2] != '\t')
		error_massage("wrong sprites!!\n", m);
	*str = substr_without_space(&tmp[i + 2]);
}

static int is_player_location(char *tmp, t_map *map)
{
	if (!is_empty(tmp))
		return 0;
	int i;

	i = find_first_ch(tmp);
	if (i == -1 || word_size_in_str(tmp) != 2)
	{
		error_massage("*.cub file content WRONG!!\n", map);
	}
	if (tmp[i] == 'N' && tmp[i + 1] == 'O')
		put_sprite(&map->sprite_address.n_sprite, tmp, i, map);
	else if (tmp[i] == 'W' && tmp[i + 1] == 'E')
		put_sprite(&map->sprite_address.w_sprite, tmp, i, map);
	else if (tmp[i] == 'S' && tmp[i + 1] == 'O')
		put_sprite(&map->sprite_address.s_sprite, tmp, i, map);
	else if (tmp[i] == 'E' && tmp[i + 1] == 'A')
		put_sprite(&map->sprite_address.e_sprite, tmp, i, map);
	else
		return 0;
	return 1;
}

static int	is_rgb_location(char *tmp, t_map *map)
{
	if (!is_empty(tmp))
		return 0;
	int i;

	i = find_first_ch(tmp);
	if (i == -1 || word_size_in_str(tmp) != 2)
	{
		error_massage("*.cub file content WRONG!!\n", map);
	}
	if (is_rgb_format(&tmp[i+1]))
		error_massage("rgb format is not correct!\n", map);
	if (tmp[i] == 'F')
	{
		char **str = ft_split(&tmp[i+1], ',');
		map->f_rgb.r = ft_atoi(str[0]);
		map->f_rgb.g = ft_atoi(str[1]);
		map->f_rgb.b = ft_atoi(str[2]);
		free_double_array(str);
		return 1;
	}
	else if (tmp[i] == 'C')
	{
		char **str = ft_split(&tmp[i+1], ',');
		map->c_rgb.r = ft_atoi(str[0]);
		map->c_rgb.g = ft_atoi(str[1]);
		map->c_rgb.b = ft_atoi(str[2]);
		free_double_array(str);
		return (1);
	}
	return (0);
}

int		read_part_one(int fd, t_map *m)
{
	int 	i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < 6)
	{
		j = 0;
		
		tmp = get_next_line(fd);
		if (!tmp)
			return 1;
		while (tmp && tmp[j])
		{
			//printf("i : %d", i);
			//getchar();
			if (is_player_location(&tmp[j], m))
			{
				i++;
				break;
			}
			else if (is_rgb_location(&tmp[j], m))
			{
				i++;
				break;
			}
			else if (is_empty(tmp))
			{
				error_massage("satir dogru degil!!\n", m);
			}
			else
				break;
			
		}
		free (tmp);
	}
	return 0;
}