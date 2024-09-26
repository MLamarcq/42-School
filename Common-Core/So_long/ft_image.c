/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:00:12 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 13:23:22 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_shape *shp)
{
	int	i;
	int	j;

	i = 0;
	while (shp->final[i])
	{
		j = 0;
		while (shp->final[i][j])
		{
			ft_image_put(shp, i, j);
			j++;
		}
		i++;
	}
}

void	ft_image_put(t_shape *shp, int i, int j)
{
	if (shp->final[i][j] == 'P')
		mlx_put_image_to_window(shp->mlx_ptr, shp->win_ptr, shp->P, \
		j * 48, i * 48);
	if (shp->final[i][j] == '0')
		mlx_put_image_to_window(shp->mlx_ptr, shp->win_ptr, shp->O, \
		j * 48, i * 48);
	if (shp->final[i][j] == '1')
		mlx_put_image_to_window(shp->mlx_ptr, shp->win_ptr, shp->L, \
		j * 48, i * 48);
	if (shp->final[i][j] == 'E')
		mlx_put_image_to_window(shp->mlx_ptr, shp->win_ptr, shp->E, \
		j * 48, i * 48);
	if (shp->final[i][j] == 'C')
		mlx_put_image_to_window(shp->mlx_ptr, shp->win_ptr, shp->C, \
		j * 48, i * 48);
}
