#include "../../libft/include/libft.h"
#include "../../include/cub3d.h"
#include <stdio.h>

void print_sprites(t_map *map)
{
	if (!!map->sprite_address.n_sprite)
		printf("n_sprite : ->%s<-\n", map->sprite_address.n_sprite);
	if (!!map->sprite_address.s_sprite)
		printf("s_sprite : ->%s<-\n", map->sprite_address.s_sprite);
	if (!!map->sprite_address.e_sprite)
		printf("e_sprite : ->%s<-\n", map->sprite_address.e_sprite);
	if (!!map->sprite_address.w_sprite)
		printf("w_sprite : ->%s<-\n", map->sprite_address.w_sprite);
}

void print_rgb(t_map *map)
{
	printf("frgb r-g-b : %d-%d-%d\n", map->f_rgb.r, map->f_rgb.g, map->f_rgb.b);
	printf("crgb r-g-b : %d-%d-%d\n", map->c_rgb.r, map->c_rgb.g, map->c_rgb.b);
}

void print_map(t_map *map)
{
	if (!map->map)
		return ;
	for (int i=0; map->map[i]; i++)
	{
		printf("%s\n", map->map[i]);
	}
		
}