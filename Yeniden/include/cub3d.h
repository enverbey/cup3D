#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_s.h"

//display
void	print_sprites(t_map *map);
void 	print_rgb(t_map *map);
void	print_map(t_map *map);

//error
void	error_massage(char *str, t_map *map);
void	free_tmap(t_map *map);
void 	free_double_array(char **s);

//setArguments
int 	set_arg(int ac, char **av, t_map *m);
int		read_part_one(int fd, t_map *m);
int		read_part_two(int fd, t_map *m);

//utils
void 	set_default_map(t_map *map);
int		check_cub(char *str);
int		find_first_ch(char *str);
int		word_size_in_str(char *s);
int 	is_empty(char *s);
int		is_rgb_format(char *s);
char	*substr_without_space(char *s1);

#endif