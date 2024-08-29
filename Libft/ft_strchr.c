/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:17:25 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/26 11:44:59 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ((unsigned char)c))
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char str[] = "Salut tata, je suis tombe";
	printf("%s\n", strchr(str, 't' + 256));
	printf("%s\n", ft_strchr(str, 't' + 256));
	//ft_strchr(str, 'i');
	return (0);
}*/