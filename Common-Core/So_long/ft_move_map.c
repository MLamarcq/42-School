/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:08 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 14:25:08 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_map(t_shape *shp, char dir)
{
	int	x;
	int	y;
	int	i;
	int	z;

	y = 0;
	z = 0;
	while (shp->final[y])
	{
		x = 0;
		while (shp->final[y][x])
		{
			if (shp->final[y][x] == 'P' && z == 0)
			{	
				i = ft_map_move(shp, dir, y, x);
				ft_put_image(shp);
				z++;
			}
			x++;
		}
		y++;
	}
	return (i);
}

int	ft_map_move(t_shape *shp, char dir, int y, int x)
{
	int	i;

	if (dir == 'U')
		i = ft_move_up(shp, y, x);
	else if (dir == 'D')
		i = ft_move_down(shp, y, x);
	else if (dir == 'L')
		i = ft_move_left(shp, y, x);
	else if (dir == 'R')
		i = ft_move_right(shp, y, x);
	return (i);
}
