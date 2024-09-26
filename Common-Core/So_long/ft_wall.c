/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:22 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:22 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_first_line(t_shape *shp, char *file, char c)
{
	int	i;

	shp->fd = open(file, O_RDONLY);
	if (shp->fd == -1)
		return (0);
	shp->tmp = get_next_line(shp->fd);
	i = 0;
	while (i < (shp->x - 1))
	{
		if (shp->tmp[i] != c)
		{
			free(shp->tmp);
			return (2);
		}
		i++;
	}
	close(shp->fd);
	free(shp->tmp);
	return (1);
}

int	ft_middle(t_shape *shp, char c)
{
	int	i;
	int	j;

	i = 1;
	j = shp->y - 2;
	while (i <= j)
	{
		if (shp->final[i][0] != c || shp->final[i][shp->x - 2] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_last_line(t_shape *shp, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < (shp->y - 1))
		i++;
	j = 0;
	while (shp->final[i][j])
	{
		if (shp->final[i][j] != c)
			return (0);
		j++;
	}
	return (1);
}

int	ft_wall(t_shape *shp, char *file, char c)
{
	if (ft_first_line(shp, file, c) != 1)
		return (0);
	else if (ft_middle(shp, c) != 1)
		return (2);
	else if (ft_last_line(shp, c) != 1)
		return (3);
	return (1);
}
