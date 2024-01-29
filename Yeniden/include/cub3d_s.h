#ifndef CUB3D_S_H
# define CUB3D_S_H

typedef struct s_player
{
	int		x;
	int		y;
	char	face;
}	t_player;
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_sprite_address
{
	char	*n_sprite;
	char	*s_sprite;
	char	*e_sprite;
	char	*w_sprite;
}	t_sprite_address;

typedef struct s_map
{
	char				**map;
	char				**copy_map;
	t_player			player;
	t_sprite_address	sprite_address;
	t_rgb				f_rgb;
	t_rgb				c_rgb;
}	t_map;

#endif