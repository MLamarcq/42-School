/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:01:02 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/20 11:06:39 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned char		*str;
	int					i;

	str = (unsigned char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
