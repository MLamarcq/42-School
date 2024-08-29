/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:43:52 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/20 11:59:55 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char	*src1;
	size_t			i;
	size_t			j;

	src1 = (unsigned char *)src;
	j = ft_strlen((const char *)(src1));
	i = 0;
	if (size != 0)
	{
		while (src1[i] && i < size - 1)
		{
			dst[i] = src1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
