/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:02:15 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/17 10:38:22 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
int	main (void)
{
	printf("%d\n", ft_isalnum(13));
	return (0);
}*/
