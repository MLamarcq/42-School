/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:19 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:19 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_size_verif(t_shape *shp)
{
	if (shp->y <= 2)
	{
		write (2, "Error: you need more line to draw a map !\n", 42);
		write (2, "Advice : you have to have 3 line minimum !\n", 43);
		return (0);
	}
	return (1);
}

int	ft_rect_shp(t_shape *shp)
{
	int	i;
	int	j;

	i = 0;
	j = shp->y - 2;
	while (shp->final[i])
	{
		if (j > 0)
		{
			shp->x = ft_strlen(shp->final[i]);
			shp->i = ft_strlen(shp->final[i + 1]);
			if (shp->x != shp->i)
				return (0);
			j--;
		}
		else
			shp->i = ft_strlen(shp->final[i]) + 1;
		i++;
	}
	if (shp->x != shp->i)
		return (2);
	return (1);
}

int	ft_rect_shp_2(t_shape *shp)
{
	int	i;
	int	j;

	i = 0;
	while (shp->final[i])
		i++;
	j = ft_strlen(shp->final[i - 1]);
	if (shp->y == j)
		return (0);
	return (1);
}
