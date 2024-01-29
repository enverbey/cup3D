#include "../../include/cub3d.h"
#include "../../libft/include/libft.h"
#include <stdlib.h>
#include <stdio.h>


void set_default_map(t_map *map)
{
	map->map = NULL;
	map->copy_map = NULL;
	map->sprite_address.n_sprite = NULL;
	map->sprite_address.s_sprite = NULL;
	map->sprite_address.e_sprite = NULL;
	map->sprite_address.w_sprite = NULL;
}

int	check_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
		return (0);
	return (1);
}

int find_first_ch(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return i;
		i++;
	}
	return -1;
}


int	word_size_in_str(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
		{
			s++;
		}
		else
		{
			while (*s && (*s != ' ' && *s != '\t'))
				s++;
			i++;
		}
	}
	return (i);
}

int is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else
			return 1;
	}
	return 0;
}

int is_rgb_format(char *s)
{
	int count;
	int i;
	count = 0;
	i = find_first_ch(s);
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			i++;
		else if (s[i] == ',')
		{
			count++;
			i++;
			if (count > 2 || !ft_isdigit(s[i]))
			{
				return 1;
			}
				
		}
		else
			break;
	}
	if (count != 2)
		return 1;
	if (s[i] == '\0' || s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		return 0;
	}
	return 1;
}



char	*substr_without_space(char *s1)
{
	char		*s2;
	int			i;
	int			j;

	

	i = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] && (s1[i] == ' ' || s1[i] == '\t'))
		i++;
	while (s1[i] && s1[i] != ' ' && s1[i] != '\t' && s1[i] != '\n')
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}