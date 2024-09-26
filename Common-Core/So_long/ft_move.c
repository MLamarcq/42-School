/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:26:27 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 14:26:27 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_shape *shp, int y, int x)
{
	if (shp->final[y][x] == 'P' && shp->final[y - 1][x] == '0')
	{
		shp->final[y][x] = '0';
		shp->final[y - 1][x] = 'P';
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y - 1][x] == 'C')
	{
		shp->final[y][x] = '0';
		shp->final[y - 1][x] = 'P';
		shp->c--;
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y - 1][x] == 'E' \
	&& shp->c == 0)
	{
		ft_free_all(shp);
	}
	else if ((shp->final[y][x] == 'P' && shp->final[y - 1][x] == 'E') \
	|| (shp->final[y][x] == 'P' && shp->final[y - 1][x] == '1'))
	{
		return (0);
	}
	return (0);
}

int	ft_move_down(t_shape *shp, int y, int x)
{
	if (shp->final[y][x] == 'P' && shp->final[y + 1][x] == '0')
	{
		shp->final[y][x] = '0';
		shp->final[y + 1][x] = 'P';
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y + 1][x] == 'C')
	{
		shp->final[y][x] = '0';
		shp->final[y + 1][x] = 'P';
		shp->c--;
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y + 1][x] == 'E' \
	&& shp->c == 0)
	{
		ft_free_all(shp);
	}
	else if ((shp->final[y][x] == 'P' && shp->final[y + 1][x] == 'E') \
	|| (shp->final[y][x] == 'P' && shp->final[y + 1][x] == '1'))
	{
		return (0);
	}
	return (0);
}

int	ft_move_left(t_shape *shp, int y, int x)
{
	if (shp->final[y][x] == 'P' && shp->final[y][x - 1] == '0')
	{
		shp->final[y][x] = '0';
		shp->final[y][x - 1] = 'P';
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y][x - 1] == 'C')
	{
		shp->final[y][x] = '0';
		shp->final[y][x - 1] = 'P';
		shp->c--;
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y][x - 1] == 'E' \
	&& shp->c == 0)
	{
		ft_free_all(shp);
	}
	else if ((shp->final[y][x] == 'P' && shp->final[y][x - 1] == 'E') \
	|| (shp->final[y][x] == 'P' && shp->final[y][x - 1] == '1'))
	{
		return (0);
	}
	return (0);
}

int	ft_move_right(t_shape *shp, int y, int x)
{
	if (shp->final[y][x] == 'P' && shp->final[y][x + 1] == '0')
	{
		shp->final[y][x] = '0';
		shp->final[y][x + 1] = 'P';
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y][x + 1] == 'C')
	{
		shp->final[y][x] = '0';
		shp->final[y][x + 1] = 'P';
		shp->c--;
		return (1);
	}
	else if (shp->final[y][x] == 'P' && shp->final[y][x + 1] == 'E' \
	&& shp->c == 0)
	{
		ft_free_all(shp);
	}
	else if ((shp->final[y][x] == 'P' && shp->final[y][x + 1] == 'E') \
	|| (shp->final[y][x] == 'P' && shp->final[y][x + 1] == '1'))
	{
		return (0);
	}
	return (0);
}
