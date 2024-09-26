/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:16 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:16 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_items(t_shape *shp)
{
	shp->c = 0;
	shp->p = 0;
	shp->e = 0;
	shp->j = 0;
	shp->move = 0;
}

int	ft_map(t_shape *shp, char c, char p, char e)
{
	int	i;
	int	j;

	ft_init_items(shp);
	i = 0;
	while (shp->final[i])
	{
		j = 0;
		while (shp->final[i][j])
		{
			if (shp->final[i][j] == c)
				shp->c++;
			else if (shp->final[i][j] == p)
				shp->p++;
			else if (shp->final[i][j] == e)
				shp->e++;
			j++;
		}
		i++;
	}
	if (shp->p > 1 || shp->e > 1)
		return (0);
	if (shp->c < 1 || shp->p < 1 || shp->e < 1)
		return (2);
	return (1);
}

int	ft_check_map(t_shape *shp, char c, char p, char e)
{
	int		i;
	int		j;
	char	a;
	char	o;
	char	l;

	i = 0;
	o = '0';
	l = '1';
	while (shp->final[i])
	{
		j = 0;
		while (shp->final[i][j] != '\n' && shp->final[i][j])
		{
			a = shp->final[i][j];
			if (a != c && a != p && a != e && a != o && a != l)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
