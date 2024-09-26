/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:25 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/09 11:06:57 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change(t_shape *shp, char p, int x, int y)
{
	if ((shp->final[y][x] == p && shp->final[y - 1][x] == '0') ||
	(shp->final[y][x] == p && shp->final[y - 1][x] == 'C'))
		shp->final[y - 1][x] = p;
	if ((shp->final[y][x] == p && shp->final[y + 1][x] == '0') ||
	(shp->final[y][x] == p && shp->final[y + 1][x] == 'C'))
		shp->final[y + 1][x] = p;
	if ((shp->final[y][x] == p && shp->final[y][x + 1] == '0') ||
	(shp->final[y][x] == p && shp->final[y][x + 1] == 'C'))
		shp->final[y][x + 1] = p;
	if ((shp->final[y][x] == p && shp->final[y][x - 1] == '0') ||
	(shp->final[y][x] == p && shp->final[y][x - 1] == 'C'))
		shp->final[y][x - 1] = p;
}

int	ft_verif(t_shape *shp, char p)
{
	int	i;
	int	j;

	i = -1;
	while (shp->final[++i])
	{
		j = 0;
		while (shp->final[i][j])
		{
			if ((shp->final[i][j] == p && shp->final[i][j + 1] == '0') ||
			(shp->final[i][j] == p && shp->final[i][j + 1] == 'C'))
				return (1);
			if ((shp->final[i][j] == p && shp->final[i][j - 1] == '0') ||
			(shp->final[i][j] == p && shp->final[i][j - 1] == 'C'))
				return (1);
			if ((shp->final[i][j] == p && shp->final[i - 1][j] == '0') ||
			(shp->final[i][j] == p && shp->final[i - 1][j] == 'C'))
				return (1);
			if ((shp->final[i][j] == p && shp->final[i + 1][j] == '0') ||
			(shp->final[i][j] == p && shp->final[i + 1][j] == 'C'))
				return (1);
			j++;
		}
	}
	return (0);
}

int	ft_transform_bis(t_shape *shp, char p)
{
	int	i;
	int	j;

	i = 0;
	while (shp->final[i])
	{
		j = 0;
		while (j < shp->x - 2)
		{
			if (shp->final[i][j] == p)
				ft_change(shp, p, j, i);
			j++;
		}
		i++;
	}
	if (ft_verif(shp, p) == 1)
		ft_transform_bis(shp, p);
	return (1);
}
