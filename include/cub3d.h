/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:24:48 by bortakuz          #+#    #+#             */
/*   Updated: 2024/01/22 19:37:42 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
	char	*n_sprire;
	char	*s_sprite;
	char	*e_sprite;
	char	*w_sprite;
}	t_sprite_address;

typedef struct s_map
{
	char				**map;
	t_player			player;
	t_sprite_address	sprite_address;
	t_rgb				*f_rgb;
	t_rgb				*c_rgb;
}	t_map;

void	isFileValid(int ac, char**av);
#endif