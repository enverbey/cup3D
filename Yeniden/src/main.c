#include "../include/cub3d.h"
#include "../libft/include/libft.h"

int main(int argc, char **argv)
{
	t_map map;

	if (set_arg(argc, argv, &map))
		ft_putstr("Error Argument!\n");
	else
	{
		print_sprites(&map);
		print_rgb(&map);
		print_map(&map);
		ft_putstr("Argumanlar ayarlandi, Error Yok!\n");
	}
	free_tmap(&map);

	while (1){}

}