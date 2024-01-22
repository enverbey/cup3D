/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkFile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:22:50 by bortakuz          #+#    #+#             */
/*   Updated: 2024/01/22 19:24:39 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

static int	check_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
		return (1);
	return (0);
}

static	char	**read_map(int fd)
{
	char	**map;
	char	*temp;
	char	*temp2;

	temp2 = "\0";
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		temp2 = ft_strjoin(temp2, temp);//Temp2 freelemeyi unutma
		free(temp);
	}
	map = ft_split(temp2, '\n');
	free(temp2);
	close(fd);
	return (map);
}

static	char	**read_values(int fd)
{
	int	i;

	i = 0;
	while()
	{
		
	}
}

char	**is_file_valid(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		error_massage("Invalid number of argumant!", NULL);
	if (!check_cub(av[1]))
		error_massage("Invalid file type!", NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		error_massage("File read failed", NULL);
	}
	return (is_valid(fd));
}
