/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:04:17 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/26 13:32:30 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src2;

	dst = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = len;
	if (dest > src)
	{
		while (i > 0)
		{
			i--;
			dst[i] = src2[i];
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
/*
int	main()
{
	char	src[] = "Hello good morning";
	char	dest[23];

	ft_memmove(dest, src, 18);
	printf("%s\n", dest);
	return (0);
}*/
