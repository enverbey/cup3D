#include "../../include/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void free_tmap(t_map *map)
{
	for (int i=0; (map->map && map->map[i]); i++)
		free(map->map[i]);
	if (!!map->map)
		free(map->map);
	for (int i=0; (map->copy_map && map->copy_map[i]); i++)
		free(map->copy_map[i]);
	if (!!map->copy_map)
		free (map->copy_map);
	if (!!map->sprite_address.n_sprite)
		free(map->sprite_address.n_sprite);	
	if (!!map->sprite_address.s_sprite)
		free(map->sprite_address.s_sprite);
	if (!!map->sprite_address.e_sprite)
		free(map->sprite_address.e_sprite);
	if (!!map->sprite_address.w_sprite)
		free(map->sprite_address.w_sprite);
}

void free_double_array(char **str)
{
	for (int i=0; str[i]; i++)
		free(str[i]);
	if (!!str)
		free(str);
}