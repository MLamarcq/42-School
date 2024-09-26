/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:53:45 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/20 11:43:29 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*p;
	size_t			i;

	c = (unsigned char *)src;
	p = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p[i] = c[i];
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char	src[] = "Salut ca va ?";
	char	dest[5];
	
	ft_memcpy(dest, src, 5);
	printf("own: %s\nown length: %i\n\n", dest, ft_strlen(dest));
	




	char source[] = "Salut ca va ?";
	char destination[5];

	memcpy(destination, source, 5);
	printf("real: %s\nreal length: %i\n\n", destination, ft_strlen(destination));
	
	
	
	
	return (0);
}*/
