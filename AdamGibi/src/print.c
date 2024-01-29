#include "../include/cub3d.h"
#include "../libft/include/libft.h"
#include <stdio.h>
void	print_map(t_map *map)
{
	for (int i=0; map->map[i]; i++)
		printf("%s\n", map->map[i]);
}

void	print_player(t_map *map)
{
	printf("Player x : %d\n", map->player.x);
	printf("Player y : %d\n", map->player.y);
	printf("Player c : %c\n", map->player.face);
}

void print_sprite_information(t_map *map)
{
	if (map->sprite_address.n_sprite)
	{
		printf("Map n sprite : ->%s<-\n", map->sprite_address.n_sprite);
	}
	if (map->sprite_address.s_sprite)
	{
		printf("Map s sprite : ->%s<-\n", map->sprite_address.s_sprite);
	}
	if (map->sprite_address.e_sprite)
	{
		printf("Map e sprite : ->%s<-\n", map->sprite_address.e_sprite);
	}
	if (map->sprite_address.w_sprite)
	{
		printf("Map w sprite : ->%s<-\n", map->sprite_address.w_sprite);
	}
}

void print_rgb(t_map *map)
{
	printf("F_rgf r-g-b : %d-%d-%d \n", map->f_rgb.r,map->f_rgb.g, map->f_rgb.b);
	printf("C_rgf r-g-b : %d-%d-%d \n", map->c_rgb.r,map->c_rgb.g, map->c_rgb.b);
}


void print_map_information(t_map *map)
{
	print_map(map);
	print_sprite_information(map);
	print_rgb(map);
}