/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:41:45 by envyilma          #+#    #+#             */
/*   Updated: 2024/01/24 01:27:07 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup2(const char *s1, int len)
{
	char		*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	i = 0;
	s2[0] = '#';
	s2[1] = ' ';
	while (s1[i])
	{
		s2[i+2] = s1[i];
		i++;
	}
	while (i < len-1)
	{
		s2[i+2] = ' ';
		i++;
	}
	s2[len-1] = '#';
	s2[len] = '\0';
	return (s2);
}
/*
Verilen parametrenin bir kopyasını döndürür.
*/