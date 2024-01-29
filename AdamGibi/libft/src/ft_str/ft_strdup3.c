/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:41:45 by envyilma          #+#    #+#             */
/*   Updated: 2024/01/24 01:38:27 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdio.h>
char	*ft_strdup3(int a, int len)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	i = 1;
	s2[0] = '#';
	while (i < len-1)
	{
		if (!a)
			s2[i] = '#';
		if (a == 1)
			s2[i] = ' ';
		i++;
	}
	s2[len-1] = '#';
	s2[len] = '\0';
	return (s2);
}
/*
Verilen parametrenin bir kopyasını döndürür.
*/