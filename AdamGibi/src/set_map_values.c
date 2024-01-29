#include "../include/cub3d.h"
#include "../libft/include/libft.h"
//
#include <stdio.h>
static int is_n_location(char *c)
{
	return (*c == 'N' && *(c+1) == 'O');
}
static int is_w_location(char *c)
{
	return (*c == 'W' && *(c+1) == 'E');
}
static int is_s_location(char *c)
{
	return (*c == 'S' && *(c+1) == 'O');
}
static int is_e_location(char *c)
{
	return (*c == 'E' && *(c+1) == 'A');
}

static int is_player_location(char *tmp, t_map *map)
{
	if (tmp[0] && tmp[1])
	{
		if (is_n_location(tmp))
			map->sprite_address.n_sprite = ft_substr2(&tmp[2], 0, ft_strlen(tmp) - 2);
		else if (is_w_location(tmp))
			map->sprite_address.w_sprite = ft_substr2(&tmp[2], 0, ft_strlen(tmp) - 2);
		else if (is_s_location(tmp))
			map->sprite_address.s_sprite = ft_substr2(&tmp[2], 0, ft_strlen(tmp) - 2);
		else if (is_e_location(tmp))
			map->sprite_address.e_sprite = ft_substr2(&tmp[2], 0, ft_strlen(tmp) - 2);
		else
			return (0);
		return (1);
	}
	
	
	return (0);
}

int is_rgb_location(char *tmp, t_map *map)
{
	if (*tmp == 'F')
	{
		char **str = ft_split(&tmp[1], ',');
		map->f_rgb.r = ft_atoi(str[0]);
		map->f_rgb.g = ft_atoi(str[1]);
		map->f_rgb.b = ft_atoi(str[2]);
		return (1);
	}
	else if (*tmp == 'C')
	{
		char **str = ft_split(&tmp[1], ',');
		map->c_rgb.r = ft_atoi(str[0]);
		map->c_rgb.g = ft_atoi(str[1]);
		map->c_rgb.b = ft_atoi(str[2]);
		return (1);
	}
	return (0);
}

void	set_map(int fd, t_map *map)
{
	char *tmp;
	char *m;
	
	m = get_next_line(fd);
	tmp = get_next_line(fd);
	
	while (tmp)
	{
		m = ft_strjoin_free(m, tmp);
		tmp = get_next_line(fd);
	}
	map->map = ft_split(m, '\n');
	
}

void	set_map_values(int fd, t_map *map)
{
	int		i;
	int		j;
	char		*tmp;

	i = 0;
	while (i < 6)
	{
		tmp = get_next_line(fd);
		j = 0;
		if (!tmp)
			return ;
		while (tmp && tmp[j])
		{
			if (is_player_location(&tmp[j], map))
			{
				j+=2;
				i++;
			}
			if (is_rgb_location(&tmp[j], map))
			{
				i++;
			}
			j++;
		}
	}
	set_map(fd, map);
}