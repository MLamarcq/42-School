/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:51:39 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/20 11:43:16 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*t;
	size_t			i;

	p = (unsigned char *)s1;
	t = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (p[i] != t[i])
		{
			return (p[i] - t[i]);
		}
		i++;
		n--;
	}
	return (0);
}
/*
int	main()
{
	unsigned char str1[] = "hello";
	unsigned char str2[] = "Hello";

	printf("%d\n", ft_memcmp(str1, str2, 5));
	return (0);
}*/
