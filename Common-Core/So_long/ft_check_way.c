/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:11:54 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 12:23:25 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_p(t_shape *shp, char e)
{
	int	i;
	int	j;

	i = 0;
	while (shp->final[i])
	{
		j = 0;
		while (shp->final[i][j])
		{
			if (shp->final[i][j] == e)
			{
				if (shp->final[i][j + 1] != 'P')
					shp->j++;
				if (shp->final[i][j - 1] != 'P')
					shp->j++;
				if (shp->final[i + 1][j] != 'P')
					shp->j++;
				if (shp->final[i - 1][j] != 'P')
					shp->j++;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_e(t_shape *shp, char p, char e)
{
	ft_transform_bis(shp, p);
	ft_check_p(shp, e);
	if (shp->j == 4)
		return (0);
	return (1);
}

int	ft_check_item(t_shape *shp)
{
	int	i;
	int	j;

	i = 0;
	while (shp->final[i])
	{
		j = 0;
		while (shp->final[i][j])
		{
			if (shp->final[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	ft_free_str(shp->final);
	return (1);
}
