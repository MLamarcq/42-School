/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:09 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 12:59:20 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_free_all(t_shape *shp)
{
	mlx_destroy_image(shp->mlx_ptr, shp->O);
	mlx_destroy_image(shp->mlx_ptr, shp->L);
	mlx_destroy_image(shp->mlx_ptr, shp->E);
	mlx_destroy_image(shp->mlx_ptr, shp->P);
	mlx_destroy_image(shp->mlx_ptr, shp->C);
	mlx_destroy_window(shp->mlx_ptr, shp->win_ptr);
	mlx_destroy_display(shp->mlx_ptr);
	free(shp->mlx_ptr);
	ft_free_str(shp->final);
	exit (1);
}
